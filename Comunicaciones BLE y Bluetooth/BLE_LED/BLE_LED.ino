// Conexión de dispositivo con GATT y variación del color LED RGB con característica BLE
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <ArduinoBLE.h>

// Declaración UUID de servicio y de característica
const char* deviceServiceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
const char* deviceServiceCharacteristicUuid = "19b10001-e8f2-537e-4f6c-d104768a1214";

// Declaración de un servicio para el LED en la UUID "180A"
BLEService ledService("180A"); // BLE LED Service

// Característica de activación del LED Escribible y Legible
// BLE LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLEByteCharacteristic switchCharacteristic("2A57", BLERead | BLEWrite);

void setup() {
  // put your setup code here, to run once:
  // Inicialización del puerto serie
  Serial.begin(9600);
  while (!Serial);

  // set LED's pin to output mode
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  digitalWrite(LED_BUILTIN, LOW);         // when the central disconnects, turn off the LED
  digitalWrite(LEDR, HIGH);               // will turn the LED off (RGB con ánodo común)
  digitalWrite(LEDG, HIGH);               // will turn the LED off
  digitalWrite(LEDB, HIGH);               // will turn the LED off

  // Comprobación de inicio correcto de BLE
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy failed!");
    while (1);
  }

  // Escritura del nombre del dispositivo y del Servicio declarado para el led
  BLE.setLocalName("Nano_33_BLE_Sense_Diego"); // set your own local name
  BLE.setAdvertisedService(ledService);

  // Añade característica al servicio
  ledService.addCharacteristic(switchCharacteristic);

  // Añade el servicio a BLE
  BLE.addService(ledService);

  // Valor inicial para la característica switch
  switchCharacteristic.writeValue(0);

  // Inicia el advertising
  BLE.advertise();

  // Muestro por pantalla mensaje de espera a una nueva conexión
  Serial.println("BLE LED Peripheral");
  Serial.println("Bluetooth device is now active, waiting for connections...");
}

void loop() {
  // put your main code here, to run repeatedly:
  // listen for Bluetooth® Low Energy peripherals to connect: (Inicio un dispositivo BLE central)
  BLEDevice central = BLE.central();

  // if a central is connected to peripheral: (Compruebo conexión a un periférico)
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());
    digitalWrite(LED_BUILTIN, HIGH);            // Enciendo LED para indicar conexión

    // Bucle que se ejecuta mientras se encuentre el dispositivo conectado al central
    while (central.connected()) {
      // Si escribo una característica en el dispositivo central:
      // Uso el valor para controlar el LED: (01, 02, 03 valores en Bytes)
      if (switchCharacteristic.written()) {
        switch (switchCharacteristic.value()) {   // any value other than 0
          case 01:
            Serial.println("Red LED on");     // LED rojo on
            digitalWrite(LEDR, LOW);          // will turn the LED on
            digitalWrite(LEDG, HIGH);         // will turn the LED off
            digitalWrite(LEDB, HIGH);         // will turn the LED off
            break;
          case 02:
            Serial.println("Green LED on");   // LED verde on
            digitalWrite(LEDR, HIGH);         // will turn the LED off
            digitalWrite(LEDG, LOW);          // will turn the LED on
            digitalWrite(LEDB, HIGH);         // will turn the LED off
            break;
          case 03:
            Serial.println("Blue LED on");    // LED azul on
            digitalWrite(LEDR, HIGH);         // will turn the LED off
            digitalWrite(LEDG, HIGH);         // will turn the LED off
            digitalWrite(LEDB, LOW);          // will turn the LED on
            break;
          default:
            Serial.println(F("LEDs off"));     // LED's apagados
            digitalWrite(LEDR, HIGH);          // will turn the LED off
            digitalWrite(LEDG, HIGH);          // will turn the LED off
            digitalWrite(LEDB, HIGH);          // will turn the LED off
            break;
        }
      }
    }

    // Desconexión del central
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
    digitalWrite(LED_BUILTIN, LOW);    // Apago el led al desconectar del central
    digitalWrite(LEDR, HIGH);          // will turn the LED off
    digitalWrite(LEDG, HIGH);          // will turn the LED off
    digitalWrite(LEDB, HIGH);          // will turn the LED off
  }
}