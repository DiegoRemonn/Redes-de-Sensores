# Comunicacion_I2C

Implementación de comunicación I2C entre dos dispositivos utilizando el Arduino Nano 33 BLE. El proyecto se divide en dos partes: `Escritura_I2C` y `Lectura_I2C`.

## Contenido

- `Escritura_I2C`: Contiene el código para el dispositivo maestro que envía datos a través del protocolo I2C.
- `Lectura_I2C`: Contiene el código para el dispositivo esclavo que recibe datos a través del protocolo I2C.

## Requisitos

- Dos dispositivos Arduino Nano 33 BLE.
- Conexión I2C entre los dispositivos (conexión de las líneas SDA y SCL).
- Un LED conectado al pin D2 del dispositivo esclavo.

## Uso

1. Sube el código `Escritura_I2C.ino` al dispositivo maestro.
2. Sube el código `Lectura_I2C.ino` al dispositivo esclavo.
3. Abre el monitor serie en el IDE de Arduino a 9600 baudios para el dispositivo maestro y sigue las instrucciones para encender o apagar el LED en el dispositivo esclavo.
