//
//  BlackScholesFormulas.cpp
//  joshi_chp9
//
//  Created by Matthew liew on 22.10.23.
//

#include "BlackScholesFormulas.hpp"
#include <cmath>
#include "Normals.hpp"

double BlackScholesCall(double Spot,
                        double Strike,
                        double r,
                        double d,
                        double Vol,
                        double Expiry) {
    double standardDeviation = Vol * sqrt(Expiry);
    double moneyness = log(Spot/Strike);
    double d1 = (moneyness + (r-d)*Expiry
                 + 0.5 * standardDeviation * standardDeviation) / standardDeviation;
    double d2 = d1 - standardDeviation;
    
    return Spot * exp(-d * Expiry) * CumulativeNormal(d1)
            - Strike * exp(-r * Expiry) * CumulativeNormal(d2);
   
}

double BlackScholesCallVega(double Spot,
                            double Strike,
                            double r,
                            double d,
                            double Vol,
                            double Expiry) {
    double standardDeviation = Vol * sqrt(Expiry);
    double moneyness = log(Spot/Strike);
    double d1 = moneyness + ((r-d)*Expiry + 0.5 * standardDeviation * standardDeviation)/standardDeviation;
    
    return Spot *  exp(-d * Expiry) * sqrt(Expiry) * NormalDensity(d1);
}

//TODO: the rest of the models
