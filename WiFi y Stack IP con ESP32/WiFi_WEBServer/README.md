# WiFi_WEBServer

## Descripción
Este directorio contiene archivos y código necesarios para crear un servidor web en un ESP32 que muestra la hora actual y proporciona un botón para restablecer la hora a 00:00.

## Archivos
- `WiFi_WEBServer.ino`: Archivo principal que contiene el código para configurar el servidor web, conectar a la red WiFi, inicializar SPIFFS para servir archivos estáticos y definir las rutas de las solicitudes HTTP.
- `data`: Contiene archivos estáticos como `index.html` y `style.css`.

## Contenido de `WiFi_WEBServer.ino`
El archivo `WiFi_WEBServer.ino` contiene el código principal para configurar el servidor web, manejar las solicitudes HTTP y controlar el reinicio de la hora.

### Funcionamiento del código
1. Se importan las librerías necesarias: `WiFi.h`, `ESPAsyncWebServer.h` y `SPIFFS.h`.
2. Se definen las características de la red WiFi, como el SSID y la contraseña.
3. Se configura un servidor web AsyncWebServer en el puerto 80.
4. Se inicializa SPIFFS para servir archivos estáticos.
5. Se configura una ruta para servir la página principal (`/index.html`) que muestra la hora actual y proporciona un botón para restablecer la hora.
6. Se configura una ruta para servir el archivo de estilos (`/style.css`).
7. Se configura una ruta para el reinicio de la hora (`/RESTART`).
8. El servidor comienza a escuchar en el puerto 80.
9. En el bucle principal `loop()`, el código está vacío ya que la funcionalidad principal se maneja en las devoluciones de llamada de las rutas del servidor.

## Carpeta `data`
La carpeta `data` contiene archivos estáticos como `index.html` y `style.css`, que son servidos por el servidor web.

### Archivo `index.html`
El archivo `index.html` define la estructura de la página web y contiene un script JavaScript para mostrar la hora actual y un botón para restablecer la hora.

### Archivo `style.css`
El archivo `style.css` define los estilos CSS para la página web.

## Notas
- Asegúrate de cargar los archivos de la carpeta `data` en el sistema de archivos SPIFFS del ESP32 para que puedan ser servidos por el servidor web.
- La hora actual se actualiza automáticamente en la página web, y el botón "Reset Time" permite restablecer la hora a 00:00.
