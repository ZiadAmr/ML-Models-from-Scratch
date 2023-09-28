#include "../Maths/Matrix.h"

#include <vector>

class Perceptron{
    public:
        Perceptron(float alpha, int epochs);

        void fit(const Matrix& X, std::vector<float> y);

        float score(const std::vector<float> x);
        float score(const float* x);
        int predict(const std::vector<float> x);
        int predict(const float* x);
    private:
        float alpha;
        int epochs;
        std::vector<float> weights; 
        float bias;
};