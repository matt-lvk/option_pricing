//
//  BlackScholesEngine.cpp
//  joshi_chp7
//
//  Created by Matthew liew on 31.10.23.
//

#include "BlackScholesEngine.hpp"
#include <cmath>

BSEngine::BSEngine (const Wrapper<PathDependent>& TheProduct_,
                         const Parameters& r_,  // risk free rate
                         const Parameters& d_,  // dividend yield
                         const Parameters& Vol_,// volatility
                         const Wrapper<RandomBase>& TheGenerator_,
                            double Spot_)
: ExoticEngine(TheProduct_, r_), TheGenerator(TheGenerator_) {
    MJArray Times(TheProduct_ -> GetLookAtTimes());
    NumberOfTimes = Times.size();
    
    TheGenerator -> ResetDimensionality(NumberOfTimes);
    Drifts.resize(NumberOfTimes);
    StandardDeviations.resize(NumberOfTimes);
    
    double Variance = Vol_.IntegralSquare(0, Times[0]);
    
    Drifts[0] = r_.Integral(0.0, Times[0]) - d_.Integral(0.0, Times[0])
    - 0.5  * Variance;
    
    StandardDeviations[0] = sqrt(Variance);
    
    for (unsigned long j=1; j < NumberOfTimes; ++j) {
        double thisVariance = Vol_.IntegralSquare(Times[j-1], Times[j]);
    
        Drifts[j] = r_.Integral(Times[j-1], Times[j]) - d_.Integral(Times[j-1], Times[j])
        - 0.5 * Variance;
        
        StandardDeviations[j]  = sqrt(thisVariance);
    }
    LogSpot = log(Spot_);
    Variates.resize(NumberOfTimes);
}

void BSEngine::GetOnePath(MJArray& SpotValues) {
    TheGenerator -> GetGaussians(Variates);
    
    double CurrentLogSpot = LogSpot;
    
    for (unsigned long j=0; j < NumberOfTimes; ++j) {
        CurrentLogSpot += Drifts[j];
        CurrentLogSpot += StandardDeviations[j] * Variates[j];
        SpotValues[j] = exp(CurrentLogSpot);
    }
    return;
}
