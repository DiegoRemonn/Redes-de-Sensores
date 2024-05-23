# Words Classification

Este directorio contiene el código necesario para la clasificación de palabras utilizando el Arduino Nano 33 BLE y las librerías obtenidas de Edge Impulse.

## Archivos

- `wordsClassification.ino`: Archivo principal del proyecto que contiene el código fuente.

## Descripción del Código

### `wordsClassification.ino`

Este archivo contiene el código necesario para la clasificación de palabras utilizando el Arduino Nano 33 BLE y las librerías obtenidas de Edge Impulse. El código realiza las siguientes funciones:

1. Configuración inicial del puerto serie a una velocidad de 115200 baudios.
2. Inicialización del proceso de inferencia utilizando el modelo generado por Edge Impulse.
3. Configuración y ejecución del proceso de clasificación de palabras.
4. Muestra por el puerto serie las predicciones obtenidas durante el proceso de clasificación.

## Uso

1. Conecta el Arduino Nano 33 BLE a tu computadora.
2. Sube el código `wordsClassification.ino` al dispositivo.
3. Abre el monitor serie en el IDE de Arduino a 115200 baudios para visualizar las predicciones de palabras.