'''
Script lectura del puerto serie mediante codigo python
Escritura en archivo .txt de los datos obtenidos
Dibujo del promedio y desviación estándar de los datos recibidos cada 5 segundos
Created by Diego Remón
https://github.com/DiegoRemonn/Redes-de-Sensores
'''
# Declaración de las librerias
import serial
import sys
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

''' Declaración de variables globales '''
num_datos = 100
cont = 0
contador = 0
resultados_prom = [0]*3
resultados_desv = [0]*3
fig1, ax1 = plt.subplots()
fig2, ax2 = plt.subplots()
x1 = [0]*100
x2 = [0]*100 
y1 = [0]*100
y2 = [0]*100
y3 = [0]*100
y4 = [0]*100
y5 = [0]*100 
y6 = [0]*100

''' Declaración de ejes a dibujar y asignación de líneas dibujadas '''
line1, = ax1.plot(x1, y1, '-', color = 'blue', label = 'Promedio_X')
line2, = ax1.plot(x1, y2, '-', color = 'red', label = 'Promedio_Y')
line3, = ax1.plot(x1, y3, '-', color = 'green', label = 'Promedio_Z')
line4, = ax2.plot(x2, y4, '-', color = 'blue', label = 'DesvEstándar_X')
line5, = ax2.plot(x2, y5, '-', color = 'red', label = 'DesvEstándar_Y')
line6, = ax2.plot(x2, y6, '-', color = 'green', label = 'DesvEstándar_Z')

ax1.legend()
ax2.legend()

''' Función de animación del promedio '''
def animationPromedio(frame):
    # LLamada a variables globales
    global x1, y1, y2, y3
    
    # Añado al eje 'x' el valor del contador de tiempo en segundos
    # Añado al eje 'y' el valor del promedio de cada eje
    x1.append(contador/20)
    y1.append(resultados_prom[0])
    y2.append(resultados_prom[1])
    y3.append(resultados_prom[2])
    
    # Asigno los valores para actualizar en la gráfica
    line1.set_data(x1, y1) 
    line2.set_data(x1, y2) 
    line3.set_data(x1, y3)
    # Actualizo el tamaño del plot
    fig1.gca().relim()
    fig1.gca().autoscale_view() 
    
    return line1, line2, line3

''' Función de animación de la desviación estándar '''
def animationDesviacion(frame):
    # LLamada a variables globales
    global x2, y4, y5, y6
    
    # Añado al eje 'x' el valor del contador de tiempo en segundos
    # Añado al eje 'y' el valor de la desviación estándar de cada eje
    x2.append(contador/20)
    y4.append(resultados_desv[0])
    y5.append(resultados_desv[1])
    y6.append(resultados_desv[2])
    
    # Asigno los valores para actualizar en la gráfica
    line4.set_data(x2, y4)
    line5.set_data(x2, y5)
    line6.set_data(x2, y6)
    # Actualizo el tamaño del plot
    fig2.gca().relim()
    fig2.gca().autoscale_view()
    
    return line4, line5, line6

