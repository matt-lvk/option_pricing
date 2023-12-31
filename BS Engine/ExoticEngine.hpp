//
//  ExoticEngine.hpp
//  joshi_chp7
//
//  Created by Matthew liew on 31.10.23.
//

#ifndef ExoticEngine_hpp
#define ExoticEngine_hpp

#include "wrapper.h"
#include "Parameters.h"
#include "PathDependent.hpp"
#include "MCStatistics.h"
#include <vector>

class ExoticEngine {
public:
    ExoticEngine(const Wrapper<PathDependent>& TheProduct,
                 const Parameters& r) ;
    
    virtual void GetOnePath(MJArray& SpotValues) = 0;
    void DoSimulation(StatisticsMC& TheGatherer,
                      unsigned long NumberOfPaths);
    
    virtual ~ExoticEngine(){}
    double DoOnePath(const MJArray& SpotValues) const;
    
private:
    Wrapper<PathDependent> TheProduct;
    Parameters r;
    MJArray Discounts;
    mutable std::vector<CashFlow> TheseCashFlows;
};

#endif /* ExoticEngine_hpp */
