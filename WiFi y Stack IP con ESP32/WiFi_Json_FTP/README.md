# Carpeta WiFi_Json_FTP

## Descripción
Este directorio contiene un proyecto para conectar un dispositivo a una red WiFi y enviar archivos JSON a un servidor FTP. El proyecto está diseñado para funcionar en dispositivos compatibles con Arduino y ESP32.

## Archivos
- `WiFi_Json_FTP.ino`: Archivo principal del proyecto que contiene el código para conectar el dispositivo a la red WiFi, generar archivos JSON y enviarlos al servidor FTP.
- `ESP32_FTPClient.h`: Archivo de cabecera que define la clase `ESP32_FTPClient` utilizada para la comunicación FTP.
- `ESP32_FTPClient.cpp`: Implementación de la clase `ESP32_FTPClient` que proporciona métodos para interactuar con un servidor FTP.

## Contenido de `WiFi_Json_FTP.ino`
El archivo `WiFi_Json_FTP.ino` configura el dispositivo para conectarlo a una red WiFi, generar archivos JSON con datos de temperatura aleatorios y enviarlos al servidor FTP configurado.

### Funcionamiento del código
1. Se inicializa la comunicación serie para la depuración.
2. Se configuran las credenciales de la red WiFi y del servidor FTP.
3. Se conecta el dispositivo a la red WiFi.
4. Se genera un archivo JSON cada 20 segundos con datos de temperatura aleatorios.
5. Se envía el archivo JSON al servidor FTP configurado.

## Clase `ESP32_FTPClient`
La clase `ESP32_FTPClient` proporciona métodos para interactuar con un servidor FTP. Permite realizar operaciones como abrir y cerrar conexión, crear, renombrar y eliminar archivos, y obtener listas de contenidos de directorios.

## Notas
- Este proyecto está diseñado para funcionar en dispositivos compatibles con Arduino y ESP32.
- Asegúrate de tener instalada la biblioteca `ArduinoJson` y la biblioteca ESP32_FTPClient en tu entorno de desarrollo Arduino antes de compilar el código.
- Los archivos JSON se generan con datos de temperatura aleatorios y se envían al servidor FTP configurado cada 20 segundos.
- Se uso un cliente FTP para poder conectarse con el servidor del laboratorio y ver los envíos.