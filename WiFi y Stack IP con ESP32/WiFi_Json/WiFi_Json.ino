// Creación de fichero Json cada 10 segundos con datos de temperatura random
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <ArduinoJson.h>

// Inicialización de variables y pines
const unsigned long interval = 10000; // 10000 milisegundos
unsigned long previousMillis = 0;

void setup()
{
  // Inicialización del puerto serie
  Serial.begin(115200);

  // Inicialización de semilla random
  randomSeed(analogRead(0));
}

void loop()
{
  // Asigno a una variable el tiempo actual
  unsigned long currentMillis = millis();
  // Compruebo que la diferencia de tiempos sea de 10 segundos
  if (currentMillis - previousMillis >= interval) {
    // Asigno al valor previo el actual de tiempo y genero y envio el Json
    previousMillis = currentMillis;
    generateAndSendData();
  }
}

void generateAndSendData() {
  // Construir el objeto JSON en formato SenML
  StaticJsonDocument<200> doc;
  doc["bv"] = random(0,100); // temperatura random
  doc["bu"] = "degC"; // unidades de temperatura
  doc["bt"] = millis() / 1000; // tiempo en segundos desde el inicio del programa

  // Serializo el documento Json "doc" en la variable output
  String output;
  serializeJson(doc, output);
  Serial.println("JSON generado:");
  Serial.println(output);  
}
