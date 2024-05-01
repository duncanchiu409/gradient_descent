# Gradient Descent
Simple `Batch` [Gradient Descent](https://en.wikipedia.org/wiki/Gradient_descent) implementation based from mathematic proof where I learned from [Andrew Ng](https://www.linkedin.com/in/andrewyng) from Standford University.

## Linear Model (Regression Model)
The linear model ([Linear Regression](https://en.wikipedia.org/wiki/Linear_regression)) that predict $`f_{w, b}(x^{(i)})`$ is
```math
f_{w, b}(x^{i}) = wx^{(i)} + b \tag{1}
```
where `w` and `b` are the slope and constant in the linear model,  

### BUT???
How do we know `w` and `b` are optimised (fitted for the model)?
Linear Regression and Gradient Descent are like a person trying to get downhill taking small steps.
The program adjust and adjust `w` and `b` variable. We measure the optimisation of `w` and `b` through a Cost Function.

## Cost Function Formula (Mean Square Error Equation)
The formula is
```math
J_{w, b} = \frac{1}{2m} \sum\limits_{i=0}^{m-1} (f_{w,b}(x^{(i)}) - y^{(i)})^2 \tag{2}
```
where m is the number of training examples, $`y^{i}`$ is the ith true data,  

### BUT???
How do we know should we increase or decrease `w` and `b` each iteration?
Our ultimate goal is finding a local minimum (not global minimum) on the Cost Function.  
Therefore, we use partial derivatives for the decision making, if the current `w` and `b` return a positive number, it decreases the `w` and `b`.

## Gradient Descent Algorithm
Gradient descent algorithm is essentially described as  
repeat until convergence: {
```math
w = w - α \frac{d J(w, b)}{d w}
```
```math
b = b - α \frac{d J(w, b)}{d b} \tag{3}
```
}  
where `w` and `b` are updated simultaneously,  

### Simplify the Derivatives
Using the chain rule and the linear combination rule,  
```math
\frac{d J(w, b)}{d w} = \frac{1}{m} \sum\limits_{i=0}{m-1} (f_{w, b}(x^{(i)}) - y^{(i)}) x^{(i)} \tag{4}
```
```math
\frac{d J(w, b)}{d b} = \frac{1}{m} \sum\limits_{i=0}{m-1} (f_{w, b}(x^{(i)}) - y^{(i)}) \tag{5}
```
