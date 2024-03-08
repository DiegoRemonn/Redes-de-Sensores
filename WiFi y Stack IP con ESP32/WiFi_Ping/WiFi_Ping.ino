// Conexión a red WiFi y comprobación de conectividad con Google mediante un ping
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <WiFi.h>
#include <ESPping.h>

// Declaración de las características de la red WiFi
const char* ssid = "Redmi_Note_8_Pro";
const char* password = "pkdq7163";

void setup() {
  // put your setup code here, to run once:
  // Inicialización del puerto serie
  Serial.begin(9600);

  // Conexión a la red WiFi
  WiFi.begin(ssid, password);

  Serial.println("Conectando a" + String("ssid"));

  // Espera a que la conexión sea correcta
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  // Muestro por pantalla la IP asignada al dispositivo
  Serial.println("");
  Serial.println("Conexión establecida");
  Serial.print("Dirección IP asignada: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  // Realizar un ping a Google si la conexión a WiFi es correcta
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Realizando ping a google.com... ");
    // Si el ping realizado es correcto se recibe mensaje de comunicación adecuada
    if (Ping.ping("google.com")) {
      Serial.println("Respuesta recibida");
    } else {
      Serial.println("Fallo en la respuesta"); // Fallo en la comunicación
    }
    delay(5000); // Espero 5 segundos antes de realizar un nuevo ping
  } else {
    Serial.println("Error: No hay conexión a la red WiFi");
    delay(1000);
  }
}
