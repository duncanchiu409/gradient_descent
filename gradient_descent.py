import numpy as np
import math

def equation(x, w, b,):
    return np.dot(w, x) + b

def compute_cost(x, y, w, b):
    length = x.shape[0]

    cost = 0
    total_cost = 0

    for i in range(length):
        cost += (equation(x[i], w, b) - y[i])**2
    
    total_cost = cost / 2 / length
    return total_cost

def compute_gradient(x, y, w, b):
    m, n = x.shape
    dj_dw = np.zeros((n, ))
    dj_db = 0.

    for i in range(m):
        for j in range(n):
            dj_dw[j] += (equation(x[i], w, b) - y[i]) * x[i][j]
        dj_db += equation(x[i], w, b) - y[i]

    dj_dw = dj_dw / m
    dj_db = dj_db / m

    return dj_dw, dj_db

def gradient_descent(x, y, a, w_init, b_init, iterations):
    w = w_init
    b = b_init

    J_history = []


    for i in range(iterations):
        dj_dw, dj_db = compute_gradient(x, y, w, b)
        w = w - a * dj_dw
        b = b - a * dj_db

        if i < 100000:
            J_history.append(compute_cost(x, y, w, b))

        if (i % math.ceil(iterations/10)) == 0:
            print(f"Iteration {i:4d}: Cost {J_history[-1]:8.2f}")

    return w, b
    

def main():
    w_init = np.array([ 0.39133535, 18.75376741, -53.36032453, -26.42131618])
    # initialize parameters
    initial_w = np.zeros_like(w_init)
    initial_b = 0.
    # some gradient descent settings
    iterations = 1000
    alpha = 5.0e-7

    X_train = np.array([[2104, 5, 1, 45], [1416, 3, 2, 40], [852, 2, 1, 35]])
    y_train = np.array([460, 232, 178])

    w, b = gradient_descent(X_train, y_train, alpha, initial_w, initial_b, iterations)
    print(f"b, w found by gradient descent: {b:0.2f}, {w} ")

main()