# Comunicaciones BLE y Bluetooth

Este directorio contiene varios proyectos relacionados con comunicaciones mediante Bluetooth de baja energía (BLE) y Bluetooth clásico. Cada subdirectorio contiene un proyecto específico con su respectivo archivo principal.

## Subcarpetas y Proyectos

### 1. BLE_ActivateAccelerometer
Este proyecto permite activar o desactivar un acelerómetro a través de una característica BLE personalizada.

#### Contenido:
- `BLE_ActivateAccelerometer.ino`: Código principal del proyecto que controla la activación y desactivación del acelerómetro mediante Bluetooth.

#### Descripción:
El proyecto establece un servicio BLE con una característica que permite activar o desactivar un acelerómetro. Cuando se activa, el dispositivo comienza a enviar datos del acelerómetro a través de Bluetooth.

### 2. BLE_advertising
Este proyecto demuestra cómo configurar la publicidad BLE en una placa compatible con Arduino.

#### Contenido:
- `BLE_advertising.ino`: Código principal del proyecto que configura la publicidad BLE en la placa.

#### Descripción:
El proyecto configura el dispositivo para que transmita mensajes de publicidad BLE. Estos mensajes pueden ser detectados por otros dispositivos BLE cercanos.

### 3. BLE_LED
Este proyecto controla un LED a través de Bluetooth de baja energía (BLE).

#### Contenido:
- `BLE_LED.ino`: Código principal del proyecto que controla un LED mediante Bluetooth BLE.

#### Descripción:
El proyecto establece un servicio BLE con una característica que permite encender y apagar un LED conectado a la placa Arduino mediante comandos Bluetooth.

### 4. BLE_ReadAccelerometer
Este proyecto lee los datos de un acelerómetro y los transmite a través de Bluetooth BLE.

#### Contenido:
- `BLE_ReadAccelerometer.ino`: Código principal del proyecto que lee los datos del acelerómetro y los transmite mediante Bluetooth BLE.

#### Descripción:
El proyecto lee los datos de un acelerómetro y los envía a través de Bluetooth BLE a dispositivos conectados. Los datos del acelerómetro pueden ser leídos por dispositivos remotos para su análisis.

### 5. Bluetooth_Chat
Este proyecto permite establecer un chat entre dos dispositivos utilizando Bluetooth clásico.

#### Contenido:
- `Bluetooth_Chat.ino`: Código principal del proyecto que permite el intercambio de mensajes entre dos dispositivos mediante Bluetooth clásico.

#### Descripción:
El proyecto configura la comunicación Bluetooth clásico entre dos dispositivos y permite el intercambio de mensajes a través de un chat simple.
