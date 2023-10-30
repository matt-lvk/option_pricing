//
//  main.cpp
//  joshi_chp5
//
//  Created by Matthew liew on 17.10.23.
//
#include "SimpleMC7.hpp"
#include <iostream>
using namespace std;
#include "Vanilla3.h"
#include "MCStatistics.hpp"


int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    
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
     
     cout << "\nNumber of paths\n";
     cin >> NumberOfPaths;
    
    PayOffCall thePayOff(Strike);
    
    VanillaOption theOption(thePayOff, Expiry);
    
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    
    StatisticsMean gatherer;
    
    SimpleMonteCarlo5(theOption,
                      Spot,
                      VolParam,
                      rParam,
                      NumberOfPaths,
                      gatherer
                      );
    
    vector<vector<double>> results = gatherer.GetResultsSoFar();
    
    cout << "\nFor the call price the results are \n";
    for (unsigned long i=0; i < results.size(); i++) {
        for (unsigned long j=0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        
        cout << "\n";
        }
    }
    
    double tmp;
    cin >> tmp;
    
    return 0;
    
}
