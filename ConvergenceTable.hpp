//
//  ConvergenceTable.hpp
//  joshi_chp5
//
//  Created by Matthew liew on 22.10.23.
//

#ifndef ConvergenceTable_hpp
#define ConvergenceTable_hpp

#include "MCStatistics.hpp"
#include "Wrapper.hpp"

class ConvergenceTable : public StatisticsMC {
public:
    ConvergenceTable(const Wrapper<StatisticsMC>& Inner_) ;
    
    virtual StatisticsMC* clone() const;
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    
private:
    Wrapper<StatisticsMC> Inner;
    std::vector<std::vector<double> > ResultsSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;
};

#endif /* ConvergenceTable_hpp */
