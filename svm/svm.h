#include "../Maths/Matrix.h"
#include <vector>

class SVM {
    public:
        SVM(float lambda, float alpha, int epochs);

        void fit(const Matrix& X, std::vector<float> y);

        float score(const std::vector<float> x);
        float score(const float* x);
        int predict(const std::vector<float> x);
        int predict(const float* x);

        std::vector<float> get_weights() {return weights;}
    private:
        float alpha;
        int epochs;
        std::vector<float> weights; 
        float bias;
        float lambda;
};