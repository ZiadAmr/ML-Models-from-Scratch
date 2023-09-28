#include "perceptron.h"

#include <cstdlib>

Perceptron::Perceptron(float alpha, int epochs)
{
    this->alpha = alpha;
    this->epochs = epochs;
    this->bias = 0;
}

void Perceptron::fit(const Matrix& X, std::vector<float> y)
{
    // self.W = std::rand() / std::RAND_MAX;
    this->weights = std::vector<float>(X.y_size());
    for(int i = 0; i < this->weights.size(); i++){
        this->weights[i] = std::rand() / RAND_MAX;
    }
    for(int iter = 0; iter < epochs; iter++){
        bool finished = true;
        for(int i = 0; i < X.x_size(); i++){
            if (y[i] != this->predict(X[i])){
                finished = false;
                // this->weights += this->alpha * y[i] * X[i]
                for(int w = 0; w < this->weights.size(); w++){
                    this->weights[w] += this->alpha * y[i] * X[i][w];
                }
                this->bias += this->alpha * y[i];
            }
        }
        if(finished) break;
    }
}

float Perceptron::score(const std::vector<float> x)
{
    float sum = 0;
    for(int i = 0; i < this->weights.size(); i++){
        sum += x[i] * this->weights[i];
    }
    return sum + this->bias;
}

int Perceptron::predict(const std::vector<float> x)
{
    float result = this->score(x);
    if(result >= 0){
        return 1;
    } else {
        return -1;
    }
}

float Perceptron::score(const float* x)
{
    float sum = 0;
    for(int i = 0; i < this->weights.size(); i++){
        sum += x[i] * this->weights[i];
    }
    return sum + this->bias;
}

int Perceptron::predict(const float* x)
{
    float result = this->score(x);
    if(result >= 0){
        return 1;
    } else {
        return -1;
    }
}
