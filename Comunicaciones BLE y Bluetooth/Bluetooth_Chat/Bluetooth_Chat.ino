// Chat entre dos dispositivos mediante Bluetooth clásico
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include "BluetoothSerial.h"

// Declaro nombre del dispositivo
String device_name = "ESP32-BT-Slave";

// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
  #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
  #error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

// Inicialización de Bluetooth Serial
BluetoothSerial SerialBT;

void setup() {
  // Inicialización del puerto serie
  Serial.begin(115200);
  SerialBT.begin("ESP32_Diego"); //Bluetooth device name (Lo declaro aquí)
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
}

void loop() {
  // Si hay datos disponibles en puerto serie los envío via bluetooth
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  // Si hay datos recibidos por Bluetooth los muestro en el puerto serie
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}