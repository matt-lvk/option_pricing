//
//  Bisection.hpp
//  joshi_chp9
//
//  Created by Matthew liew on 02.10.23.
//

#ifndef Bisection_hpp
#define Bisection_hpp

template <class T>
double Bisection(double Target,
                 double Low,
                 double High,
                 double Tol,
                 T TheFunction) {
    
    // initiate
    double x = 0.5 * (Low + High);
    double y = TheFunction(x);
    
    do {
        if (y < Target) Low = x;
        if (y > Target) High = x;
        
        x = 0.5 * (Low + High);
        y = TheFunction(x);
    } while (fabs(y - Target) > Tol);
    
    return x;
}

#endif /* Bisection_hpp */
