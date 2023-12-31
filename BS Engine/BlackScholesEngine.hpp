//
//  BlackScholesEngine.hpp
//  joshi_chp7
//
//  Created by Matthew liew on 31.10.23.
//

#ifndef BlackScholesEngine_hpp
#define BlackScholesEngine_hpp

#include "Random2.h"
#include "ExoticEngine.hpp"

class BSEngine : public ExoticEngine {
public:
    BSEngine(const Wrapper<PathDependent>& TheProduct_,
             const Parameters& r_,
             const Parameters& d_,
             const Parameters& Vol_,
             const Wrapper<RandomBase>& TheGenerator_,
             double Spot_);
    
    virtual void GetOnePath(MJArray& SpotValues);
    virtual ~BSEngine() {}
    
private:
    Wrapper<RandomBase> TheGenerator;
    MJArray Drifts;
    MJArray StandardDeviations;
    double LogSpot;
    unsigned long NumberOfTimes;
    MJArray Variates;
};

#endif /* BlackScholesEngine_hpp */
