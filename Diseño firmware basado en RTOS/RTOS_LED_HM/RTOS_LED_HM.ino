// Programa con dos tareas LED que enciende cada 200 ms y envío "Hola Mundo" cada 1 segundo
// Created by Diego Remon
// https://github.com/DiegoRemonn/Arquitectura-Arduino-Nano-33-BLE

#include <Arduino.h>

int LED = 18;

void setup() {
  // put your setup code here, to run once:
  // Inicializacion del puerto serie
  Serial.begin(115200);
  while(!Serial);
  
  pinMode(LED, OUTPUT);

  // Inicialización de las dos tareas
  xTaskCreate(Tarea1,"Tarea1",10000,NULL,1,NULL);
  xTaskCreate(Tarea2,"Tarea2",10000,NULL,1,NULL);
}

void loop() {
  delay(1000);
}

void Tarea1( void * parameter ) {
  // Envío por puerto serie "Hola mundo"
  while(true){
    Serial.println("Hola mundo");
    delay(1000);
  }
  vTaskDelete( NULL ); // Finalizo tarea
}

void Tarea2( void * parameter) {
  // Enciendo o apago el led según el estado actual
  while(true){
    Serial.println("LED toggle");
    digitalWrite(LED,!digitalRead(LED)) ;
    delay(200); 
  }
  vTaskDelete( NULL ); // Finalizo tarea
}
