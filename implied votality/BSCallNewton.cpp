//
//  BSCallNewton.cpp
//  joshi_chp9
//
//  Created by Matthew liew on 10.10.23.
//

#include "BSCallNewton.hpp"
#include "BlackScholesFormulas.hpp"

BSCallNewton::BSCallNewton(double r_, double d_,
                           double T_, double Spot_, double Strike_)
: r(r_), d(d_), T(T_), Spot(Spot_), Strike(Strike_) {}

double BSCallNewton::Price(double Vol) const {
    return BlackScholesCall(Spot, Strike, r, d, Vol, T);
}

double BSCallNewton::Vega(double Vol) const {
    return BlackScholesCallVega(Spot, Strike, r, d, Vol, T);
}
