# WiFi_Subscribe_MQTT

## Descripción
Este directorio contiene un proyecto para conectar un dispositivo ESP32 a una red WiFi y suscribirse a un servidor de Adafruit mediante MQTT para recibir datos. El proyecto está diseñado para funcionar con placas basadas en ESP32 y utiliza la biblioteca `Adafruit_MQTT` para la comunicación MQTT.

## Archivos
- `WiFi_Subscribe_MQTT.ino`: Archivo principal del proyecto que contiene el código para conectarse a la red WiFi y suscribirse a un feed de Adafruit IO mediante MQTT.
- `config.h`: Archivo de configuración que contiene las credenciales de Adafruit IO y las características de la red WiFi.

## Contenido de `WiFi_Subscribe_MQTT.ino`
El archivo `WiFi_Subscribe_MQTT.ino` configura la conexión WiFi y la suscripción MQTT para recibir datos de un feed de Adafruit IO.

### Funcionamiento del código
1. Se incluye el archivo de configuración `config.h`, que contiene las credenciales de Adafruit IO y las características de la red WiFi.
2. Se inicializa la conexión WiFi.
3. Se conecta al servidor MQTT de Adafruit.
4. Se configura una función de callback para manejar los mensajes entrantes del feed.
5. En el bucle principal, se procesan los mensajes y se mantiene la conexión.

### Uso
1. Abre el archivo `WiFi_Subscribe_MQTT.ino` en el IDE de Arduino.
2. Configura las credenciales de tu red WiFi y los detalles de tu cuenta de Adafruit IO en el archivo `config.h`.
3. Carga el código en tu placa basada en ESP32.
4. El dispositivo se conectará a la red WiFi y comenzará a recibir datos del feed de Adafruit IO especificado.

## Contenido de `config.h`
El archivo `config.h` contiene las credenciales de Adafruit IO y las características de la red WiFi.

### Uso
1. Abre el archivo `config.h` en un editor de texto.
2. Completa las credenciales de tu cuenta de Adafruit IO y las características de tu red WiFi.
3. Guarda los cambios en el archivo.

## Notas
- Este proyecto está diseñado para funcionar con placas basadas en ESP32.
- Asegúrate de que la configuración de WiFi y Adafruit IO esté correctamente configurada en el archivo `config.h`.

