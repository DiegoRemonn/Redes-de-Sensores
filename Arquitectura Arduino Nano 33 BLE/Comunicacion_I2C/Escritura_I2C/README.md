# Escritura_I2C

Código para el dispositivo maestro que envía datos a través del protocolo I2C utilizando un Arduino Nano 33 BLE.

## Archivos

- `Escritura_I2C.ino`: Archivo principal del proyecto que contiene el código fuente.

## Descripción del Código

El código realiza las siguientes funciones:

1. Inicializa el puerto serie a una velocidad de 9600 baudios.
2. Inicializa la comunicación I2C.
3. Solicita al usuario que ingrese un valor (`0` para apagar el LED, `1` para encender el LED).
4. Envía el valor ingresado al dispositivo esclavo en la dirección I2C 8.

### Funciones Principales

- `setup()`: Configura la comunicación serie y la comunicación I2C.
- `loop()`: Solicita al usuario un valor y lo envía a través de I2C.
- `readSerial(char resultado[])`: Lee un valor del puerto serie y lo almacena en un array de caracteres.

## Uso

1. Conecta el Arduino Nano 33 BLE configurado como maestro a tu computadora.
2. Sube el código `Escritura_I2C.ino` al dispositivo.
3. Abre el monitor serie en el IDE de Arduino a 9600 baudios.
4. Sigue las instrucciones en el monitor serie para enviar datos al dispositivo esclavo.
