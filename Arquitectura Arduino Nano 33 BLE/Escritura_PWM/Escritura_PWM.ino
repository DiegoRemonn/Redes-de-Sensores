// Lectura del ADC con los timers
// Created by Diego Remon
// https://github.com/DiegoRemonn/Arquitectura-Arduino-Nano-33-BLE

#include <Arduino.h>
#include "BBTimer.hpp"
#include "mbed.h"

// Designacion de un timer de la clase BBTimer para su uso
BBTimer my_t3(BB_TIMER3); 

// Inicializacion de Variables y pines del dispositivo
int sensorPin = A0;
int PinPWM = D2;
int pwmFrequency = 5000;
int sensorValue = 0;
float sensorVoltage = 0;
bool send = false;
float dutyCycle = 0;

// Asignacion de pin como salida PWM
mbed::PwmOut pwmPin(digitalPinToPinName(PinPWM));

// Funcion de devolucion de llamada del timer
void t3Callback()
{
  send = true; // Semaforo/Flag lectura ADC
}

void setup() {
  // put your setup code here, to run once:
  // Inicializacion del puerto serie
  Serial.begin(9600);

  // Inicializacion y arranque del timer con una periodicidad ajustable (0.1 segundos)
  my_t3.setupTimer(100000, t3Callback);
  my_t3.timerStart();

  // Inicializacion del PWM
  pwmPin.period(1.0/pwmFrequency); // Periodo del PWM
  pwmPin.write(0.5); // Duty inicial de señal cuadrada 50 % de t_on
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
  // Asignacion del valor del ADC al ciclo de duty y llevarlo a valores entre 0 y 1
  dutyCycle = sensorVoltage/3.3; 
  // Escritura del duty sobre el pin asignado a PWM
  pwmPin.write(dutyCycle);

}
