#include "svm.h"

#include <cstdlib>

SVM::SVM(float lambda, float alpha=0.1, int epochs=1000)
{
    this->alpha = alpha;
    this->epochs = epochs;
    this->bias = 0;
    this->lambda = lambda;
}

void SVM::fit(const Matrix& X, std::vector<float> y)
{
    // self.W = std::rand() / std::RAND_MAX;
    this->weights = std::vector<float>(X.y_size());
    for(int i = 0; i < this->weights.size(); i++){
        this->weights[i] = std::rand() / RAND_MAX;
    }
    for(int iter = 0; iter < epochs; iter++){
        for(int i = 0; i < X.x_size(); i++){
            if (y[i] != this->predict(X[i])){
                // this->weights += this->alpha * y[i] * X[i]
                for(int w = 0; w < this->weights.size(); w++){
                    this->weights[w] += this->alpha * y[i] * X[i][w];
                }
                this->bias += this->alpha * y[i];
            }
        }
        for(int w = 0; w < this->weights.size(); w++){
            this->weights[w] -= this->alpha * this->lambda * this->weights[w]; // regularization
        }
    }
}

float SVM::score(const std::vector<float> x)
{
    float sum = 0;
    for(int i = 0; i < this->weights.size(); i++){
        sum += x[i] * this->weights[i];
    }
    return sum + this->bias;
}

int SVM::predict(const std::vector<float> x)
{
    float result = this->score(x);
    if(result >= 0){
        return 1;
    } else {
        return -1;
    }
}

float SVM::score(const float* x)
{
    float sum = 0;
    for(int i = 0; i < this->weights.size(); i++){
        sum += x[i] * this->weights[i];
    }
    return sum + this->bias;
}

int SVM::predict(const float* x)
{
    float result = this->score(x);
    if(result >= 0){
        return 1;
    } else {
        return -1;
    }
}
