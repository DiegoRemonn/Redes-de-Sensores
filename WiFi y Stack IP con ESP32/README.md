# WiFi y Stack IP con ESP32

## Descripción
Este directorio contiene varios proyectos relacionados con la conexión a redes WiFi y el uso de diferentes protocolos de comunicación en un ESP32, como TCP, JSON, NTP, MQTT y HTTP.

## Subdirectorios

### WiFi_ESP32_TCP
- Contiene un proyecto que establece una conexión TCP con un servidor utilizando un ESP32.

### WiFi_Json
- Contiene un proyecto que utiliza el formato JSON para intercambiar datos entre un ESP32 y un servidor.

### WiFi_Json_FTP
- Contiene un proyecto que utiliza JSON para enviar datos a un servidor y utiliza FTP para la transferencia de archivos.

### WiFi_NTP
- Contiene un proyecto que sincroniza el tiempo del ESP32 con un servidor NTP.

### WiFi_NTP_TCP
- Contiene un proyecto que sincroniza el tiempo del ESP32 con un servidor NTP y envía la hora a través de TCP.

### WiFi_NTP_TCP_OnOff
- Contiene un proyecto similar al anterior, pero con la capacidad de activar o desactivar el envío de la hora mediante un mensaje TCP.

### WiFi_Ping
- Contiene un proyecto que realiza un ping a un servidor para comprobar la conectividad.

### WiFi_Subscribe_MQTT
- Contiene un proyecto que se suscribe a un servidor MQTT para recibir datos.

### WiFi_Publish_MQTT
- Contiene un proyecto que publica datos en un servidor MQTT.

### WiFi_WEBServer
- Contiene un proyecto que establece un servidor web en el ESP32 para mostrar la hora actual y permitir el restablecimiento de la hora.

## Notas
- Cada subdirectorio contiene un proyecto independiente con su propio archivo .ino y, posiblemente, otros archivos necesarios.
- Los proyectos abarcan una variedad de aplicaciones, desde la sincronización de la hora hasta la comunicación con servidores utilizando diferentes protocolos.
- Cada proyecto puede ser útil para diferentes aplicaciones y escenarios de IoT.
