// Escritura I2C con Arduino Nano 33 BLE
// Created by Diego Remon
// https://github.com/DiegoRemonn/Arquitectura-Arduino-Nano-33-BLE

#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  // Inicializacion del puerto serie
  Serial.begin(9600);
  while(!Serial);
  // Inicializacion de la comunicacion I2C
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // Pregunta en el puerto serie sobre la eleccion de encendido o apagado del led
  Serial.print("Enter 0 to turn off led, enter 1 to turn it on ");
  // Creacion de variable de lectura del led con un solo indice
  char ledVal[0];
  // Lectura del puerto serie del valor del led
  readSerial(ledVal);
  // Inicio de la transmision del dato por I2C en la direccion 8
  Wire.beginTransmission(8);
  // Escritura del valor del led por I2C
  Wire.write(ledVal);
  // Finalizacion de la transmision
  Wire.endTransmission();
  // Espera de medio segundo para la realizacion del envio
  delay(500);
}

// Funcion de lectura del puerto Serie y que devuelve un entero
// Se guarda en una variable char[] la palabra leida
int readSerial(char resultado[]){
  int i = 0;
  // Bucle infinito para lectura continua hasta detectar un fin de linea '\n'
  while(1){
    // Bucle que se ejecuta mientras haya datos disponibles en el puerto serie
    while(Serial.available() > 0){
      // Lectura del dato obtenido en el puerto serie
      char inChar = Serial.read();
      // Comprobacion de final de cadena / final de linea
      if (inChar == '\n') {
        // Asignacion de caracter nulo a la posicion actual del resultado (final de cadena)
        resultado[i] = '\0';
        // Vaciado del buffer de entrada del puerto serie
        Serial.flush(); //Asegurar que no hay datos pendientes en el puerto serie tras lectura
        return 0; // Fin de lectura, lectura exitosa
      }
      // Comprobacion de caracter leido distinto al caracter de movimiento del cursor al inicio de linea
      if (inChar != '\r') {
        // Asignacion del caracter leido a la posicion actual del resultado
        resultado[i] = inChar;
        i++; // Incremento del indice de la cadena de caracteres
      }
    }
  }
}
