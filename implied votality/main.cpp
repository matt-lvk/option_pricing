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

    cout << "Enter expiry";
    cin >> Expiry;

    cout << "Strike";
    cin >> Strike;

    cout << "Enter spot";
    cin >> Spot;

    cout << "Enter dividen";
    cin >> d;

    cout << "risk free interest, r";
    cin >> r;

    cout << "Price of Call";
    cin >> Price;

    double start, tolerance;

    cout << "Initial guess";
    cin >> start;

    cout << "tolerance";
    cin >> tolerance;

    BSCallNewton theCall(r, d, Expiry, Spot, Strike);

    double vol = NewtonRaphson<BSCallNewton, &BSCallNewton::Price, &BSCallNewton::Vega>(Price, start, tolerance, theCall);


    double nextPrice = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);

    cout << "Implied vol is " << vol << endl;
    cout << "Price according to Black Scholes is " << nextPrice << endl;

    return 0;

}
