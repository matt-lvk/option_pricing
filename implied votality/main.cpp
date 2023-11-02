//
//  NewtonMain.cpp
//  joshi_chp9
//
//  Created by Matthew liew on 02.11.23.
//

#include "NewtonRaphson.h"
#include <cmath>
#include "BSCallNewton.hpp"
#include "BlackScholesFormulas.hpp"
#include <iostream>
using namespace std;

int main () {
    double Expiry;
    double Strike;
    double Spot;
    double r;
    double d;
    double Price;

    cout << "\nEnter expiry\n";
    cin >> Expiry;

    cout << "\nStrike\n";
    cin >> Strike;

    cout << "\nEnter spot\n";
    cin >> Spot;

    cout << "\nEnter d\n";
    cin >> d;

    cout << "\nr\n";
    cin >> r;

    cout << "\nPrice of Call\n";
    cin >> Price;

    double start, tolerance;

    cout << "\nInitial guess\n";
    cin >> start;

    cout << "\ntolerance\n";
    cin >> tolerance;

    BSCallNewton theCall(r, d, Expiry, Spot, Strike);

    double vol = NewtonRaphson<BSCallNewton, &BSCallNewton::Price, &BSCallNewton::Vega>(Price, start, tolerance, theCall);


    double nextPrice = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);

    cout << "\nImplied vol is " << vol << "\n";
    cout << "\nPrice according to Black Scholes is " << nextPrice << "\n";

    return 0;

}