def main(args):
    # Se inicia una instancia del puerto serie
    puerto = serial.Serial('COM5', 9600)
    
    try:
        #with open('datosPlot.txt', 'w') as f:
            #f.write("x;y;z\n")
        global contador
        contador = 0
        
        while 1:
            # Inicio valores
            global num_datos, resultados_prom, resultados_desv
            resultados = [0.0,0.0,0.0]
            suma_resultados = [0.0,0.0,0.0]
            num_datos = 100
            x_guardados = [0]*100
            y_guardados = [0]*100
            z_guardados = [0]*100
            num_x_var = [0]*100
            num_y_var = [0]*100
            num_z_var = [0]*100
            x_var_sum = [0]*100
            y_var_sum = [0]*100
            z_var_sum = [0]*100
            suma_num_var = [0]*3
            resultados_prom = [0]*3
            resultados_desv = [0]*3
            cont = 0
            # Entro en el bucle mientras que el contador sea menor que 100 (5 seg)
            while cont < num_datos:
                # Comprueba que hay datos en el puerto serie
                if puerto.in_waiting > 0:
                    # Convierto datos de entrada a cadena de texto y elimino espacios
                    line = puerto.readline().decode('utf-8').rstrip()
                    #print(line)
                    #with open('datosPlot.txt', 'a') as f:
                        #f.write(line.replace(', ', ';') + '\n')
                
                    # Compruebo el número de valores recibidos en el puerto serie
                    line_sub = line.split(", ")
                    if len(line_sub) >= 2:
                        x = line_sub[0]
                        y = line_sub[1]
                        z = line_sub[2]
                        
                        # Actualización de un array con los valores del puerto serie
                        resultados = [x, y, z]
                        # Sumo los valores recibidos a los guardados en el array de suma
                        x_nuevo = suma_resultados[0] + float(resultados[0])
                        y_nuevo = suma_resultados[1] + float(resultados[1])
                        z_nuevo = suma_resultados[2] + float(resultados[2])
                        suma_resultados = [x_nuevo, y_nuevo, z_nuevo]
                        
                        # Almaceno los datos recibidos en arrays respectivos
                        x_guardados[cont] = float(resultados[0])
                        y_guardados[cont] = float(resultados[1])
                        z_guardados[cont] = float(resultados[2])
                    
                    else:
                        # En caso de no obtener separadores adecuados o número incorrecto
                        print("Error en la lectura")
                    
                    cont += 1
            # Actualizo el contador del plot (cada 5 segundos)
            contador += cont
            
            ''' Cálculo del promedio '''
            print("Cálculo del promedio")
            x_promedio = suma_resultados[0]/num_datos
            y_promedio = suma_resultados[1]/num_datos
            z_promedio = suma_resultados[2]/num_datos
            resultados_prom = [x_promedio, y_promedio, z_promedio]
            print(resultados_prom)
            
            ''' Cálculo de la desviación estándar '''
            print("Cálculo de la desviación estándar")
            i = 0
            for i in range (num_datos):
                # Resta del cada valor del eje y del promedio de todos, al cuadrado
                num_x_var[i] = (x_guardados[i] - resultados_prom[0])**2
                num_y_var[i] = (y_guardados[i] - resultados_prom[1])**2
                num_z_var[i] = (z_guardados[i] - resultados_prom[2])**2
                
                # Sumo la resta al valor almacenado en el array de suma de la varianza
                x_var_sum = suma_num_var[0] + num_x_var[i]
                y_var_sum = suma_num_var[1] + num_y_var[i]
                z_var_sum = suma_num_var[2] + num_z_var[i]
            
            # Cálculo de la varianza    
            x_varianza = x_var_sum/(num_datos - 1)
            y_varianza = y_var_sum/(num_datos - 1)
            z_varianza = z_var_sum/(num_datos - 1)
            resultados_var = [x_varianza, y_varianza, z_varianza]
            
            # Cálculo de la desviación estándar (raiz cuadrada de la varianza)
            desv_estandar_x = np.sqrt(resultados_var[0])
            desv_estandar_y = np.sqrt(resultados_var[1])
            desv_estandar_z = np.sqrt(resultados_var[2])
            resultados_desv = [desv_estandar_x, desv_estandar_y, desv_estandar_z]
            print(resultados_desv)
            
            # Dibujo con la función FuncAnimation el promedio y desviación
            anim1 = FuncAnimation(fig1, animationPromedio, interval = 1000, repeat = True, blit = True, save_count = 50)
            anim2 = FuncAnimation(fig2, animationDesviacion, interval = 1000, repeat = True, blit = True, save_count = 50)
            # Espero un pequeño tiempo para el correcto dibujo de los datos y muestro
            plt.pause(0.01)
            plt.show()
    
    except KeyboardInterrupt:
        # Finalizar con comando Ctrl+C para cerrar adecuadamente el puerto serie
        puerto.close()
        plt.close('all')
        print("Comunicacion finalizada.")

# Ejecución de la función principal "main" al ejecutar el código
if __name__ == '__main__':
    main(sys.argv)