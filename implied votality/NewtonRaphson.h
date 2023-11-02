//
//  NewtonRaphson.h
//  joshi_chp9
//
//  Created by Matthew liew on 08.10.23.
//

#ifndef NewtonRaphson_h
#define NewtonRaphson_h

#include <cmath>

template <class T,
            double (T::*Value)(double) const,
            double (T::*Derivative)(double) const>
double NewtonRaphson(double Target, double Start,
                     double Tolerance, const T& TheObject) {
    
    double y = (TheObject.*Value)(Start);
    double x = Start;
    
    do {
        double d = (TheObject.*Derivative)(x);
        x += (Target - y) / d;
        y = (TheObject.*Value)(x);
    } while (fabs(y - Target) > Tolerance);
    
    return x;
}

#endif /* NewtonRaphson_h */
