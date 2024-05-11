# -*- coding: utf-8 -*-
"""
Created on Mon Apr 15 23:57:13 2024

@author: Diego Remón
"""

#IMPORTS
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import math
import time  as t
import sys
import os
import csv

#FUNCTIONS

#function to read the data from a csv file
def Get_timelapse(excel_path):
    
    time = []
    accX = []
    accY = []
    accZ = []
    gyrX = []
    gyrY = []
    gyrZ = []
    
    with open(excel_path,'r') as csv_file:
        csv_data = csv.reader(csv_file, delimiter=' ')
        for row in csv_data:            
            row_data = row[0].split(",")            
            try:            
                time.append(float(row_data[0]))
                accX.append(float(row_data[1]))
                accY.append(float(row_data[2]))
                accZ.append(float(row_data[3]))
                gyrX.append(float(row_data[4]))
                gyrY.append(float(row_data[5]))
                gyrZ.append(float(row_data[6]))
            except:
                pass
    
    return time, accX, accY, accZ, gyrX, gyrY, gyrZ


#function to filter the high frequencies from the dataset
def smooth_data(data,n_smooth):
    data_smoothed=[]
    
    for i in range(len(data)):
        if i > n_smooth-1:
            
            data_smoothed.append(sum(data[i-j] for j in range(n_smooth))/n_smooth)
    return data_smoothed

#function to saturate the data
def sat_data(data,max_limit,min_limit):
    data_sat=[]
    for i in range(len(data)):
        if data[i] < min_limit :
            data_sat.append(min_limit)
            
        elif data[i] > max_limit :
            data_sat.append(max_limit)
        
        else:
            data_sat.append(data[i])
    return data_sat
    
    
#function to draw the data in time axis
def draw_data(data,time,type_data):
    
    plt.plot(time,data)
    plt.xlabel('Time')
    if type_data == 0:  
        plt.ylabel('accZ')
    elif type_data == 1:  
        plt.ylabel('gyrY')
    plt.grid()
    plt.show()

#function to find the index
def find_indices(array, value):
    indices = [i for i, x in enumerate(array) if x == value]
    return indices[0]

#function to integrate a signal
def integrate_signal(signal,time):
    
    dt = (time[1]-time[0])/1000    
    angle=0
    angle_degrees =[]
    for i in range(len(time)):       
            
        angle_add = signal[i] * dt      
        angle = angle + angle_add        
        angle_degrees.append(angle)
    return angle_degrees
        

#GLOBAL VARIABLES
#mef
class StateMachine:
    def __init__(self):
        self.state = 'Rest'

    def transition(self, new_state):
        self.state = new_state
        
states_list =['Rest', 'Up', 'Top','Down']
        

#MAIN FUNCTION
if __name__ == "__main__":
    
    #Get data to analyze
    excel_path = r'C:\Users\Usuario\Desktop\Trabajo edge impulse\3\Puntillas.a3de23c6a901.csv'    
    time, _ , _ , accZ, _ , gyrY, _ = Get_timelapse(excel_path)
    
    #Smooth the data to eliminate the high frquencies 
    n_smooth = 20
    accZ = smooth_data(accZ,n_smooth)   
    accZ = sat_data(accZ,1,-0.08)
    gyrY = smooth_data(gyrY,n_smooth)     
    time = time[0:(len(time)-n_smooth)]
    angle_degrees = integrate_signal(gyrY,time)
    
    #Analyze the states
    myMEF = StateMachine()
    myMEF.transition(states_list[0])
    
    #get the key points
    up_time = []
    up_accZ = []
    up_gyrY = []
    top_time = []
    top_accZ = []
    top_gyrY = []
    down_time = []
    down_accZ = []
    down_gyrY = []
    rest_time = []
    rest_accZ = []
    rest_gyrY  = []
    dist_min = 5
    for i in range(len(time)):
        if i > 0 :
            daccZ_dt = (accZ[i]-accZ[i-1])/(time[i]-time[i-1])
            dist_min-=1
            
            #From Rest to Up
            if   (accZ[i] > -0.08) and (dist_min<=0) and (myMEF.state == 'Rest'):
                dist_min=5
                myMEF.transition(states_list[1]) 
                up_time.append(time[i])
                up_accZ.append(accZ[i])
                up_gyrY.append(gyrY[i])
            
            #From Up to Top
            if (myMEF.state =='Up') and (daccZ_dt <= 1e-3) and (daccZ_dt >= 0):
                dist_min=5
                myMEF.transition(states_list[2])
                top_time.append(time[i])
                top_accZ.append(accZ[i])
                top_gyrY.append(gyrY[i])
            
            #From Top to Down
            if (myMEF.state =='Top') and (daccZ_dt <  -1e-5):
                dist_min=5
                myMEF.transition(states_list[3])
                down_time.append(time[i])
                down_accZ.append(accZ[i])
                down_gyrY.append(gyrY[i])
            
            #From Down to Rest
            if   (accZ[i] < -0.075) and (dist_min<=0) and (myMEF.state == 'Down'):
                dist_min=40 
                myMEF.transition(states_list[0]) 
                rest_time.append(time[i])
                rest_accZ.append(accZ[i])     
                rest_gyrY.append(gyrY[i])
                    
                
    plt.plot(time,accZ)    
    plt.scatter(up_time,up_accZ, color='r',s=10)
    plt.scatter(top_time,top_accZ, color='g',s=10)
    plt.scatter(down_time,down_accZ, color='c',s=10)
    plt.scatter(rest_time,rest_accZ, color='m',s=10)
    plt.xlabel('Time')      
    plt.ylabel('accZ ')    
    plt.grid()
    plt.show()        
    
    
    #Get infromation with the key points
    #time of each cycle
    time_cycle =[]
    for i in range(len(rest_time)):
        res = rest_time[i]-up_time[i]        
        time_cycle.append(res)
        
    #time in the top
    time_top =[]
    for i in range(len(top_time)
    ):
        res = down_time[i]-top_time[i]        
        time_top.append(res)
        
    #angle
    max_angle = []
    min_angle = []
    mean_angle = []
    for i in range(len(top_time)):
        idx0 = find_indices(time,top_time[i])
        idx1 = find_indices(time,down_time[i])
        
        max_val = 0
        min_val = 100
        mean_val = 0
        for j in range(idx0,idx1+1):
            
            if(angle_degrees[j]>max_val):
                max_val= angle_degrees[j]               
        
            if(angle_degrees[j]<min_val and angle_degrees[j]>0):
                min_val= angle_degrees[j]
            
            mean_val += angle_degrees[j]
                
                
                
        if max_val>0 and min_val <100:        
            max_angle.append(max_val) 
            min_angle.append(min_val) 
        mean_angle.append(mean_val/(idx1+1))     
        
            
    
    
    
        
    
    
   
        
        
    