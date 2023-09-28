#include "Maths/Matrix.h"
#include "perceptron/perceptron.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include <vector>

int main() {
    
    try {    
        std::vector<float> X_temp;
        std::vector<float> y;

        std::ifstream file;
        file.open("IRIS.csv");
        std::string line;
        std::getline(file, line);
        int counter = 0;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            for(int i = 0; i < 4; i++){
                std::string substr;
                std::getline(ss, substr, ',');
                X_temp.push_back(std::stof(substr));
            }
            std::string substr;
            std::getline(ss, substr, ',');
            if(substr == "Iris-setosa"){
                y.push_back(1);
            } else {
                y.push_back(-1);
            }
        }

        Matrix X(100, 4, X_temp);
        Perceptron clf(0.1, 200);
        clf.fit(X, y);

        std::cout << clf.predict({6.1,2.9,4.7,1.4}) << std::endl;

    } catch (std::exception e){
        std::cout << e.what();
    }
}