#include "Normals.hpp"
#include <cstdlib>
#include <cmath>
#include <stdexcept>

using namespace std;

// modified Box-Muller
double GetOneGaussianByBoxMuller() {
    double result;
    double x;
    double y;
    double sizeSquared;
    
    do {
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        
        sizeSquared = x*x + y*y;
    } while (sizeSquared > 1.0);
    
    result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);
    
    return result;
}

double NormalDensity(double x) {
    return exp(-x*x/2) / sqrt(2 * M_PI);
}

double CumulativeNormal(double x) {
    static double a[5] = { 0.319381530,
                           -0.356563782,
                           1.781477937,
                           -1.821255978,
                           1.330274429 };
    
    static double p = 0.2316419;
    static double c = 0.918938533204672;
    double y;
    
    double t = 1/(1 + fabs(x) * p);
    double s = ((((a[4]*t + a[3])*t + a[2])*t + a[1])*t + a[0])*t;
    
    y = s * exp(-0.5 * x * x - c);
    
    if (x > 0) y = 1 - y;
    
    return y;
}

// Beasley-Springer-Moro algorithm
double InverseCumulativeNormal(double u) {
    if (u < 0 || u > 1) {
        throw std::invalid_argument("Argument to InverseCumulativeNormal must be in [0,1]");
    }
    
    static double a[4] = { 2.50662823884,
                           -18.61500062529,
                           41.39119773534,
                           -25.44106049637 };
    
    static double b[4] = { -8.47351093090,
                           23.08336743743,
                           -21.06224101826,
                           3.13082909833 };
    
    static double c[9] = { 0.3374754822726147,
                           0.9761690190917186,
                           0.1607979714918209,
                           0.0276438810333863,
                           0.0038405729373609,
                           0.0003951896511919,
                           0.0000321767881768,
                           0.0000002888167364,
                           0.0000003960315187 };
    
    double y = u - 0.5;
    double r;
    double x;
    
    if (fabs(y) < 0.42) {
        r = y * y;
        x = y * (((a[3]*r + a[2]) * r + a[1]) * r + a[0])/((((
            b[3]*r + b[2])*r + b[1])*r + b[0])*r + 1);
    } else {
        r = u;
        if (y > 0) r = 1-u;
        r = log(-log(r));
        x = c[0] + r*(c[1] + r*(c[2] + r*(c[3] + r*(c[4] + r*(
            c[5] + r*(c[6] + r*(c[7] + r*c[8])))))));
        if (y < 0) x = -x;
    }
    return x;
}

