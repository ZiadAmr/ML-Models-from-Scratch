#include "Maths/Matrix.h"
#include "svm/svm.h"

#include <vector>

int main() {
    try {    
        auto f = std::vector<float>({-1,0,0,1,4,4,2,3});
        Matrix X(4,2, f);
        std::vector<float> y({-1,-1,1,1});

        SVM clf(0.5, 0.1, 1000);
        clf.fit(X, y);
        std::cout << X << std::endl;
        std::cout << clf.predict(X[0]) << std::endl;
        std::cout << clf.predict(X[1]) << std::endl;
        std::cout << clf.predict(X[2]) << std::endl;
        std::cout << clf.predict(X[3]) << std::endl;
    } catch (std::exception e){
        std::cout << e.what();
    }
}