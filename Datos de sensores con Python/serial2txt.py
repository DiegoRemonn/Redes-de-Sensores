'''
Script lectura del puerto serie mediante codigo python
Escritura en archivo .txt de los datos obtenidos
Created by Diego Remón
https://github.com/DiegoRemonn/Redes-de-Sensores
'''
# Declaración de las librerias
import serial
import sys

def main(args):
    # Se inicia una instancia del puerto serie
    puerto = serial.Serial('COM5', 9600)
    
    try:
        # Apertura y escritura de una línea de prueba en un archivo .txt
        with open('prueba.txt', 'w') as f:
            f.write('Archivo generado adecuadamente\n')
        
        # Apertura y escritura de una línea de inicio de datos del sensor en .txt
        with open('datos.txt', 'w') as f:
            f.write("x;y;z\n")
        
        i = 0
        # Escribo datos en el archivo .txt mientras el número de datos sea < 100
        while i < 100:
            # Comprueba que hay datos en el puerto serie
            if puerto.in_waiting > 0:
                # Convierto datos de entrada a cadena de texto y elimino espacios
                line = puerto.readline().decode('utf-8').rstrip()
                print(line)
                # Escritura de una línea de datos leidos en archivo .txt y separo con ';'
                with open('datos.txt', 'a') as f:
                    f.write(line.replace(', ', ';') + '\n')
                i += 1
        print("Escritura finalizada con exito.")
        # Cierro puerto serie al tener los 100 datos escritos en el archivo .txt
        puerto.close()
    
    except KeyboardInterrupt:
        # Finalizar con comando Ctrl+C para cerrar adecuadamente el puerto serie
        puerto.close()
        print("Comunicacion finalizada.")

# Ejecución de la función principal "main" al ejecutar el código
if __name__ == '__main__':
    main(sys.argv)