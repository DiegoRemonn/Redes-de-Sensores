// Conexión a red WiFi y suscripcion a servidor de Adafruit mediante MQTT para recepción de datos
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include "config.h"  // Archivo de configuración con credenciales de Adafruit IO

// Inicialización de un cliente WiFi para comunicación TCP
WiFiClient client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, IO_SERVER, IO_SERVERPORT, IO_USERNAME, IO_KEY);

// Setup a feed for publishing.
AdafruitIO_Feed *feed = io.feed("");

void setup()
{
  // Inicialización del puerto serie
  Serial.begin(115200);
  
  // Conexión a la red WiFi
  Serial.printf("Connecting to %s ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  // Espera a que la conexión sea correcta
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
  
  // Muestro la dirección IP asignada
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Inicializo Adafruit IO
  io.connect();

  feed->onMessage(feedMessage);
}

void loop()
{
  // Procesamiento de mensajes y mantenimiento de la conexión
  io.run();
}

// Función de callback para manejar mensajes entrantes del feed
void feedMessage(AdafruitIO_Data *data) {
  Serial.print("Nuevo mensaje en el feed: ");
  Serial.println(data->value());
}
