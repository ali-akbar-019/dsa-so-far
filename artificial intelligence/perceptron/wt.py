import numpy as np

class Perceptron:
    def __init__(self, learning_rate=0.1, epochs=10):
        self.learning_rate = learning_rate
        self.epochs = epochs
    
    def activation(self, z):
        return 1 if z >= 0 else 0
    
    def fit(self, X, y):
        self.weights = np.zeros(X.shape[1])
        self.bias = 0

        for epoch in range(self.epochs):
            for inputs, target in zip(X, y):
                z = np.dot(self.weights, inputs) + self.bias
                prediction = self.activation(z)
                error = target - prediction
                self.weights += self.learning_rate * error * inputs
                self.bias += self.learning_rate * error
        
    def predict(self, X):
        return [self.activation(np.dot(x, self.weights) + self.bias) for x in X]

X = np.array([[0,0],[0,1],[1,0],[1,1]])
y = np.array([0,0,0,1])

model = Perceptron()
model.fit(X, y)

print("Weights: ", model.weights)
print("Bias: ", model.bias)
print("Prediction: ",model.predict(X))