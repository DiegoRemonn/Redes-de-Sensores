// Advertising my name on BLE
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <ArduinoBLE.h>

// Declaración UUID de servicio y de característica
const char* deviceServiceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
const char* deviceServiceCharacteristicUuid = "19b10001-e8f2-537e-4f6c-d104768a1214";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  // Comprobación de inicio correcto de BLE
  if(!BLE.begin()){
    Serial.println("* Starting Bluetooth® Low Energy module failed!");
    while(1);
  }

  // Escritura y advertise del dispositivo con "Mi Nombre"
  BLE.setLocalName("Diego"); // Set your own local name
  BLE.advertise();

  // Muestro por pantalla mensaje de espera a una nueva conexión
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
    while (central.connected()) {
      // No hago nada mientras estoy conectado, aquí se pueden hacer otras actividades si fuera necesario
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
