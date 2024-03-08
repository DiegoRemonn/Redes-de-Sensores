// Conexión a red WiFi y conexión del ESP32 a un servidor TCP enviandole datos randoms/segundo
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <WiFi.h>
#include "time.h"
#include "ESP32TimerInterrupt.h"

// Declaración de las características de la red WiFi y servidor TCP
const char* ssid = "Redmi_Note_8_Pro";
const char* password = "pkdq7163";
//const char* serverIP = "10.200.122.205";
const char* serverIP = "192.168.73.181";
const uint serverPort = 4096;

// Inicialización de un cliente WiFi para comunicación TCP
WiFiClient client;

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

// Función que muestra la hora y día local y la envía mediante comunicación TCP
void SendData()
{
  // Comprueba si se establece una conexión con el servidor TCP y se encuentra conectado
  if (client.connect(serverIP, serverPort)) { // Establish a connection
    if (client.connected()){
      int temp = random (0, 100);
      client.printf("%d\n\n\n\n", temp);
      Serial.println(temp);
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
  
  // Inicializo semilla para los valores random
  randomSeed(analogRead(0));

  // Inicialización del timer (*1000 -> us)
  ITimer.attachInterruptInterval(TIMER_INTERVAL_MS * 1000, TimerHandler);
}

void loop()
{
  // Compruebo que ha pasado un segundo y envío por TCP el dato random
  if (send == true) {
    SendData();
    send = false;
  }
}
