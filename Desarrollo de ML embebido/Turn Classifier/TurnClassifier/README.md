# Turn Classifier

Este directorio contiene los recursos necesarios para el proyecto "Turn Classifier", que utiliza el Arduino Nano 33 BLE para detectar giros.

## Archivo

### `TurnClassifier.ino`

Este archivo contiene el código principal del proyecto.

## Contenido del Archivo

El archivo `TurnClassifier.ino` configura y ejecuta el clasificador de Edge Impulse en segundo plano para detectar giros utilizando los datos del giroscopio del Arduino Nano 33 BLE. El código realiza las siguientes funciones:

1. Inicializa el puerto serie a una velocidad de 115200 baudios.
2. Inicializa el sensor inercial LSM9DS1 y verifica su correcto funcionamiento.
3. Ejecuta el clasificador en segundo plano para detectar giros continuamente.
4. Muestra por el puerto serie las predicciones de giros clasificadas.
5. Controla un LED RGB para cada clase de giro detectada.

## Uso

1. Abre el archivo `TurnClassifier.ino` en el IDE de Arduino.
2. Carga el código en tu Arduino Nano 33 BLE.
3. Abre el monitor serie en el IDE de Arduino a 115200 baudios para visualizar las predicciones de giros.

## Notas

- Asegúrate de que las librerías `DiegoRemon_AccelerometerArduino_inferencing` y `Arduino_LSM9DS1` estén instaladas en tu entorno de Arduino para la correcta ejecución del código.
- Este proyecto utiliza el giroscopio del sensor LSM9DS1 para detectar giros.