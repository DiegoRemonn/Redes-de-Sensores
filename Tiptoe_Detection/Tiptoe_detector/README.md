# Tiptoe_detector

## Descripción
Este directorio contiene un proyecto para detectar el movimiento de puntillas (tiptoe) utilizando un sensor LSM9DS1 y enviar los datos a través de comunicación BLE (Bluetooth Low Energy). El proyecto fue creado por Ignacio Latre y Diego Remón.

## Archivos
- `Tiptoe_detector.ino`: Archivo principal del proyecto que contiene el código para la detección del movimiento de puntillas y el envío de datos mediante BLE.
- `BBTimer.hpp`: Archivo de cabecera que contiene una clase para acceder a los temporizadores de hardware nRF52840.

## Contenido de `Tiptoe_detector.ino`
El archivo `Tiptoe_detector.ino` configura el sensor LSM9DS1 y utiliza BLE para enviar los datos de detección de puntillas.

### Funcionamiento del código
1. Se incluyen las bibliotecas necesarias.
2. Se definen las variables y constantes utilizadas en el proyecto.
3. Se definen los servicios y características BLE personalizadas.
4. Se inicializa el sensor LSM9DS1 y se configura BLE.
5. Se establece un temporizador para controlar el envío periódico de datos.
6. Se implementa un bucle principal que:
   - Escucha las conexiones BLE.
   - Detecta el inicio y la finalización del movimiento de puntillas.
   - Calcula y envía los datos de ángulos y tiempos a través de BLE.

### Uso
1. Abre el archivo `Tiptoe_detector.ino` en el IDE de Arduino.
2. Carga el código en tu placa compatible con el sensor LSM9DS1 y BLE.
3. Utiliza un dispositivo con capacidad BLE para conectarte al proyecto y recibir los datos de detección de puntillas.

## Contenido de `BBTimer.hpp`
El archivo `BBTimer.hpp` contiene una clase para acceder a los temporizadores de hardware nRF52840.

### Funcionamiento de `BBTimer.hpp`
El archivo define la clase `BBTimer` que permite configurar y utilizar los temporizadores de hardware nRF52840 para generar interrupciones periódicas.

### Uso
1. Incluye el archivo `BBTimer.hpp` en tu proyecto.
2. Crea instancias de la clase `BBTimer` para acceder a los temporizadores de hardware.
3. Utiliza los métodos de la clase para configurar y controlar los temporizadores según sea necesario.

