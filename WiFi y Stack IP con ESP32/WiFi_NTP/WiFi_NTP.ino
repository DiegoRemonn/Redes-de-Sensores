// Conexión a red WiFi y puesta del módulo en hora mediante un servidor NTP
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <WiFi.h>
#include "time.h"
#include "ESP32TimerInterrupt.h"

// Declaración de las características de la red WiFi
const char* ssid = ""; // Put your own WiFi ssid
const char* password = ""; // Put your own WiFi password

// Declaración de las características del servidor NTP
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

// Inicialización de variables y pines
bool send = false;
int TIMER_INTERVAL_MS = 1000; // Timer se ejecuta cada segundo

// Inicialización de un Timer del ESP32
ESP32Timer ITimer(0);

// Función de interrupción del ESP32 Handler
bool IRAM_ATTR TimerHandler(void*) {
  send = true;
  return send; // Devuelve el flag de nueva interrupción
}

// Función que muestra la hora y día local
void printLocalTime()
{
  struct tm timeinfo; // Variable para almacenar los datos del servidor
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  // Comprobación de que la hora recibida es correcta
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  // Muestro la información del servidor NTP
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
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
  // Compruebo que ha pasado un segundo y muestro el tiempo local
  if (send == true) {
    printLocalTime();
    send = false;
  }
}
