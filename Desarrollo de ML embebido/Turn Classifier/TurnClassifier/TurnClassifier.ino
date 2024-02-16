/* Edge Impulse ingestion SDK
 * Copyright (c) 2022 EdgeImpulse Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

 // Created by Diego Remon
 // https://github.com/DiegoRemonn/Redes-de-Sensores

/* Includes ---------------------------------------------------------------- */
#include <DiegoRemon_AccelerometerArduino_inferencing.h>
#include <Arduino_LSM9DS1.h> //Click here to get the library: https://www.arduino.cc/reference/en/libraries/arduino_lsm9ds1/

/* Constant defines -------------------------------------------------------- */ // NOT USED
#define CONVERT_G_TO_MS2    9.80665f
#define MAX_ACCEPTED_RANGE  2.0f        // starting 03/2022, models are generated setting range to +-2, but this example use Arudino library which set range to +-4g. If you are using an older model, ignore this value and use 4.0f instead

/*
 ** NOTE: If you run into TFLite arena allocation issue.
 **
 ** This may be due to may dynamic memory fragmentation.
 ** Try defining "-DEI_CLASSIFIER_ALLOCATION_STATIC" in boards.local.txt (create
 ** if it doesn't exist) and copy this file to
 ** `<ARDUINO_CORE_INSTALL_PATH>/arduino/hardware/<mbed_core>/<core_version>/`.
 **
 ** See
 ** (https://support.arduino.cc/hc/en-us/articles/360012076960-Where-are-the-installed-cores-located-)
 ** to find where Arduino installs cores on your machine.
 **
 ** If the problem persists then there's not enough memory for this model and application.
 */

/* Private variables ------------------------------------------------------- */
static bool debug_nn = false; // Set this to true to see e.g. features generated from the raw signal
static uint32_t run_inference_every_ms = 200; // Period of inference cycle
static rtos::Thread inference_thread(osPriorityLow);
static float buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE] = { 0 };   // Array con tamaño definido por el número especifico de datos manejables al mismo tiempo
static float inference_buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE];

/* Forward declaration */
void run_inference_background();

/**
* @brief      Arduino setup function
*/
void setup()
{
    // put your setup code here, to run once:
    // Inicializacion del puerto serie
    Serial.begin(115200);
    // comment out the below line to cancel the wait for USB connection (needed for native USB)
    while (!Serial);
    Serial.println("Edge Impulse Inferencing Arduino Nano 33 BLE");

    // Inicializacion del sensor inercial 
    if (!IMU.begin()) {
        ei_printf("Failed to initialize IMU!\r\n");
    }
    else {
        ei_printf("IMU initialized\r\n");
    }
    // Comprobacion que el numero maximo de muestras por frame sea = 3 (gyrX, gyrY, gyrZ)
    if (EI_CLASSIFIER_RAW_SAMPLES_PER_FRAME != 3) {
        ei_printf("ERR: EI_CLASSIFIER_RAW_SAMPLES_PER_FRAME should be equal to 3 (the 3 sensor axes)\n");
        return;
    }

    // Inicializacion de la interrupcion de inferencia del modelo
    inference_thread.start(mbed::callback(&run_inference_background));

}

/**
 * @brief Return the sign of the number
 * 
 * @param number 
 * @return int 1 if positive (or 0) -1 if negative
 */
float ei_get_sign(float number) {
    return (number >= 0.0) ? 1.0 : -1.0;
}

/**
 * @brief      Run inferencing in the background. Funcion que realiza la inferencia en segundo plano
 */
