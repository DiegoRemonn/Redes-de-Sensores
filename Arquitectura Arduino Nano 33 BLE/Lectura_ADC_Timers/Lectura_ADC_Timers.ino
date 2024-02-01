// Lectura del ADC con los timers
// Created by Diego Remon
// https://github.com/DiegoRemonn/Arquitectura-Arduino-Nano-33-BLE

#include <Arduino.h>
#include "BBTimer.hpp"

// Designacion de un timer de la clase BBTimer para su uso
BBTimer my_t3(BB_TIMER3);

// Inicializacion de Variables y pines del dispositivo
int sensorPin = A0;
int sensorValue = 0;
float sensorVoltage = 0;
bool send = false;

// Funcion de devolucion de llamada del timer
void t3Callback()
{
  send = true; // Semaforo/Flag lectura ADC
}

void setup() {
  // put your setup code here, to run once:
  // Inicializacion del puerto serie
  Serial.begin(9600);

  // Inicializacion y arranque del timer con una periodicidad de 10 segundos
  my_t3.setupTimer(10000000, t3Callback);
  my_t3.timerStart();
}

void loop() {
  // put your main code here, to run repeatedly:
  // Lectura del ADC si se ha iniciado / devuelto la llamada del timer
  if (send == true){
    // Lectura del ADC y conversion a valor de tension (10 bit - 3.3 V)
    sensorValue = analogRead(sensorPin);
    sensorVoltage = sensorValue*3.3/1023;
    // Muestra por pantalla el valor de la tension
    Serial.print("The value is: ");
    Serial.println(sensorVoltage);
    // Indicacion final de fin de uso del timer
    send = false;
  }
}
