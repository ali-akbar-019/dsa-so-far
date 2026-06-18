import pandas as pd
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression


hours = [[1], [2], [3], [4], [5], [6], [7],[8], [9], [10]]
marks = [10,20,30,40,50,60,70,80,90,100]

model = LinearRegression()
model.fit(hours, marks)

prediction = model.predict([[7.5]])
all_prediction = model.predict(hours)

print("Slope: ", model.coef_[0])
print("Intercept: ", model.intercept_)
print("Prediction for the 7.5 hrs: ", prediction)
print("MSE: ", mean_squared_error(marks, all_prediction))
print("R2 Score: ", r2_score(marks, all_prediction))

plt.scatter(hours, marks, label="Actual Data")
plt.plot(hours, all_prediction, label="Regression Line")

plt.xlabel("Hours")
plt.ylabel("Marks")

plt.legend()
plt.show()
