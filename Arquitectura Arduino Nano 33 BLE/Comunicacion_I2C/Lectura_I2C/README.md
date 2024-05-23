# Lectura_I2C

Código para el dispositivo esclavo que recibe datos a través del protocolo I2C utilizando un Arduino Nano 33 BLE.

## Archivos

- `Lectura_I2C.ino`: Archivo principal del proyecto que contiene el código fuente.

## Descripción del Código

El código realiza las siguientes funciones:

1. Inicializa la comunicación I2C en la dirección 8.
2. Configura una función de evento que se ejecuta cuando se reciben datos a través de I2C.
3. Enciende o apaga un LED conectado al pin D2 en función del valor recibido (`0` para apagar, `1` para encender).

### Funciones Principales

- `setup()`: Configura la comunicación I2C y la función de evento.
- `loop()`: No realiza ninguna acción, el control se gestiona a través de la función de evento.
- `receiveEvent(int howMany)`: Función de evento que se ejecuta cuando se reciben datos a través de I2C, y controla el estado del LED.

## Uso

1. Conecta el Arduino Nano 33 BLE configurado como esclavo a tu computadora.
2. Conecta un LED al pin D2 del Arduino.
3. Sube el código `Lectura_I2C.ino` al dispositivo.
4. El dispositivo esclavo recibirá datos del dispositivo maestro y controlará el estado del LED en consecuencia.
