# BLE_LED

Este directorio contiene un proyecto para controlar un LED RGB a través de Bluetooth Low Energy (BLE). El archivo `BLE_LED.ino` contiene el código necesario para realizar esta tarea.

## Descripción

El programa `BLE_LED.ino` permite controlar un LED RGB conectado a un dispositivo Arduino Nano 33 BLE mediante BLE. Utiliza un servicio y una característica personalizados para enviar comandos de control de color desde un dispositivo central BLE.

### Funcionalidad

- Inicia el módulo Bluetooth Low Energy.
- Asigna un nombre local al dispositivo BLE.
- Define un servicio BLE y una característica para controlar el LED RGB.
- Espera a que otros dispositivos BLE se conecten a él para controlar el LED.
- Cambia el color del LED según los comandos enviados desde el dispositivo central BLE.

## Uso

1. Abre el archivo `BLE_LED.ino` en el IDE de Arduino.
2. Carga el código en tu Arduino Nano 33 BLE.
3. Observa en el monitor serie que el dispositivo está activo y esperando conexiones BLE.
4. Utiliza un dispositivo compatible con BLE (como un teléfono inteligente) para conectarte al dispositivo y controlar el LED RGB enviando valores a través de la característica definida usando una aplicación como nrfConnect.
