import numpy as np

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

    m, n = x

    for i in range(iterations):
    

def main():
    x_train = np.array()