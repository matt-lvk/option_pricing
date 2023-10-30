//
//  SimpleMC7.hpp
//  joshi_chp5
//
//  Created by Matthew liew on 17.10.23.
//

#ifndef SimpleMC7_hpp
#define SimpleMC7_hpp

#include "Vanilla3.h"
#include "Parameters.h"
#include "MCStatistics.hpp"

void SimpleMonteCarlo5(const VanillaOption& TheOption,
                       double Spot,
                       const Parameters& Vol,
                       const Parameters& r,
                       unsigned long NumberOfPaths,
                       StatisticsMC& gatherer);



#endif /* SimpleMC7_hpp */
