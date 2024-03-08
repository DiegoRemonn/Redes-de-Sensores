// Conexión a red WiFi y muestra del tiempo actual mediante un servidor WEB con pulsador para resetear la hora a 00:00
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

// Importar librerias necesarias
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"

// Declaración de las características de la red WiFi
const char* ssid = "Redmi_Note_8_Pro";
const char* password = "pkdq7163";

// Declaración de las características del servidor NTP
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

// Creación de un AsyncWebServer object en el puerto 80
AsyncWebServer server(80);

// Inicialización de variables y pines 
bool date2zero = false;

// Replaces placeholder with LED state value
String processor(const String& var){  
  struct tm timeinfo; // Variable para almacenar los datos del servidor
  char buffer[50]; // Inicialización de un buffer para los datos a enviar
  Serial.println(var);
  // Compruebo que la variable var sea igual a "Date"
  if(var == "Date"){
    // Si la hora recibida es correcta convierto a string la fecha actual y la devuelvo en el buffer
    if(getLocalTime(&timeinfo)){
      strftime(buffer, sizeof(buffer), "%A, %B %d %Y %H:%M:%S", &timeinfo);
      return (String)buffer;
    }
  }
  return String();
}

void setup() {
  // put your setup code here, to run once:
  // Inicialización del puerto serie
  Serial.begin(115200);

  // Inicializa SPIFFS
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Conexión a la red WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  // Espera a que la conexión sea correcta
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");

  // Inicializo el servidor NTP
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  // Muestro la dirección IP asignada al ESP32
  Serial.println(WiFi.localIP());

  // Ruta al root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false,processor);
  });
  
  // Ruta al archivo style.css
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });  
  
  // Reset de la fecha
  server.on("/RESTART", HTTP_GET, [](AsyncWebServerRequest *request){        
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  // Inicio el server
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

}
