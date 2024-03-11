// Programa que toma muestras random cada 100 ms, las muestra cada 1s y enciende un led 200 ms
// Created by Diego Remon
// https://github.com/DiegoRemonn/Arquitectura-Arduino-Nano-33-BLE

#include <Arduino.h>

// Declaración de variables y pines
int LED = 18;
int list_acc[50];
int idx = 0;
bool send_flag = false;

void setup() {
  // put your setup code here, to run once:
  // Inicializacion del puerto serie
  Serial.begin(115200);
  while(!Serial);
  
  pinMode(LED, OUTPUT);
  randomSeed(analogRead(0));

  // Inicialización de las tres tareas
  xTaskCreate(Tarea1,"Tarea1",10000,NULL,0,NULL); // Mayor prioridad al muestreo
  xTaskCreate(Tarea2,"Tarea2",10000,NULL,1,NULL); // Muestra por pantalla
  xTaskCreate(Tarea3,"Tarea3",10000,NULL,1,NULL); // Enciende led
}

void loop() {
  delay(1000);
}

void Tarea1( void * parameter ) {
  // Muestreo dato random
  while(true){
    int acc = random(0,100);
    list_acc[idx] = acc;
    idx = (idx+1)%10;
    delay(100);
  }
  vTaskDelete( NULL ); // Finalizo tarea
}

void Tarea2( void * parameter) {
  // Muestro los diez valores muestreados
  while(true){
    Serial.println("Datos nuevos:");
    for(int i=0;i<10;i++){
      Serial.println(list_acc[i]);
    }    
    delay(1000); 
    send_flag = true;
  }
  vTaskDelete( NULL ); // Finalizo tarea
}

void Tarea3( void * parameter) {
  // Enciendo LED tras mostrar
  while(true){
    if (send_flag){
      digitalWrite(LED,HIGH);
      //Serial.println("LED ON");
      send_flag = false;
    }
    delay(200);     
    //Serial.println("LED OFF");
    digitalWrite(LED,LOW);
  }
  vTaskDelete( NULL ); // Finalizo tarea
}
