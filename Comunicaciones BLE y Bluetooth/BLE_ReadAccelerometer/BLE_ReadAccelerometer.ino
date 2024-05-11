// Conexión de dispositivo con GATT y lectura/notificación de los datos del acelerómetro con característica BLE
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <ArduinoBLE.h>
#include <Arduino.h>
#include "BBTimer.hpp"
#include <Arduino_LSM9DS1.h>

// Designacion de un timer de la clase BBTimer para su uso
BBTimer my_t3(BB_TIMER3);

// Inicializacion de Variables y pines del dispositivo
bool send = false;
String x, y, z;
String a;
float x_acc, y_acc, z_acc;

// Declaración UUID de servicio y de característica
const char* deviceServiceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
const char* deviceServiceCharacteristicUuid = "19b10001-e8f2-537e-4f6c-d104768a1214";

// UUID personalizado para el servicio de acelerometro
const char* accelerometerServiceUuid = "F000AA10-0451-4000-B000-000000000000";
// UUID personalizado para la caracteristica de acelerometro
const char* accelerometerXCharacteristicUuid = "F000AA11-0451-4000-B000-000000000000";
const char* accelerometerYCharacteristicUuid = "F000AA12-0451-4000-B000-000000000000";
const char* accelerometerZCharacteristicUuid = "F000AA13-0451-4000-B000-000000000000";
const char* accelerometerCharacteristicUuid = "F000AA14-0451-4000-B000-000000000000";

BLEService accelerometerService(accelerometerServiceUuid); // BLE Accelerometer Service

// BLE Accelerometer Characteristic - custom 128-bit UUID, read and notify by central
// Syntax: BLE<DATATYPE>Characteristic <NAME>(<UUID>,<PROPERTIES>,<DATA LENGTH>)
BLEStringCharacteristic ble_accelerometerX(accelerometerXCharacteristicUuid, BLERead | BLENotify, 12);
BLEStringCharacteristic ble_accelerometerY(accelerometerYCharacteristicUuid, BLERead | BLENotify, 12);
BLEStringCharacteristic ble_accelerometerZ(accelerometerZCharacteristicUuid, BLERead | BLENotify, 12);
BLEStringCharacteristic ble_accelerometer(accelerometerCharacteristicUuid, BLERead | BLENotify, 20);

//Function prototype
void readValues();

// Funcion de devolucion de llamada del timer
void t3Callback()
{
  send = true; // Semaforo/Flag lectura ADC
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);

  // Inicializacion del sensor IMU (Inertial Measurement Unit)
  // Comprobacion de un arranque correcto
  if(!IMU.begin()){
    Serial.println("Error al inicializar el IMU!");
    while(1);
  }

  // set LED's pin to output mode
  pinMode(LED_BUILTIN, OUTPUT);
  
  digitalWrite(LED_BUILTIN, LOW);    // when the central disconnects, turn off the LED

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy failed!");
    while (1);
  }

  // set advertised local name and service UUID:
  BLE.setLocalName("Nano_33_BLE_Sense_Diego"); // set your own local name
  BLE.setAdvertisedService(accelerometerService);

  // add the characteristic to the service
  accelerometerService.addCharacteristic(ble_accelerometerX);
  accelerometerService.addCharacteristic(ble_accelerometerY);
  accelerometerService.addCharacteristic(ble_accelerometerZ);
  accelerometerService.addCharacteristic(ble_accelerometer);

  // add service
  BLE.addService(accelerometerService);

  // start advertising
  BLE.advertise();

  // Muestro por pantalla mensaje de espera a una nueva conexión
  Serial.println("BLE LED Peripheral");
  Serial.println("Bluetooth device is now active, waiting for connections...");

  // Inicializacion y arranque del timer con una periodicidad de 1 segundo
  my_t3.setupTimer(1000000, t3Callback);
  my_t3.timerStart();
}

void loop() {
  // put your main code here, to run repeatedly:
  // listen for Bluetooth® Low Energy peripherals to connect:
  BLEDevice central = BLE.central();

  // if a central is connected to peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());
    digitalWrite(LED_BUILTIN, HIGH);            // turn on the LED to indicate the connection

    // while the central is still connected to peripheral:
    while (central.connected()) {
      if (send == true) {
        // Read values from the sensor
        readValues();

        // Writing sensor values to the characteristic
        ble_accelerometerX.writeValue(x);
        ble_accelerometerY.writeValue(y);
        ble_accelerometerZ.writeValue(z);
        ble_accelerometer.writeValue(a);

        // Displaying the sensor values on the Serial Monitor
        Serial.println("Reading sensors...");
        Serial.println(x + ", " + y + ", " + z);
        Serial.println("\n");
        send = false;
      }
    }

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
    digitalWrite(LED_BUILTIN, LOW);    // when the central disconnects, turn off the LED
  }
}

void readValues() {
  if (IMU.accelerationAvailable()) {
    // Lectura del acelerometro en x, y, z
    IMU.readAcceleration(x_acc, y_acc, z_acc);
  }
  x = "x: " + String(x_acc);
  y = "y: " + String(y_acc);
  z = "z: " + String(z_acc);

  a = String(x_acc) + ", " + String(y_acc) + ", " + String(z_acc);
}