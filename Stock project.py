import numpy as np
import matplotlib as plt
from sklearn import preprocessing
import pandas as pd
from sklearn import metrics
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
import random

data = pd.read_csv("D:/Projects/1/TSLA.csv")
data.head()
data.info()
data.describe()
X = data[['High','Low','Open','Volume']].values
y = data['Close'].values
print(X)
print(y)

X_train, X_test, y_train, y_test = train_test_split(X,y, test_size=0.3, random_state=1)

Model = LinearRegression()

Model.fit(X_train, y_train)

print(Model.coef_)

predicted = Model.predict(X_test)
print(predicted)
import math
print('Mean Absolute Error:', metrics.mean_absolute_error(y_test,predicted))
print('Mean Squared Error:', metrics.mean_squared_error(y_test,predicted))
print('Root Mean Squared Error:', math.sqrt(metrics.mean_squared_error(y_test,predicted)))

graph = data.head(20)
graph.plot(kind='bar')

