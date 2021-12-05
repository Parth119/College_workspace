import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt 

from sklearn.datasets import load_boston 
boston = load_boston()
df = pd.DataFrame(boston.data)

df.columns = boston.feature_names

from sklearn.model_selection import train_test_split
x = boston.data
y = boston.target

X_train, x_test, Y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=4 )

from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

LinReg = LinearRegression()
LinReg.fit(X_train, Y_train)

#Predict
y_predict = LinReg.predict(x_test)

#Error Calculation by MSE
mse = mean_squared_error(y_test, y_predict)
print('Mean Squared Error: ', mse)

#Error Calculation by RMSE
from math import sqrt
print('RMSE : ',sqrt(mse))
