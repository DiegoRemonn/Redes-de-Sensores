# WiFi_NTP

## Descripción
Este directorio contiene un proyecto para conectar un dispositivo ESP32 a una red WiFi y sincronizar el módulo con la hora local utilizando un servidor NTP. El proyecto está diseñado para funcionar con placas basadas en ESP32 y utiliza un temporizador para mostrar la hora actual cada segundo.

## Archivos
- `WiFi_NTP.ino`: Archivo principal del proyecto que contiene el código para conectarse a la red WiFi, sincronizarse con un servidor NTP y mostrar la hora local.

## Contenido de `WiFi_NTP.ino`
El archivo `WiFi_NTP.ino` configura la conexión WiFi y la sincronización de tiempo mediante un servidor NTP. Además, utiliza un temporizador para mostrar la hora local cada segundo.

### Funcionamiento del código
1. Se configuran las credenciales de la red WiFi.
2. Se configuran los parámetros del servidor NTP.
3. Se inicializa la conexión WiFi y se sincroniza con el servidor NTP.
4. Se inicializa un temporizador para ejecutar una interrupción cada segundo.
5. En la rutina de interrupción, se actualiza y muestra la hora local obtenida del servidor NTP.

### Uso
1. Abre el archivo `WiFi_NTP.ino` en el IDE de Arduino.
2. Configura las credenciales de tu red WiFi y el servidor NTP.
3. Carga el código en tu placa basada en ESP32.
4. El dispositivo se conectará a la red WiFi y sincronizará la hora con el servidor NTP, mostrando la hora local cada segundo en el puerto serie.

## Notas
- Este proyecto está diseñado para funcionar con placas basadas en ESP32.
- Asegúrate de que la configuración de WiFi y NTP esté correctamente configurada en el código.
