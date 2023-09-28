#include "Matrix.h"

#include <stdexcept>
#include <iostream>
#include <memory>

Matrix::Matrix(int x, int y){
    this->x = x;
    this->y = y;
    array = new float*[x];
    for(int i = 0; i < x; i++){
        array[i] = new float[y];
        std::memset(array[i], 0, y * sizeof(float));
    }
}
Matrix::Matrix(int x, int y, float *values){
    this->x = x;
    this->y = y;
    array = new float*[x];
    for(int i = 0; i < x; i++){
        array[i] = new float[y];
    }
    int index = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            array[i][j] = values[index];
            index++;
        }
    }
}
Matrix::Matrix(int x, int y, std::vector<float> values){
    this->x = x;
    this->y = y;
    array = new float*[x];
    for(int i = 0; i < x; i++){
        array[i] = new float[y];
    }
    int index = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            array[i][j] = values[index];
            index++;
        }
    }
}
float Matrix::get(int x, int y) const
{
    if (x >= this->x || y >= this->y){
        throw std::runtime_error("Error: Out of index access");
    }
    return array[x][y];
};

Matrix& Matrix::operator=(const Matrix& other){
    // validate size
    if(x != other.x_size() || y != other.y_size()){
        throw std::runtime_error("Error: trying to equate matrices of different sizes");
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            array[i][j] = other.get(i,j);
        }
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix &other)
{
    if(x != other.x_size() || y != other.y_size()){
        throw std::runtime_error("Error: trying to add matrices of different sizes");
    }
    float output[x*y];
    int index = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            output[index] = array[i][j] + other.get(i,j);
            index += 1;
        }
    }

    return Matrix(x, y, output);
}

Matrix Matrix::operator-(const Matrix &other)
{
    if(x != other.x_size() || y != other.y_size()){
        throw std::runtime_error("Error: trying to subtract matrices of different sizes");
    }
    float output[x*y];
    int index = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            output[index] = array[i][j] - other.get(i,j);
            index += 1;
        }
    }

    return Matrix(x, y, output);
}

Matrix Matrix::operator*(const Matrix &other)
{
    if(y != other.x_size()){
        throw std::runtime_error("Error: trying to multiply matrices of incompatible sizes");
    }
    float output[x * other.y_size()];
    int index = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < other.y_size(); j++){
            // ith row of matrix one with jth column of matrix two
            float sum = 0;
            for(int m = 0; m < y; m++){
                sum += this->get(i,m) * other.get(m,j);
            }
            output[index] = sum;
            index += 1;
        }
    }
    return Matrix(x, other.y_size(), output);
}

Matrix Matrix::operator*(const float number)
{
    float output[x *y];
    int index = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            output[index] = this->get(i,j) * number;
            index += 1;
        }
    }
    return Matrix(x,y,output);
}

Matrix Matrix::operator/(const float number)
{
    float output[x *y];
    int index = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            output[index] = this->get(i,j) / number;
            index += 1;
        }
    }
    return Matrix(x,y,output);
}

float *Matrix::operator[](const int index) const
{
    if (index >= this->x){
        throw std::runtime_error("Error: Out of index access");
    }
    return array[index];
}

Matrix::~Matrix()
{
    for(int i = 0; i < x; i++){
        delete array[i];
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    for(int i = 0; i < m.x_size(); i++){
        os << "| ";
        for(int j = 0; j < m.y_size(); j++){
            os << m.get(i,j) << " "; 
        }
        os << "|\n";
    }
    return os;
}