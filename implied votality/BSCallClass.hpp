//
//  BSCallClass.hpp
//  joshi_chp9
//
//  Created by Matthew liew on 22.10.23.
//

#ifndef BSCallClass_hpp
#define BSCallClass_hpp

class BSCall {
public:
    BSCall (double r_,
            double d_,
            double T,
            double Spot_,
            double Strike_);
    double operator()(double Vol) const;

private:
    double r;
    double d;
    double T;
    double Spot;
    double Strike;
};

#endif /* BSCallClass_hpp */
