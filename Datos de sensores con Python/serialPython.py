'''
Script lectura del puerto serie mediante codigo python
Created by Diego Remón
https://github.com/DiegoRemonn/Redes-de-Sensores
'''
# Declaración de las librerias
import serial
import sys

def main(args):
    # Se inicia una instancia del puerto serie
    puerto = serial.Serial('COM10', 9600)
    
    try:
        while True:
            # Comprueba que hay datos en el puerto serie
            if puerto.in_waiting > 0:
                # Convierto datos de entrada a cadena de texto y elimino espacios
                line = puerto.readline().decode('utf-8').rstrip()
                print(line)
    
    except KeyboardInterrupt:
        # Finalizar con comando Ctrl+C para cerrar adecuadamente el puerto serie
        puerto.close()
        print("Comunicacion finalizada.")

# Ejecución de la función principal "main" al ejecutar el código
if __name__ == '__main__':
    main(sys.argv)