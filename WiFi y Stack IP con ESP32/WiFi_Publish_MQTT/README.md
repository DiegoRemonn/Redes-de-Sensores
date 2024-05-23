# WiFi_Publish_MQTT

## Descripción
Este directorio contiene un proyecto para conectar un dispositivo ESP32 a una red WiFi y enviar datos a un feed de Adafruit mediante el protocolo MQTT. El proyecto está diseñado para funcionar con placas basadas en ESP32 y utiliza la biblioteca `Adafruit_MQTT` para la comunicación MQTT.

## Archivos
- `WiFi_Publish_MQTT.ino`: Archivo principal del proyecto que contiene el código para conectarse a la red WiFi y enviar datos a un feed de Adafruit IO mediante MQTT.

## Contenido de `WiFi_Publish_MQTT.ino`
El archivo `WiFi_Publish_MQTT.ino` configura la conexión WiFi y la conexión MQTT para enviar datos a un feed de Adafruit IO.

### Funcionamiento del código
1. Se configuran las credenciales de la red WiFi y el servidor MQTT.
2. Se inicializa la conexión WiFi.
3. Se conecta al servidor MQTT de Adafruit.
4. En el bucle principal, se asegura de que la conexión MQTT esté activa y publica valores aleatorios en un feed de Adafruit cada 10 segundos.

### Uso
1. Abre el archivo `WiFi_Publish_MQTT.ino` en el IDE de Arduino.
2. Configura las credenciales de tu red WiFi y los detalles de tu cuenta de Adafruit IO.
3. Carga el código en tu placa basada en ESP32.
4. El dispositivo se conectará a la red WiFi y comenzará a enviar datos aleatorios al feed de Adafruit IO especificado.
