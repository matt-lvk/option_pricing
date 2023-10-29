//
//  SimpleMC8.hpp
//  joshi_chp6
//
//  Created by Matthew liew on 25.10.23.
//

#ifndef SimpleMC8_hpp
#define SimpleMC8_hpp

#include "Vanilla3.h"
#include "Parameters.h"
#include "Random.hpp"
#include "MCStatistics.hpp"

void SimpleMonteCarlo6 (const VanillaOption& TheOption,
                       double Spot,
                       const Parameters& Vol,
                       const Parameters& r,
                       unsigned long NumberOfPaths,
                       StatisticsMC& gatherer,
                       RandomBase& generator);

#endif /* SimpleMC8_hpp */
