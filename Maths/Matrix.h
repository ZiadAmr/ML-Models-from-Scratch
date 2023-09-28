#ifndef MATRIX_H
#define MATRIX_H

#include <cstring>
#include <vector>
#include <iostream>

class Matrix {
    public:
        Matrix(int x, int y);
        Matrix(int x, int y, float* values);
        Matrix(int x, int y, std::vector<float> values);
        // TODO: throw error when x,y are beyond bounds
        float get(int x, int y) const;
        void set(int x, int y, float value) {array[x][y] = value;}

        Matrix& transpose() const;

        Matrix& operator=(const Matrix& other);

        Matrix operator+(const Matrix& other);
        Matrix operator-(const Matrix& other);
        Matrix operator*(const Matrix& other);

        Matrix operator*(const float number);
        Matrix operator/(const float number);

        float* operator[](const int index) const;

        int x_size() const {return x;}
        int y_size() const {return y;}
        
        ~Matrix();
    private:
        int x, y;
        float **array;
};

//TODO: implement operators +, -, = etc.
std::ostream& operator<<(std::ostream& os, const Matrix& m);

#endif