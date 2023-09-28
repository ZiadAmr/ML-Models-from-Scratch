# ML-Models-from-Scratch
A repository where I program machine learning models such as SVM, PCA, etc. from scratch in C++

## Matrix class
Supported operations 
Copy operator using = 

Pairwise subtraction addition operators +/-

Multiplication with a single number *

Dot product operator *

[] access operator (returns an array of floats corresponding to accessed row)

**work in progress:**
transpose operator

## Perceptron
Make sure to `#include<Perceptron/Perceptron.h>` in your file. Then create an instance of the class using `Perceptron clf(a, e)` where `a` is the alpha value that determines the regularization rate and `e` representing the number of epochs to iterate over. The model is then trained using `clf.fit(X, y)` where `X` is a matrix of the features and `y` is the labels (must be values of -1 and 1).

### Theory
**explain here how the perceptron works**

