# Lectura_ADC

Lectura del ADC (Convertidor Analógico a Digital) en el Arduino Nano 33 BLE. Se realiza una lectura de un sensor conectado al pin analógico A0, se convierte el valor leído a voltaje y se muestra el resultado en el puerto serie.

## Archivos

- `Lectura_ADC.ino`: Archivo principal del proyecto que contiene el código fuente.

## Descripción del Código

El código `Lectura_ADC.ino` realiza las siguientes funciones:

1. Inicializa el puerto serie a una velocidad de 9600 baudios.
2. Lee el valor del pin analógico A0.
3. Convierte el valor leído (un número entre 0 y 1023) a voltaje (de 0 a 3.3V).
4. Imprime el valor del voltaje en el puerto serie.
5. Espera 1 segundo y repite el proceso.

