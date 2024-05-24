# RTOS_Random_LE

## Descripción
Este directorio contiene un programa para Arduino Nano 33 BLE que implementa un sistema operativo en tiempo real (RTOS) utilizando el framework FreeRTOS. El programa es similar al de la carpeta RTOS_Random_1s, pero incluye una función de callback de FreeRTOS para manejar el modo de bajo consumo cuando no hay tareas en ejecución.

## Archivo RTOS_Random_LE.ino
- **RTOS_Random_LE.ino:** Este archivo contiene el código principal del programa. Se inicializan el puerto serie, el pin del LED y la semilla para la generación de números aleatorios. Luego se crean las tres tareas y se ejecuta un bucle infinito. Además, se define una función de callback (`myIdleHook`) para manejar el modo de bajo consumo cuando no hay tareas en ejecución.

## Funciones
- **void Tarea1(void *parameter):** Esta función representa la primera tarea del programa. Toma muestras aleatorias cada 100 ms y las almacena en un arreglo.
- **void Tarea2(void *parameter):** Esta función representa la segunda tarea del programa. Muestra las muestras almacenadas cada 1 segundo por el puerto serie.
- **void Tarea3(void *parameter):** Esta función representa la tercera tarea del programa. Enciende el LED durante 200 ms después de que la segunda tarea haya mostrado las muestras.
- **void myIdleHook():** Esta función es una callback de FreeRTOS que se llama cuando no hay tareas en ejecución. Coloca el microcontrolador en modo de bajo consumo para ahorrar energía.

## Notas
- La función `esp_pm_configure()` se utiliza para configurar el modo de bajo consumo del microcontrolador cuando no hay tareas en ejecución, lo que puede ser útil para ahorrar energía en aplicaciones con requisitos de consumo de energía estrictos.
- El uso de callbacks de FreeRTOS permite personalizar el comportamiento del sistema operativo en tiempo real para adaptarse a las necesidades específicas de la aplicación.
