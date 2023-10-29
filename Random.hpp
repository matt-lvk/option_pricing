//
//  Random.hpp
//  joshi_chp6
//
//  Created by Matthew liew on 22.10.23.
//

#ifndef Random_hpp
#define Random_hpp

#include <Eigen/Dense>

class RandomBase {
public:
    RandomBase(unsigned long Dimensionality);
    inline unsigned long GetDimensionality() const;
    
    virtual RandomBase* clone() const = 0;
    virtual void Skip(unsigned long numberOfPaths)=0;
    virtual void GetUniforms(Eigen::ArrayXXf& variates) = 0;
    virtual void SetSeed(unsigned long Seed) = 0;
    virtual void Reset() = 0;
    
    virtual void GetGaussians(Eigen::ArrayXXf& variates);
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    
private:
    unsigned long Dimensionality;
};

unsigned long RandomBase::GetDimensionality() const {
    return Dimensionality;
}

#endif /* Random_hpp */
