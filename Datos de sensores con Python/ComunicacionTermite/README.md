# ComunicacionTermite

Este directorio contiene los recursos necesarios para el proyecto "ComunicacionTermite", que se encarga de enviar datos por puerto serie para lectura en Termite o Python.

## Archivos

- `ComunicacionTermite.ino`: Este archivo contiene el código principal del proyecto.
- `BBTimer.hpp`: Archivo de cabecera que define la clase `BBTimer` para gestionar los timers del microcontrolador.

## Contenido del Archivo 

### `ComunicacionTermite.ino`

El archivo `ComunicacionTermite.ino` configura un timer para medir periódicamente el acelerómetro del sensor LSM9DS1 conectado al Arduino Nano 33 BLE y envía los datos por puerto serie. Aquí está un resumen de lo que hace:

1. Inicializa el puerto serie a una velocidad de 9600 baudios.
2. Inicializa la comunicación I2C.
3. Inicializa el sensor IMU LSM9DS1 y verifica su correcto funcionamiento.
4. Configura y arranca un timer con una periodicidad de 50 milisegundos.
5. En la interrupción del timer, lee las lecturas del acelerómetro en los ejes X, Y y Z.
6. Formatea las lecturas y las envía por puerto serie en formato CSV.

### `BBTimer.hpp`

Este archivo define la clase `BBTimer` que permite acceder y manejar los cinco timers de 32 bits del nRF52840. La clase proporciona métodos para configurar, iniciar, detener y actualizar el periodo de los timers. El contenido de este archivo es el mismo que en la carpeta `Lectura_ADC_Timers`.

## Uso

1. Abre el archivo `ComunicacionTermite.ino` en el IDE de Arduino.
2. Carga el código en tu Arduino Nano 33 BLE.
3. Asegúrate de que la biblioteca `BBTimer.hpp` esté en la misma carpeta que el archivo `ComunicacionTermite.ino`.
4. Abre Termite o Python para recibir y visualizar los datos enviados por puerto serie.

## Notas

- Asegúrate de que la biblioteca `BBTimer.hpp` esté en la misma carpeta que el archivo `ComunicacionTermite.ino` para que se compile correctamente.
- Este proyecto utiliza el sensor LSM9DS1 para medir los datos del acelerómetro.
