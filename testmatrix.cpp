#include <iostream>
#include <vector>
#include <stdexcept>

#include "Maths/Matrix.h"

int main(){
    // float f[] = {1,2,3,4,5,6,7,8,9};
    try{
        std::vector<float> f = {1, 2, 3};
        Matrix m(1,3, f);
        
        std::vector<float> f2 = {4,5,6};
        Matrix m2(3,1, f2);
        std::cout << "Multi" << std::endl;
        Matrix m3 = m2*m;

        std::cout << m3.x_size() << " " << m3.y_size() << std::endl;
        std::cout << m3;

    } catch (std::runtime_error e){
        std::cout << e.what();
    } catch (std::exception e){
        std::cout << e.what();
    }

    return 0;
}

