# Acelerometro

Este directorio contiene el código para leer y procesar datos del acelerómetro integrado en el Arduino Nano 33 BLE.

## Archivos

- `Acelerometro.ino`: Archivo principal del proyecto que contiene el código fuente.
- `BBTimer.hpp`: Archivo de cabecera que define la clase `BBTimer`.

## Descripción del Código

### `Acelerometro.ino`

Este archivo configura y utiliza un temporizador para realizar lecturas periódicas del acelerómetro. El código realiza las siguientes funciones:

1. Inicializa el puerto serie a una velocidad de 9600 baudios.
2. Inicializa el sensor IMU (Unidad de Medición Inercial) y verifica su correcto funcionamiento.
3. Configura un temporizador para llamar a una función de devolución de llamada cada 0.1 segundos.
4. Lee los valores del acelerómetro y los almacena en una matriz.
5. Muestra los valores leídos por el puerto serie cada 1 segundo.

### Funciones Principales

- `setup()`: Configura la comunicación serie, inicializa el sensor IMU y configura el temporizador.
- `loop()`: Lee los valores del acelerómetro y los almacena en una matriz, muestra los valores cada 1 segundo.
- `t3Callback()`: Función de devolución de llamada del temporizador que actualiza un contador y establece una bandera para indicar que se deben leer los valores del acelerómetro.
- `dtostrf()`: Convierte un valor flotante en una cadena de caracteres.
- `inclinadoArriba()`, `inclinadoAbajo()`, `inclinadoIzquierda()`, `inclinadoDerecha()`: Funciones para determinar la inclinación del dispositivo.

### `BBTimer.hpp`

Este archivo define la clase `BBTimer` que permite acceder y manejar los cinco timers de 32 bits del nRF52840. La clase proporciona métodos para configurar, iniciar, detener y actualizar el periodo de los timers. El contenido de este archivo es el mismo que en la carpeta `Lectura_ADC_Timers`.

## Uso

1. Conecta el Arduino Nano 33 BLE a tu computadora.
2. Sube el código `Acelerometro.ino` al dispositivo.
3. Abre el monitor serie en el IDE de Arduino a 9600 baudios para ver los datos del acelerómetro.
