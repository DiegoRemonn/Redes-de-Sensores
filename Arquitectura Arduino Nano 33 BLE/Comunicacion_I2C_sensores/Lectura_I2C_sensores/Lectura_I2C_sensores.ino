// Lectura sensores de aceleracion, giroscopo y magnetometro
// Created by Diego Remon
// https://github.com/DiegoRemonn/Arquitectura-Arduino-Nano-33-BLE

#include <Arduino.h>
#include "BBTimer.hpp"
#include <Arduino_LSM9DS1.h>
#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  // Inicializacion del puerto serie
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Started"); // Mensaje de inicio del puerto serie

  // Inicializacion de la comunicacion I2C (lectura de la direccion 8)
  Wire.begin(8);
  // Declaracion de la comunicacion como lectura llamada a su funcion de Evento
  Wire.onReceive(receiveEvent);

  // Inicializacion del sensor IMU (Inertial Measurement Unit)
  // Comprobacion de un arranque correcto
  if(!IMU.begin()){
    Serial.println("Error al inicializar el IMU!");
    while(1);
  }

  // Muestra por puerto serie el ratio de muestras del acelerometro en Hz y otros mensajes utiles
  Serial.print("Ratio de muestras del acelerometro = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Aceleracion en g's");
  Serial.println("X\tY\tZ");

  // Muestra por puerto serie el ratio de muestras del giroscopo en Hz y otros mensajes utiles
  Serial.print("Ratio de muestras del giroscopo = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope en grados/segundo");
  Serial.println("X\tY\tZ");

  // Muestra por puerto serie el ratio de muestras del magnetometro en Hz y otros mensajes utiles
  Serial.print("Ratio de muestras del campo magnetico = ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Magnetic Field in uT");
  Serial.println("X\tY\tZ");
}

void loop() {
  // put your main code here, to run repeatedly:

}

// Funcion que se ejecuta al recibir evento I2C
// howMany indica el numero de bytes legibles desde el dispositivo maestro
void receiveEvent(int howMany){
  // Inicializacion de un string vacio sobre el que se escribiran los datos recibidos
  String data = "";
  // Bucle mientras que hay comunicacion / envio disponible
  while(Wire.available()){
    // Inicializacion y lectura del caracter obenido por I2C
    char lectura = Wire.read();
    // El caracter leido via comunicacion I2C se añade al string "data"
    data += lectura;
  }
  // Muestra por pantalla los datos obtenidos por cada segundo y enciende LED
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5);
  digitalWrite(LED_BUILTIN, LOW); 
  Serial.println(data);
}
