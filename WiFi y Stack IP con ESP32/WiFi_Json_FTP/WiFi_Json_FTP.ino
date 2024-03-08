// Conexión a red WiFi y envío a un servidor FTP de ficheros Json
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <ArduinoJson.h>
#include <WiFi.h>
#include "ESP32_FTPClient.h"

// Declaración de las características de la red WiFi y servidor FTP
const char* ssid = "Redmi_Note_8_Pro";
const char* password = "pkdq7163";
char ftp_server[] = "155.210.150.77";
char ftp_user[] = "rsense";
char ftp_pass[] = "rsense";
char ftp_directory[] = "/rsense/797528";

// Inicialización de un cliente FTP
ESP32_FTPClient ftp (ftp_server,ftp_user,ftp_pass, 5000, 2);

// Inicialización de variables y pines
const unsigned long interval = 20000; // 10000 milisegundos
unsigned long previousMillis = 0;

void setup()
{
  // Inicialización del puerto serie
  Serial.begin(115200);
  
  // Inicializo semilla para los valores random
  randomSeed(analogRead(0));

  // Conexión a la red WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  // Espera a que la conexión sea correcta
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");

  
}

void loop()
{
  // Asigno a una variable el tiempo actual
  unsigned long currentMillis = millis();
  // Compruebo que la conexión al servidor FTP es correcta y sino la abro
  if (!ftp.isConnected()) {
    ftp.OpenConnection();
  }
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

  // Subo el Json al servidor FTP
  uploadJSON(output);
}

void uploadJSON(String json) {
  Serial.println("Conectando al servidor FTP...");  

  // Si hay conexión al servidor FTP envio los ficheros json
  if (ftp.isConnected()) {
    Serial.println("Conectado al servidor FTP");
    char fileName[32];
    sprintf(fileName, "grupoXX_%lu.json", millis()/1000); // %lu para generar numeros de archivo distintos
    Serial.println(fileName);
    ftp.InitFile("Type A"); // Transferencia de archivo ASCII
    //if (!ftp_directory) {
      //ftp.MakeDir("/rsense/797528");
    //}
    ftp.ChangeWorkDir(ftp_directory); // Cambio al directorio deseado
    ftp.NewFile(fileName); // le doy nuevo nombre al archivo
    char json_char[json.length() + 1];
    json.toCharArray(json_char, json.length() + 1); // Convierto json_char en una cadena de caracteres
    Serial.println(json_char);
    ftp.Write(json_char); // Escribo el archivo, luego lo cierro y finalizo conexión
    delay(2000);
    ftp.CloseFile();
    ftp.CloseConnection();
  } else {
    Serial.println("Error al conectar al servidor FTP");
  }
}
