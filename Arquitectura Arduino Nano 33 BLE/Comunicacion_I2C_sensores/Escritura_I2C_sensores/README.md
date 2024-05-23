# Escritura I2C Sensores

Este directorio contiene el código para escribir y transmitir datos a través del protocolo I2C desde el Arduino Nano 33 BLE hacia otros dispositivos, utilizando sensores de aceleración, giroscopio y magnetómetro.

## Archivos

- `Escritura_I2C_sensores.ino`: Archivo principal del proyecto que contiene el código fuente.
- `BBTimer.hpp`: Archivo de cabecera que define la clase `BBTimer`.

## Descripción del Código

### `Escritura_I2C_sensores.ino`

Este archivo configura y utiliza un temporizador para realizar lecturas periódicas de los sensores y transmitir los datos a través del protocolo I2C. El código realiza las siguientes funciones:

1. Inicializa el puerto serie a una velocidad de 9600 baudios.
2. Inicializa la comunicación I2C.
3. Inicializa el sensor IMU (Unidad de Medición Inercial) y verifica su correcto funcionamiento.

### `BBTimer.hpp`

Este archivo define la clase `BBTimer` que permite acceder y manejar los cinco timers de 32 bits del nRF52840. La clase proporciona métodos para configurar, iniciar, detener y actualizar el periodo de los timers.

## Uso

1. Conecta el Arduino Nano 33 BLE a tu computadora.
2. Sube el código `Escritura_I2C_sensores.ino` al dispositivo.
3. Abre el monitor serie en el IDE de Arduino a 9600 baudios para verificar la transmisión de datos.