void run_inference_background()
{
    // wait until we have a full buffer
    delay((EI_CLASSIFIER_INTERVAL_MS * EI_CLASSIFIER_RAW_SAMPLE_COUNT) + 100);

    // This is a structure that smoothens the output result
    // With the default settings 70% of readings should be the same before classifying.
    ei_classifier_smooth_t smooth;
    ei_classifier_smooth_init(&smooth, 10 /* no. of readings */, 7 /* min. readings the same */, 0.8 /* min. confidence */, 0.3 /* max anomaly */);

    while (1) {
        // copy the buffer
        memcpy(inference_buffer, buffer, EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE * sizeof(float));

        // Turn the raw buffer in a signal which we can the classify (Convierte el buffer de datos en una señal clasificable)
        signal_t signal;
        int err = numpy::signal_from_buffer(inference_buffer, EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, &signal);
        // Comprobacion de error al crear la señal del buffer
        if (err != 0) {
            ei_printf("Failed to create signal from buffer (%d)\n", err);
            return;
        }

        // Run the classifier
        ei_impulse_result_t result = { 0 };

        err = run_classifier(&signal, &result, debug_nn);
        // Comprobacion de ejecucion correcta
        if (err != EI_IMPULSE_OK) {
            ei_printf("ERR: Failed to run classifier (%d)\n", err);
            return;
        }

        // print the predictions - Muestra por pantalla las predicciones
        ei_printf("Predictions ");
        ei_printf("(DSP: %d ms., Classification: %d ms., Anomaly: %d ms.)",
            result.timing.dsp, result.timing.classification, result.timing.anomaly);
        ei_printf(": ");

        // ei_classifier_smooth_update yields the predicted label
        const char *prediction = ei_classifier_smooth_update(&smooth, &result);
        ei_printf("%s ", prediction);
        // print the cumulative results - Muestra por pantalla las distintas confianzas para cada clase
        ei_printf(" [ ");
        for (size_t ix = 0; ix < smooth.count_size; ix++) {
            ei_printf("%u", smooth.count[ix]);
            if (ix != smooth.count_size + 1) {
                ei_printf(", ");
            }
            else {
              ei_printf(" ");
            }
        }
        ei_printf("]\n");

        // LED RGB para cada clase - tienen anodo comun - logica inversa
        if (result.classification[0].value > 0.8) { // idle - Apagado
            analogWrite(LED_RED, 255); 
            analogWrite(LED_BLUE, 255);
            analogWrite(LED_GREEN, 255);

        }else if (result.classification[1].value > 0.8) { // pitchnegativo - Amarillo
            analogWrite(LED_RED, 0);
            analogWrite(LED_BLUE, 255);
            analogWrite(LED_GREEN, 0);
        
        }else if (result.classification[2].value > 0.8) { // pitchpositivo - Verde
            analogWrite(LED_RED, 255);
            analogWrite(LED_BLUE, 255);
            analogWrite(LED_GREEN, 0);
        
        }else if (result.classification[3].value > 0.8) { // rollnegativo - Rosa
            analogWrite(LED_RED, 0);
            analogWrite(LED_BLUE, 0);
            analogWrite(LED_GREEN, 255);
        
        }else if (result.classification[4].value > 0.8) { // rollpositivo - Rojo
            analogWrite(LED_RED, 0);
            analogWrite(LED_BLUE, 255);
            analogWrite(LED_GREEN, 255);
        
        }else if (result.classification[5].value > 0.8) { // yawnegativo - Morado
            analogWrite(LED_RED, 200);
            analogWrite(LED_BLUE, 0);
            analogWrite(LED_GREEN, 255);
        
        }else if (result.classification[6].value > 0.8) { // yawpositivo - Azul
            analogWrite(LED_RED, 255);
            analogWrite(LED_BLUE, 0);
            analogWrite(LED_GREEN, 255);
        
        }else{
            analogWrite(LED_RED, 0);  // Blanco
            analogWrite(LED_BLUE, 0);
            analogWrite(LED_GREEN, 0);
        }
        // Espera hasta terminar el periodo de inferencia
        delay(run_inference_every_ms);
    }

    ei_classifier_smooth_free(&smooth); // Liberacion de la memoria usada para suavizado
}

/**
* @brief      Get data and run inferencing
*
* @param[in]  debug  Get debug info if true
*/
void loop()
{
    while (1) {
        // Determine the next tick (and then sleep later)
        uint64_t next_tick = micros() + (EI_CLASSIFIER_INTERVAL_MS * 1000);

        // roll the buffer -3 points so we can overwrite the last one (Libera las ultimas 3 posiciones del buffer para guardar nuevos valores)
        numpy::roll(buffer, EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, -3);

        // read to the end of the buffer
        IMU.readGyroscope(
            buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE - 3],
            buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE - 2],
            buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE - 1]
        );

        for (int i = 0; i < 3; i++) {
            if (fabs(buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE - 3 + i]) > MAX_ACCEPTED_RANGE) {
                buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE - 3 + i] = buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE - 3 + i];
            }
        }

        // Conversion de tamaño de g's a ms2 en caso de unicamente usar el acelerometro
        //buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE - 3] *= CONVERT_G_TO_MS2;
        //buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE - 2] *= CONVERT_G_TO_MS2;
        //buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE - 1] *= CONVERT_G_TO_MS2;

        // and wait for next tick - Espera al siguiente ciclo
        uint64_t time_to_wait = next_tick - micros();
        delay((int)floor((float)time_to_wait / 1000.0f));
        delayMicroseconds(time_to_wait % 1000);
    }
}

// Comprobacion de que el sensor utilizado es el adecuado para la ejecucion
#if !defined(EI_CLASSIFIER_SENSOR) || EI_CLASSIFIER_SENSOR != EI_CLASSIFIER_SENSOR_ACCELEROMETER
#error "Invalid model for current sensor"
#endif
