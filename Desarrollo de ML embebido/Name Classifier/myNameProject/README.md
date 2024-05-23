# myNameProject

Este directorio contiene los recursos necesarios para el proyecto "myNameProject" que utiliza el Arduino Nano 33 BLE y las librerías obtenidas de Edge Impulse para la clasificación de nombres.

## Archivos

- `myNameProject.ino`: Archivo principal del proyecto que contiene el código fuente.

## Descripción del Código

### `myNameProject.ino`

Este archivo configura y utiliza un temporizador para realizar inferencias continuas de audio y clasificar nombres utilizando el modelo entrenado en Edge Impulse. El código realiza las siguientes funciones:

1. Inicializa el puerto serie a una velocidad de 115200 baudios.
2. Inicializa la ejecución del clasificador de Edge Impulse.
3. Configura el sensor de micrófono y verifica su correcto funcionamiento.
4. Realiza inferencias continuas del audio capturado por el micrófono.
5. Muestra por el puerto serie las predicciones de nombre clasificadas.

## Uso

1. Conecta el Arduino Nano 33 BLE a tu computadora.
2. Carga el código `myNameProject.ino` en el dispositivo.
3. Abre el monitor serie en el IDE de Arduino a 115200 baudios para visualizar las predicciones de nombres.

## Notas

- Asegúrate de que la carpeta `DiegoRemon_MyNameProject_2_inferencing` esté presente en el directorio de librerías de Arduino para la correcta ejecución del código.