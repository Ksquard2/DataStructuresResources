# Ahmed Kiel-Kamil
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

def vector_mult(matrix1, matrix2, start, bias):
    total = 0.0
    for i in range(len(matrix1)):
        if i != len(matrix1) - 1:
            total += matrix1[i] * matrix2[i + start]
        else:
            total += (matrix1[i] * matrix2[i + start]) + bias
    return total

def forward_prop(start, weights, bias):
    print("Start: "+str(start))
    for i in range(len(weights)):
        start *= weights[i]
        start += bias[i]
        print("Pre Sigmoid: "+str(start))
        start = sigmoid(start)
        print("Post Sigmoid: "+str(start))
    y = start - .9
    loss = (y * y) / 2
    print("Loss: "+str(loss))

def forward_prop2(input_vec, weights, bias, col=1):
    # Find the number of rows for the hidden layer
    if col - 1:
        quad = pow((2 * len(input_vec)), 2) + 4 * (col - 1) * len(weights)
        hr = int((math.sqrt(quad) - 2 * len(input_vec)) / (2 * col - 1))
    else:
        hr = len(weights) // (len(input_vec) * 2)
    
    last = len(input_vec) * hr
    hidden = []
    done = hr
    cont = len(input_vec)
    # Index for bias vector
    bindex = 0
    # Loops through the weights vector incrementing based on the number of values in the hidden layer
    i = 0
    while i < len(weights):
        val = 0.0
        # 1. Vector multiplication
        val = vector_mult(input_vec,weights,i,bias[bindex])
        # 2. Adds a product of vectors into temporary hidden layer vector
        hidden.append(sigmoid(val))
        # 3. Check if hidden layer is complete
        if len(hidden) == hr:
            # 4. Hidden layer vector becomes new input vector
            input_vec = hidden.copy()
            print(input_vec)

            hidden.clear()
            # 5. Observe the next bias
            bindex += 1
        
        # 6. Check if we have reached the output layer
        if i + last + 1 == len(weights):
            hr = last // hr
        if(done != 0):
            done = done-1
            i+=cont
        else:
            i += len(input_vec)
    print("Loss:")
    loss = [(input_vec[0]-.1)**2,(input_vec[1] -.9)**2]
    print(loss)
    return input_vec
start = .3
weights2 = [.5, .2]
bias2 = [.3, .4]

bias = [0.35, 0.6]  # Python lists can be initialized directly with values
input_vec = [0.5, 0.1]  # Named input_vec to avoid conflict with Python's input() function
weights1 = [0.15, 0.2, 0.25, 0.3, 0.4, 0.45, 0.5, 0.55]

# linear network
forward_prop(start,weights2,bias2)

# Quadratic network
forward_prop2(input_vec, weights1, bias)



