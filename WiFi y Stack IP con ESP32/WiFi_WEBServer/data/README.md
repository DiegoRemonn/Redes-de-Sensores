# data

## Descripción
Este directorio contiene archivos para crear una interfaz web simple que muestra la hora actual y permite reiniciarla a las 00:00:00. El proyecto está diseñado para ser utilizado con un servidor web alojado en un ESP32.

## Archivos
- `index.html`: Archivo HTML principal que define la estructura de la página web y contiene el código JavaScript para mostrar la hora actual y reiniciarla.
- `style.css`: Archivo CSS que define los estilos de la página web.

## Contenido de `index.html`
El archivo `index.html` define la estructura de la página web y contiene código JavaScript para mostrar la hora actual y reiniciarla.

### Funcionamiento del código
1. Se inicializa la fecha al valor actual.
2. Se define una función para restablecer la hora a 00:00:00.
3. Se define una función para mostrar la fecha y hora actual en el HTML.
4. Se actualiza la fecha y hora mostrada cada segundo.

## Contenido de `style.css`
El archivo `style.css` define los estilos de la página web.

### Estilos definidos
- Se utiliza la fuente Helvetica para el texto.
- Se centra el contenido de la página.
- Se define el color y el tamaño del texto del encabezado `<h1>` y del párrafo `<p>`.
- Se define el estilo del botón.

## Notas
- Este proyecto está diseñado para ser utilizado con un servidor web alojado en un ESP32.
- Asegúrate de cargar estos archivos en el sistema de archivos del ESP32 correctamente para que puedan ser servidos por el servidor web.
