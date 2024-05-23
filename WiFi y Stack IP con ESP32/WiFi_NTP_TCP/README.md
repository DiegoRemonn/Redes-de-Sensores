# WiFi_NTP_TCP

## Descripción
Este directorio contiene un proyecto para conectar un dispositivo ESP32 a una red WiFi y a un servidor TCP, enviando la hora local al servidor mediante la comunicación TCP. El proyecto está diseñado para funcionar con placas basadas en ESP32 y utiliza un temporizador para enviar la hora actual cada segundo.

## Archivos
- `WiFi_NTP_TCP.ino`: Archivo principal del proyecto que contiene el código para conectarse a la red WiFi, sincronizarse con un servidor NTP, y enviar la hora local a un servidor TCP.

## Contenido de `WiFi_NTP_TCP.ino`
El archivo `WiFi_NTP_TCP.ino` configura la conexión WiFi, la sincronización de tiempo mediante un servidor NTP, y la comunicación con un servidor TCP para enviar la hora local.

### Funcionamiento del código
1. Se configuran las credenciales de la red WiFi y del servidor TCP.
2. Se configuran los parámetros del servidor NTP.
3. Se inicializa la conexión WiFi y se sincroniza con el servidor NTP.
4. Se inicializa un temporizador para ejecutar una interrupción cada segundo.
5. En la rutina de interrupción, se actualiza y envía la hora local al servidor TCP.

### Uso
1. Abre el archivo `WiFi_NTP_TCP.ino` en el IDE de Arduino.
2. Configura las credenciales de tu red WiFi, el servidor NTP y el servidor TCP.
3. Carga el código en tu placa basada en ESP32.
4. El dispositivo se conectará a la red WiFi, sincronizará la hora con el servidor NTP y enviará la hora local al servidor TCP cada segundo.

## Notas
- Este proyecto está diseñado para funcionar con placas basadas en ESP32.
- Asegúrate de que la configuración de WiFi, NTP y el servidor TCP esté correctamente configurada en el código.
