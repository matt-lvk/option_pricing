//
//  BSCallNewton.hpp
//  joshi_chp9
//
//  Created by Matthew liew on 10.10.23.
//

#ifndef BSCallNewton_hpp
#define BSCallNewton_hpp

class BSCallNewton {
public:
    BSCallNewton(double r_, double d_,
                double T_, double Spot_, double Strike_);
    double Price(double Vol) const;
    double Vega(double Vol) const;
    
private:
    double r;
    double d;
    double T;
    double Spot;
    double Strike;
};
#endif /* BSCallNewton_hpp */
