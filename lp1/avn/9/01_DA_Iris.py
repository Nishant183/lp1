# Program no. 1 

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris

iris = load_iris()

data_set = pd.DataFrame(data= np.c_[iris['data'], iris['target']],
                     columns= iris['feature_names'] + ['target'])

# Complete information of all attributes of Iris
print('\n', 'DATA SET INFORMATION'.center(45, '_'))
print(data_set.info())

# Description with Statistics of Iris Dataset
print('\n', 'STATISTICAL INFORMATION'.center(45, '_'))
print(data_set.describe())

# Locate a specific type of Data type in Data set
print('\n', 'COLUMNS DTYPE (IF NOMINAL)'.center(45, '_'))
print(data_set.select_dtypes(include=['category']))

# Data types of Iris column wise, to locate ordinal & nominal
print('\n', 'COLUMNS DTYPE (ALL)'.center(45, '_'))
print(data_set.dtypes)

# Memory occupancy done by Dataset
print('\n', 'DATA SET MEMORY USAGE'.center(45, '_'))
print(data_set.memory_usage())

# Counting any missing data (if any else zero)
def num_missing(x):
  return sum(x.isnull())

#Applying per column:
print('\n', 'MISSING VALUE CHECK'.center(45, '_'))
print("Missing values per column:")
print(data_set.apply(num_missing, axis=0)) 
#axis=0 defines that function is to be applied on each column

# Plotting Histogram
# #1 All Features
data_set[['sepal length (cm)', 'sepal width (cm)', 'petal length (cm)','petal width (cm)']].plot.hist(bins=10,
                                                                                                      title='All features')
plt.show()

# #2 Only 2 features at a time
data_set[['sepal length (cm)', 'sepal width (cm)']].plot.hist(bins=10, title='Sepal Features')
plt.show()

data_set[['petal length (cm)','petal width (cm)']].plot.hist(bins=10, title='Petal Features')
plt.show()

# Plotting Boxplot
data_set.plot.box(title="All Features with outliers")
plt.show()
# Try noticing the 'o', those are outliers. The ones who are not in InterQuertile Range (IQR) are Outliers


