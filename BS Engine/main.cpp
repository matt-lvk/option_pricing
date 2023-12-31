//
//  main.cpp
//  joshi_chp7
//
//  Created by Matthew liew on 31.10.23.
//

#include <iostream>
using namespace std;
#include "ParkMiller.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include "PathDependentAsian.hpp"
#include "BlackScholesEngine.hpp"
#include "AntiThetic.h"

int main() {
    double Expiry, Strike, Spot, Vol, r, d;
    unsigned long NumberOfPaths;
    unsigned NumberOfDates;
    
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    
    cout << "\nEnter strike\n";
    cin >> Strike;
    
    cout << "\nEnter spot\n";
    cin >> Spot;
    
    cout << "\nEnter vol\n";
    cin >> Vol;
    
    cout << "\nr\n";
    cin >> r;
    
    cout << "\nd\n";
    cin >> d;
    
    cout << "\nNumber of dates\n";
    cin >> NumberOfDates;
    
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;
    
    PayOffCall thePayoff(Strike);
    MJArray times(NumberOfDates);
    
    for (unsigned long i=0; i < NumberOfDates; i++) {
        times[i] = (i + 1.0) * Expiry / NumberOfDates;
    }
    
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);
    
    PathDependentAsian theOption(times, Expiry, thePayoff);
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    
    RandomParkMiller generator(NumberOfDates);
    AntiThetic GenTwo(generator);
    
    BSEngine theEngine(theOption, rParam, dParam, VolParam, GenTwo, Spot);
    
    theEngine.DoSimulation(gathererTwo, NumberOfPaths);
    
    vector<vector<double> > results = gathererTwo.GetResultsSoFar();
    
    cout << "\nFor the Asian call price the results are \n";
    {
        for (unsigned long i=0; i < results.size(); i++) {
            for (unsigned long j=0; j < results[i].size(); j++)
                cout << results[i][j] << " ";
            cout << "\n";
        }}
    
    
    return 0;
    
}
