# BLE_ReadAccelerometer

## Descripción
Este directorio contiene el código necesario para conectar un dispositivo a través de Bluetooth Low Energy (BLE) y leer los datos del acelerómetro utilizando características BLE personalizadas. El proyecto está diseñado para funcionar con un Arduino Nano 33 BLE y un sensor LSM9DS1.

## Archivos
- `BLE_ReadAccelerometer.ino`: Archivo principal del proyecto que contiene el código para la conexión BLE y la lectura de los datos del acelerómetro.
- `BBTimer.hpp`: Archivo de cabecera que define la clase `BBTimer` para gestionar los timers del microcontrolador.

## Contenido de `BLE_ReadAccelerometer.ino`
El archivo `BLE_ReadAccelerometer.ino` configura la comunicación BLE, define las características del servicio BLE y proporciona la funcionalidad para leer los datos del acelerómetro y enviarlos a un dispositivo central a través de características BLE.

### Funcionamiento del código
1. Se inicializa la comunicación BLE y se configura el nombre local del dispositivo.
2. Se define un servicio BLE para el acelerómetro y se añaden las características necesarias para las lecturas en los ejes X, Y y Z, así como una característica adicional para enviar los datos en formato de cadena.
3. Se inicializa y arranca un timer para gestionar la periodicidad de las lecturas del acelerómetro.
4. Cuando se establece la conexión BLE con un dispositivo central, se leen los datos del acelerómetro y se envían al dispositivo central a través de las características BLE correspondientes.
5. La lectura de los datos del acelerómetro se realiza a través de la librería Arduino_LSM9DS1.

### Uso
1. Abre el archivo `BLE_ReadAccelerometer.ino` en el IDE de Arduino.
2. Carga el código en tu Arduino Nano 33 BLE.
3. Asegúrate de que la biblioteca `BBTimer.hpp` esté en la misma carpeta que el archivo `BLE_ReadAccelerometer.ino`.
4. Usa una aplicación como nrfConnect para poder comunicarte con el Arduino.

## Notas
- Asegúrate de que la biblioteca `BBTimer.hpp` esté en la misma carpeta que el archivo `BLE_ReadAccelerometer.ino` para que se compile correctamente.
- Este proyecto utiliza el sensor LSM9DS1 para medir los datos del acelerómetro.
