# Escritura_PWM

Este proyecto es una práctica sobre la generación de señales PWM (Modulación por Ancho de Pulso) en el Arduino Nano 33 BLE. Utiliza un timer para realizar lecturas periódicas del ADC y ajustar el ciclo de trabajo del PWM en función del valor leído.

## Archivos

- `Escritura_PWM.ino`: Archivo principal del proyecto que contiene el código fuente.
- `BBTimer.hpp`: Archivo de cabecera que define la clase `BBTimer` para gestionar los timers del microcontrolador.

## Descripción del Código

### `Escritura_PWM.ino`

Este archivo configura y utiliza un timer para realizar lecturas periódicas del ADC y ajustar el ciclo de trabajo del PWM. El código realiza las siguientes funciones:

1. Inicializa el puerto serie a una velocidad de 9600 baudios.
2. Configura un timer para llamar a una función de devolución de llamada cada 0.1 segundos.
3. Lee el valor del pin analógico A0 cuando el timer indica que es momento de hacerlo.
4. Convierte el valor leído (un número entre 0 y 1023) a voltaje (de 0 a 3.3V).
5. Ajusta el ciclo de trabajo del PWM en función del voltaje leído.
6. Imprime el valor del voltaje en el puerto serie.

### `BBTimer.hpp`

Este archivo define la clase `BBTimer` que permite acceder y manejar los cinco timers de 32 bits del nRF52840. La clase proporciona métodos para configurar, iniciar, detener y actualizar el periodo de los timers. El contenido de este archivo es el mismo que en la carpeta `Lectura_ADC_Timers`.
