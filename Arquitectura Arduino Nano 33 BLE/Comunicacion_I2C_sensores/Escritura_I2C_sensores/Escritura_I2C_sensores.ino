// Escritura I2C sensores de aceleracion, giroscopo y magnetometro
// Created by Diego Remon
// https://github.com/DiegoRemonn/Arquitectura-Arduino-Nano-33-BLE

#include <Arduino.h>
#include "BBTimer.hpp"
#include <Arduino_LSM9DS1.h>
#include <Wire.h>

// Designacion de un timer de la clase BBTimer para su uso
BBTimer my_t3(BB_TIMER3);

// Inicializacion de Variables y pines del dispositivo
float x_axis, y_axis, z_axis;
float x_gyro, y_gyro, z_gyro;
float x_magn, y_magn, z_magn;
int ledvalue;
int degreesX = 0;
int degreesY = 0;
int plusThreshold = 30;
int minusThreshold = -30;
int cont = 0;
float medidas[5][3][3]; // Matriz con los 5 valores medidos en cada sensor de x, de y, de z
bool send = false;
char buffer[15];
char envio[8];
String valor = "";

// Funcion de devolucion de llamada del timer
void t3Callback()
{
  send = true; // Semaforo/Flag lectura ADC
  cont = (cont+1)%5; // Incremento del 0 a 5
}

void setup() {
  // put your setup code here, to run once:
  // Inicializacion del puerto serie
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Started"); // Mensaje de inicio del puerto serie

  // Inicializacion de la comunicacion I2C
  Wire.begin();

  // Inicializacion del sensor IMU (Inertial Measurement Unit)
  // Comprobacion de un arranque correcto
  if(!IMU.begin()){
    Serial.println("Error al inicializar el IMU!");
    while(1);
  }

  // Muestra por puerto serie el ratio de muestras del acelerometro en Hz y otros mensajes utiles
  Serial.print("Ratio de muestras del acelerometro = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Aceleracion en g's");
  Serial.println("X\tY\tZ");

  // Muestra por puerto serie el ratio de muestras del giroscopo en Hz y otros mensajes utiles
  Serial.print("Ratio de muestras del giroscopo = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope en grados/segundo");
  Serial.println("X\tY\tZ");

  // Muestra por puerto serie el ratio de muestras del magnetometro en Hz y otros mensajes utiles
  Serial.print("Ratio de muestras del campo magnetico = ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Magnetic Field in uT");
  Serial.println("X\tY\tZ");

  // Inicializacion y arranque del timer con una periodicidad de 0.2 segundos
  my_t3.setupTimer(200000, t3Callback);
  my_t3.timerStart();
}

void loop() {
  // put your main code here, to run repeatedly:
  // Si hay valor disponible en el puerto serie se procede a leerlo
  if (Serial.available() > 0){
    // Lectura de una palabra en el puerto serie
    valor = Serial.readStringUntil('\n'); // Lectura hasta que finaliza la linea
    cont = 0; // Reinicio el contador
  }
  // Inicio de la transmision del dato por I2C en la direccion 8
  Wire.beginTransmission(8);
  // Comprobacion que el contador sea mayor o igual a 0 y menor que 5 y que haya llamada al timer
  // Se debe medir cada 200 ms y mostrar una vez pasado 1 segundo (5 veces 200 ms)
  // Compruebo que el comando enviado es "send"
  if (cont>=0 and cont<5 and send == true and valor == "send"){
    // Comprobacion que el acelerometro, giroscopo y magnetometro estan disponibles
    if(IMU.accelerationAvailable() and IMU.gyroscopeAvailable() and IMU.magneticFieldAvailable()){
      // Lectura del acelerometro en x, y, z
      IMU.readAcceleration(x_axis, y_axis, z_axis);
      // Lectura del giroscopo en x, y, z
      IMU.readGyroscope(x_gyro, y_gyro, z_gyro);
      // Lectura del magnetometro en x, y, z
      IMU.readMagneticField(x_magn, y_magn, z_magn);
    }
    // Almacenamiento de las lecturas en una matriz, primer valor x, segundo y, tercero z
    // Cinco filas cont y 3 columnas para x, y, z del acelerometro
    medidas[cont][0][0] = x_axis; // Cinco valores de x del acelerometro
    medidas[cont][0][1] = y_axis; // Cinco valores de y del acelerometro
    medidas[cont][0][2] = z_axis; // Cinco valores de z del acelerometro

    // Cinco filas cont y 3 columnas para x, y, z del giroscopo
    medidas[cont][1][0] = x_gyro; // Cinco valores de x del giroscopo
    medidas[cont][1][1] = y_gyro; // Cinco valores de y del giroscopo
    medidas[cont][1][2] = z_gyro; // Cinco valores de z del giroscopo

    // Cinco filas cont y 3 columnas para x, y, z del magnetometro
    medidas[cont][2][0] = x_magn; // Cinco valores de x del magnetometro
    medidas[cont][2][1] = y_magn; // Cinco valores de y del magnetometro
    medidas[cont][2][2] = z_magn; // Cinco valores de z del magnetometro
    
    // Comprobacion que ya se ha terminado el segundo (5 veces recorrido el timer)
    if(cont == 4){
      // Recorrido de la matriz, se anida sobre las muestras, cada sensor y los ejes a leer
      for(int muestra = 0; muestra < 5; muestra++){
        for(int sensor = 0; sensor < 3; sensor++){
          for(int axis = 0; axis < 3; axis++){
            // Guarda en un float el valor leido en cada posicion de la matriz medidas
            float resultados = medidas[muestra][sensor][axis];
            // Conversion a un string el valor medido en la variable "resultados" en formato con 4 decimales
            sprintf(envio, "%.4f", resultados);
            // Ejemplo de conversion de la variable float a string con "dtostrf"
            dtostrf(resultados, 10, 2, buffer);
            // Escritura de la medida por I2C y del caracter ',' para separar valores
            Wire.write(envio);
            Wire.write(',');
          }
        }
      }
      valor = "";
      // Finalizacion de la transmision
      Wire.endTransmission();
    }
    // Indicacion final de fin de uso del timer
    send = false;
  }
}

// Funcion que permite convertir un valor float en un string
// Parametros: valor a leer, longitud del string, numero de decimales y puntero string de salida
char *dtostrf(double val, signed char width, unsigned char prec, char *sout){
  // Inicializacion de un buffer de caracteres de tamaño 20 para guardar la cadena
  char fmt[20];
  // Creacion del formato de la cadena con width y prec con formato w.pf
  // w (width) el ancho de la cadena y con p (prec) el numero de decimales
  sprintf(fmt, "%%%d.%df", width, prec);
  // Creacion de la cadena final con el formato anterior "fmt" en la variable "sout" a partir del valor de "val"
  sprintf(sout, fmt, val);
}
