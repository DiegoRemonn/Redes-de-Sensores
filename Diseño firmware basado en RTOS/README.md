# Diseño firmware basado en RTOS

## Descripción
Este directorio contiene varios programas  que implementan un sistema operativo en tiempo real (RTOS) utilizando el framework FreeRTOS. Cada subcarpeta contiene un programa diferente con funcionalidades específicas.

## Subcarpeta RTOS_LED_HM
Esta subcarpeta contiene un programa que implementa dos tareas: una tarea que enciende y apaga un LED cada 200 ms y otra tarea que envía "Hola Mundo" por el puerto serie cada segundo.

## Subcarpeta RTOS_Random_1s
Esta subcarpeta contiene un programa que toma muestras aleatorias cada 100 ms, las muestra por el puerto serie cada segundo y enciende un LED durante 200 ms después de mostrar las muestras.

## Subcarpeta RTOS_Random_LE
Esta subcarpeta contiene un programa similar al de RTOS_Random_1s, pero incluye una función de callback de FreeRTOS para manejar el modo de bajo consumo cuando no hay tareas en ejecución.

## Notas
- Los programas en estas subcarpetas están diseñados para mostrar cómo implementar un sistema operativo en tiempo real en ESP32 utilizando FreeRTOS.
- Cada programa utiliza múltiples tareas para realizar tareas concurrentes de manera eficiente.
- Se proporcionan diferentes ejemplos para ilustrar diferentes funcionalidades y técnicas de programación con RTOS.
