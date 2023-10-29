//
//  Random.cpp
//  joshi_chp6
//
//  Created by Matthew liew on 22.10.23.
//

#include "Random.hpp"
#include "Normals.h"
#include <cstdlib>

using namespace std;

void RandomBase::GetGaussians(Eigen::ArrayXXf& variates) {
    GetUniforms(variates);
    
    for (unsigned long i=0; i < Dimensionality; i++) {
        double x = variates[i];
        variates[i] = InverseCumulativeNormal(x);
    }
}

void RandomBase::ResetDimensionality(unsigned long NewDimensionality) {
    Dimensionality = NewDimensionality;
}

RandomBase::RandomBase(unsigned long Dimensionality_)
: Dimensionality(Dimensionality_) {}
