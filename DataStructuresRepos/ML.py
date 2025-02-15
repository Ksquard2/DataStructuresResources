import math

# Function to calculate e raised to the power of 'po'
def e(po):
    e_approx = 1.0
    factorial = 1.0
    for i in range(1, 20):
        factorial *= i
        e_approx += 1.0 / factorial
    return e_approx ** po

# Sigmoid function
def sigmoid(x):
    return 1.0 / (1.0 + e(x * -1.0))

# Forward Propagation function
def forwardProp(start, weights, bias):
    answer = []
    print(f"input layer: {start}")
    for i in range(len(weights)):
        start *=weights[i]
        start +=bias[i]
        print(f"pre sigmoid: {start}")
        start = sigmoid(start)
        print(f"post sigmoid: {start}")
    return answer

weights = [.5,.2]
bias = [.3,.4]
forwardProp(.3,weights,bias)