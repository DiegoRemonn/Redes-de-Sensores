// Conexión a red WiFi y conexión del ESP32 a un servidor TCP enviandole la hora local
// Envía si se indica "start" y deja de enviar si se indica "stop"
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <WiFi.h>
#include "time.h"
#include "ESP32TimerInterrupt.h"

// Declaración de las características de la red WiFi y servidor TCP
const char* ssid = "Redmi_Note_8_Pro";
const char* password = "pkdq7163";
const char* serverIP = "10.200.122.205";
const uint serverPort = 4096;

// Declaración de las características del servidor NTP
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

// Inicialización de un cliente WiFi para comunicación TCP
WiFiClient client;

// Inicialización de variables y pines
bool enable = false;
bool send = false;
int TIMER_INTERVAL_MS = 1000; // Timer se ejecuta cada segundo

// Inicialización de un Timer del ESP32
ESP32Timer ITimer(0);

// Función de interrupción del ESP32 Handler
bool IRAM_ATTR TimerHandler(void*) {
  send = true;
  return send; // Devuelve el flag de nueva interrupción
}

// Función que muestra la hora y día local y la envía mediante comunicación TCP
void printLocalTime()
{
  struct tm timeinfo; // Variable para almacenar los datos del servidor
  // Comprobación de que la hora recibida es correcta
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  //Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  // Comprueba si se establece una conexión con el servidor TCP y se encuentra conectado
  if (client.connect(serverIP, serverPort)) { // Establish a connection
    if (client.connected()){
      // Comprueba si se permite el envío tras recibir "start"
      if (enable == true) {
        client.print(&timeinfo, "%A, %B %d %Y %H:%M:%S\n\n\n\n"); // \n para visualización en el servidor
      }
    }
  }
}

void setup()
{
  // Inicialización del puerto serie
  Serial.begin(115200);
  
  // Conexión a la red WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  // Espera a que la conexión sea correcta
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
  
  // Inicializo el NTP y muestro el tiempo
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  // Inicialización del timer (*1000 -> us)
  ITimer.attachInterruptInterval(TIMER_INTERVAL_MS * 1000, TimerHandler);
}

void loop()
{
  // Compruebo que ha pasado un segundo y envío por TCP el tiempo local
  if (send == true) {
    printLocalTime();
    send = false;
  }
  
  // Compruebo que hay conexión con el servidor y que ha recibido un mensaje el cliente
  if (client.connected()){
    if (client.available() > 0) {
      // Lectura del mensaje del servidor hasta final de línea
      String envio = client.readStringUntil('\n');
      Serial.println(envio);
      // Si el mensaje recibido es "Start permite enviar datos al servidor"
      if (envio == "Start") {
        enable = true;
      } else if (envio == "Stop") { // Si el mensaje recibido es "Stop deja de enviar datos"
        enable = false;
      } else { // Cualquier otro mensaje recibido no es válido
        client.print("Not valid value, choose Start or Stop\n");
        Serial.println("Not valid value, choose Start or Stop");
      }
    }
  }
}
