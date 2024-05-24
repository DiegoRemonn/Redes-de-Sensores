# RTOS_Random_1s

## Descripción
Este directorio contiene un programa para Arduino Nano 33 BLE que implementa un sistema operativo en tiempo real (RTOS) utilizando el framework FreeRTOS. El programa realiza tres tareas simultáneas: una tarea toma muestras aleatorias cada 100 ms, otra tarea muestra las muestras cada 1 segundo por el puerto serie y una tercera tarea enciende un LED durante 200 ms después de mostrar las muestras.

## Archivo RTOS_Random_1s.ino
- **RTOS_Random_1s.ino:** Este archivo contiene el código principal del programa. Se inicializan el puerto serie, el pin del LED y la semilla para la generación de números aleatorios. Luego se crean las tres tareas y se ejecuta un bucle infinito.

## Funciones
- **void Tarea1(void *parameter):** Esta función representa la primera tarea del programa. Toma muestras aleatorias cada 100 ms y las almacena en un arreglo.
- **void Tarea2(void *parameter):** Esta función representa la segunda tarea del programa. Muestra las muestras almacenadas cada 1 segundo por el puerto serie.
- **void Tarea3(void *parameter):** Esta función representa la tercera tarea del programa. Enciende el LED durante 200 ms después de que la segunda tarea haya mostrado las muestras.

## Notas
- El programa utiliza el framework FreeRTOS para implementar un sistema multitarea en el microcontrolador Arduino Nano 33 BLE.
- Las tres tareas se ejecutan simultáneamente, lo que permite realizar acciones independientes de forma concurrente.
- La implementación de tareas en un entorno RTOS puede mejorar la eficiencia y la capacidad de respuesta del sistema en aplicaciones en las que se requiera realizar múltiples acciones de forma simultánea.
