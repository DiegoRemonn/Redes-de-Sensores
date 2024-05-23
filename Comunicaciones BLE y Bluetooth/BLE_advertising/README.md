# BLE_advertising

Este directorio contiene un proyecto para anunciar el nombre de un dispositivo a través de Bluetooth Low Energy (BLE). El archivo `BLE_advertising.ino` contiene el código necesario para realizar esta tarea.

## Descripción

El programa `BLE_advertising.ino` permite que un dispositivo Arduino Nano 33 BLE anuncie su nombre a través de BLE. Esto permite que otros dispositivos con capacidad BLE detecten y se conecten al dispositivo anunciante.

### Funcionalidad

- Inicia el módulo Bluetooth Low Energy.
- Asigna un nombre local al dispositivo BLE.
- Inicia la publicidad del dispositivo, anunciando su nombre a otros dispositivos BLE cercanos.
- Espera a que otros dispositivos se conecten a él.
- Muestra mensajes en el monitor serie indicando la conexión y desconexión de dispositivos.

## Uso

1. Abre el archivo `BLE_advertising.ino` en el IDE de Arduino.
2. Carga el código en tu Arduino Nano 33 BLE.
3. Observa en el monitor serie que el dispositivo está activo y esperando conexiones BLE.
4. Usa una aplicación como nrfConnect para poder comunicarte con el Arduino.
