//
//  eigen_test.cpp
//  option_pricing
//
//  Created by Matthew liew on 29.10.23.
//

#include "Eigen/Dense"
#include <iostream>

int main () {
    Eigen::ArrayXXf array;
    array.resize(2,2);
    array << 1,2,3,4;
    
    for (int i=0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
