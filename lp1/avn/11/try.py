import pandas as pd 
import numpy as np 
from matplotlib import pyplot as plt 

data = pd.read_csv('weather.csv',sep=',',header=None)

l = len(data)

#print(l)
maxmimum_index = -1
maxmimum_value = 0.0
date = ""
for i in range(0,l):
    x = data[0][i]
    if x[2] == '1' and x[3] == '3' :
        z = float(data[8][i])
        if z > maxmimum_value :
            maxmimum_value = z
            maxmimum_index = i
            date = x 

print(date,maxmimum_value)