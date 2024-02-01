// Lectura I2C
// Created by Diego Remon
// https://github.com/DiegoRemonn/Arquitectura-Arduino-Nano-33-BLE

#include <Wire.h>

// Inicializacion del pin del LED
int LEDPin = D2;

void setup() {
  // put your setup code here, to run once:
  // Inicializacion de la comunicacion I2C (lectura de la direccion 8)
  Wire.begin(8);
  // Declaracion de la comunicacion como lectura llamada a su funcion de Evento
  Wire.onReceive(receiveEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// Funcion que se ejecuta al recibir evento I2C
// howMany indica el numero de bytes legibles desde el dispositivo maestro
void receiveEvent(int howMany){
  // Inicializacion y lectura del caracter obenido por I2C
  char lectura = Wire.read(); //Caracter recibido
  // Comprobacion que el caracter recibido sea '0'
  if(lectura == '0'){
    digitalWrite(LEDPin, LOW); // Apaga el LED
  }
  // Comprobacion que el caracter recibido sea '1'
  if(lectura == '1'){
    digitalWrite(LEDPin, HIGH); // Enciende el LED
  }
}
