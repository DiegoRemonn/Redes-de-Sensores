// Envio de datos por puerto serie para lectura en Termite o Python
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <Arduino.h>
#include "BBTimer.hpp"
#include <Arduino_LSM9DS1.h>
#include <Wire.h>

// Designacion de un timer de la clase BBTimer para su uso
BBTimer my_t3(BB_TIMER3);

// Inicializacion de Variables y pines del dispositivo
float x_acc, y_acc, z_acc;
int degreesX = 0;
int degreesY = 0;
int cont = 0;
float medidas[3]; // Matriz con los valores de x, de y, de z
bool send = false;
char envio[8];

// Funcion de devolucion de llamada del timer
void t3Callback()
{
  send = true; // Semaforo/Flag lectura ADC
}

void setup() {
  // put your setup code here, to run once:
  // Inicializacion del puerto serie
  Serial.begin(9600);
  while(!Serial);
  //Serial.println("Started"); // Mensaje de inicio del puerto serie

  // Inicializacion de la comunicacion I2C
  Wire.begin();

  // Inicializacion del sensor IMU (Inertial Measurement Unit)
  // Comprobacion de un arranque correcto
  if(!IMU.begin()){
    Serial.println("Error al inicializar el IMU!");
    while(1);
  }

  // Inicializacion y arranque del timer con una periodicidad de 50 milisegundos
  my_t3.setupTimer(50000, t3Callback);
  my_t3.timerStart();
}

void loop() {
  // put your main code here, to run repeatedly:
  // Inicio de la transmision del dato por I2C en la direccion 8
  //Wire.beginTransmission(8);
  // Comprobacion de llamada al timer, se debe medir cada 50 ms
  if (send == true){
    // Comprobacion que el acelerometro esta disponible
    if(IMU.accelerationAvailable()){
      // Lectura del acelerometro en x, y, z
      IMU.readAcceleration(x_acc, y_acc, z_acc);
    }
    // Almacenamiento de las lecturas en una matriz, primer valor x, segundo y, tercero z
    medidas[0] = x_acc; // Valores de x del acelerometro
    medidas[1] = y_acc; // Valores de y del acelerometro
    medidas[2] = z_acc; // Valores de z del acelerometro

    //Serial.print("x, y, z: ");
    // Recorrido de la matriz
    for(int axis = 0; axis < 3; axis++){
      // Guarda en un float el valor leido en cada posicion de la matriz medidas
      float resultados = medidas[axis];
      // Conversion a un string el valor medido en la variable "resultados" en formato con 4 decimales
      sprintf(envio, "%.4f", resultados);
      // Escritura de la medida por I2C y del caracter ',' para separar valores
      //Wire.write(envio);
      //Wire.write(',');
      // Muestro por puerto serie los resultados separados por comas
      Serial.print(resultados);
      if(axis < 2){
        Serial.print(", ");
      }
    }
    Serial.println();
    // Finalizacion de la transmision
    //Wire.endTransmission();
    // Indicacion final de fin de uso del timer
    send = false;
  }
}
