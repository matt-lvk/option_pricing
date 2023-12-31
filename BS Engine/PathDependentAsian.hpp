//
//  PathDependentAsian.hpp
//  joshi_chp7
//
//  Created by Matthew liew on 31.10.23.
//

#ifndef PathDependentAsian_hpp
#define PathDependentAsian_hpp

#include "PathDependent.hpp"
#include "PayOffBridge.h"

class PathDependentAsian : public PathDependent {
public:
    PathDependentAsian(const MJArray& LookAtTimes_,
                       double DeliveryTime_,
                       const PayOffBridge& ThePayOff_);
    
    virtual unsigned long MaxNumberOfCashFlows() const;
    virtual MJArray PossibleCashFlowTimes() const;
    virtual unsigned long CashFlows(const MJArray& SpotValues,
                                    std::vector<CashFlow>& GeneratedFlows) const;
    virtual ~PathDependentAsian(){}
    virtual PathDependent* clone() const;
  
private:
    double DeliveryTime;
    PayOffBridge ThePayoff;
    unsigned long NumberOfTimes;
};

#endif /* PathDependentAsian_hpp */
