# BLE_ActivateAccelerometer

## Descripción
Este directorio contiene el código necesario para conectar un dispositivo a través de Bluetooth Low Energy (BLE) y activar o desactivar la lectura del acelerómetro mediante una característica BLE personalizada. El proyecto está diseñado para funcionar con un Arduino Nano 33 BLE y un sensor LSM9DS1.

## Archivos
- `BLE_ActivateAccelerometer.ino`: Archivo principal del proyecto que contiene el código para la conexión BLE y la activación/desactivación de la lectura del acelerómetro.
- `BBTimer.hpp`: Archivo de cabecera que define la clase `BBTimer` para gestionar los timers del microcontrolador.

## Contenido de `BLE_ActivateAccelerometer.ino`
El archivo `BLE_ActivateAccelerometer.ino` configura la comunicación BLE, define las características del servicio BLE y proporciona la funcionalidad para activar o desactivar la lectura del acelerómetro mediante una característica BLE personalizada. 

### Funcionamiento del código
1. Se inicializa la comunicación BLE y se configura el nombre local del dispositivo.
2. Se define un servicio BLE para el acelerómetro y se añaden las características necesarias, incluida una característica para activar o desactivar el sensor.
3. Se inicializa y arranca un timer para gestionar la periodicidad de las lecturas del acelerómetro.
4. Cuando se activa la conexión BLE con un dispositivo central, se lee el estado de la característica de activación del acelerómetro.
5. Si la activación del acelerómetro está habilitada, se leen los datos del sensor y se envían al dispositivo central a través de las características BLE correspondientes.
6. Si se recibe un comando para cambiar el estado de la activación del acelerómetro, se actualiza el valor y se actúa en consecuencia.

### Uso
1. Abre el archivo `BLE_ActivateAccelerometer.ino` en el IDE de Arduino.
2. Carga el código en tu Arduino Nano 33 BLE.
3. Asegúrate de que la biblioteca `BBTimer.hpp` esté en la misma carpeta que el archivo `BLE_ActivateAccelerometer.ino`.
4. Usa una aplicación como nrfConnect para poder comunicarte con el Arduino.

## Notas
- Asegúrate de que la biblioteca `BBTimer.hpp` esté en la misma carpeta que el archivo `BLE_ActivateAccelerometer.ino` para que se compile correctamente.
- Este proyecto utiliza el sensor LSM9DS1 para medir los datos del acelerómetro.
