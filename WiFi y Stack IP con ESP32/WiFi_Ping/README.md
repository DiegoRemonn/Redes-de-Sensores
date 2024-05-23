# WiFi_Ping

## Descripción
Este directorio contiene un proyecto para conectar un dispositivo ESP32 a una red WiFi y verificar la conectividad a Internet mediante un ping a Google. El proyecto está diseñado para funcionar con placas basadas en ESP32 y utiliza la biblioteca `ESPping` para realizar los pings.

## Archivos
- `WiFi_Ping.ino`: Archivo principal del proyecto que contiene el código para conectarse a la red WiFi y realizar pings a Google para comprobar la conectividad.

## Contenido de `WiFi_Ping.ino`
El archivo `WiFi_Ping.ino` configura la conexión WiFi y realiza pings a Google para verificar la conectividad a Internet.

### Funcionamiento del código
1. Se configuran las credenciales de la red WiFi.
2. Se inicializa la conexión WiFi.
3. Se espera hasta que la conexión WiFi sea exitosa y se muestra la dirección IP asignada al dispositivo.
4. En el bucle principal, se realiza un ping a Google cada 5 segundos si la conexión WiFi es correcta.
5. Se muestra un mensaje en el puerto serie indicando si el ping fue exitoso o fallido.

### Uso
1. Abre el archivo `WiFi_Ping.ino` en el IDE de Arduino.
2. Configura las credenciales de tu red WiFi.
3. Carga el código en tu placa basada en ESP32.
4. El dispositivo se conectará a la red WiFi y comenzará a realizar pings a Google para comprobar la conectividad.

## Notas
- Este proyecto está diseñado para funcionar con placas basadas en ESP32.
- Asegúrate de que la configuración de WiFi esté correctamente configurada en el código.
- El ESP32 realizará pings a Google cada 5 segundos para verificar la conectividad a Internet.
