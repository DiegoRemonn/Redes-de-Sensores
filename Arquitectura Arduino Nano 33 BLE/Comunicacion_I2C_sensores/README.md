# Comunicaciones I2C Sensores

Este proyecto aborda la comunicación I2C entre el Arduino Nano 33 BLE y otros dispositivos para la lectura y escritura de datos de sensores inerciales (IMU), como el acelerómetro, giroscopio y magnetómetro.

## Contenido

- `Escritura_I2C_sensores`: Contiene el código para escribir datos de sensores a través de comunicación I2C.
- `Lectura_I2C_sensores`: Contiene el código para leer datos de sensores a través de comunicación I2C.
- `BBTimer.hpp`: Archivo de cabecera que define la clase `BBTimer`.

## Requisitos

- Arduino Nano 33 BLE.
- Conexión a dispositivos compatibles con I2C para la lectura y escritura de datos.

## Uso

1. Sube el código correspondiente al tipo de comunicación I2C que desees utilizar al Arduino Nano 33 BLE.
2. Asegúrate de conectar los dispositivos externos de acuerdo con las especificaciones de la comunicación I2C.
3. Abre el monitor serie en el IDE de Arduino a 9600 baudios para verificar la comunicación y los datos leídos o escritos.
