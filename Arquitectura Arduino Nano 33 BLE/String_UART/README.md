# String_UART

Lectura del ADC y escritura de PWM en el Arduino Nano 33 BLE, controlando el comportamiento del dispositivo a través de comandos enviados por UART mediante cadenas de texto (Strings).

## Archivos

- `String_UART.ino`: Archivo principal del proyecto que contiene el código fuente.
- `BBTimer.hpp`: Archivo de cabecera que define la clase `BBTimer` para gestionar los timers del microcontrolador.

## Descripción del Código

### `String_UART.ino`

Este archivo configura y utiliza un timer para realizar lecturas periódicas del ADC y ajustar el ciclo de trabajo del PWM en función del valor leído. Además, permite modificar la frecuencia del timer y el ciclo de trabajo del PWM mediante comandos enviados a través de UART. El código realiza las siguientes funciones:

1. Inicializa el puerto serie a una velocidad de 9600 baudios.
2. Configura un timer para llamar a una función de devolución de llamada cada 1 segundo.
3. Lee comandos del puerto serie para ajustar el comportamiento del ADC y el PWM.
4. Permite los siguientes comandos:
   - `ADC`: Lee el valor del pin analógico A0 y lo muestra en el puerto serie.
   - `ADC(x)`: Configura el timer para leer el ADC cada `x` segundos.
   - `PWM(y)`: Ajusta el ciclo de trabajo del PWM al valor `y` (de 0 a 9).

### `BBTimer.hpp`

Este archivo define la clase `BBTimer` que permite acceder y manejar los cinco timers de 32 bits del nRF52840. La clase proporciona métodos para configurar, iniciar, detener y actualizar el periodo de los timers. El contenido de este archivo es el mismo que en la carpeta `Lectura_ADC_Timers`.
