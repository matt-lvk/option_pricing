//
//  bisectionMain.cpp
//  joshi_chp9
//
//  Created by Matthew liew on 02.11.23.
//

#include <iostream>
using namespace std;
#include <cmath>
#include "BSCallClass.hpp"
#include "BlackScholesFormulas.hpp"
#include "Bisection.hpp"


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
    
    double low, high, tolerance;
    
    cout << "\nlower guess\n";
    cin >> low;
    
    cout << "\nhigh guess\n";
    cin >> high;
        
    cout << "\ntolerance\n";
    cin >> tolerance;
    
    BSCall theCall(r, d, Expiry, Spot, Strike);
    double vol = Bisection(Price, low, high, tolerance, theCall);
    double PriceTwo = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);
    
    cout << "\n vol is " << vol << "\n";
    cout << "\n price from bisection is " << PriceTwo << "\n";
    
    return 0;
    
}
