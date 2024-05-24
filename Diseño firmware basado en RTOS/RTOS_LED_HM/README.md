# RTOS_LED_HM

## Descripción
Este directorio contiene un programa para Arduino Nano 33 BLE que implementa un sistema operativo en tiempo real (RTOS) utilizando el framework FreeRTOS. El programa consta de dos tareas: una tarea enciende y apaga un LED cada 200 ms, mientras que la otra tarea envía "Hola Mundo" por el puerto serie cada 1 segundo.

## Archivo .ino
- **RTOS_LED_HM.ino:** Este archivo contiene el código principal del programa. Se inicializan el puerto serie y el pin del LED, se crean las dos tareas y se ejecuta un bucle infinito.

## Funciones
- **void Tarea1(void *parameter):** Esta función representa la primera tarea del programa. Envía el mensaje "Hola mundo" por el puerto serie cada 1 segundo.
- **void Tarea2(void *parameter):** Esta función representa la segunda tarea del programa. Enciende y apaga el LED cada 200 ms.

## Notas
- El programa utiliza el framework FreeRTOS para implementar un sistema multitarea en el microcontrolador Arduino Nano 33 BLE.
- La implementación de tareas permite ejecutar múltiples acciones de forma concurrente, lo que puede mejorar la eficiencia y la capacidad de respuesta del sistema en aplicaciones complejas.
- Este ejemplo muestra cómo utilizar el RTOS para realizar tareas concurrentes en un entorno de desarrollo basado en Arduino.
