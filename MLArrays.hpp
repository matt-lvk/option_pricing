//
//  MLArrays.hpp
//  MLArray
//
//  Created by Matthew liew on 17.08.23.
//

#ifndef MLArrays_hpp
#define MLArrays_hpp

#ifdef USE_VAL_ARRAY
#include <valarray>
#include <iostream>
typedef std::valarray<double> MLArray;
#else

class MLArray {
public:
    explicit MLArray (unsigned long size = 0);
    MLArray(const MLArray& original);
    ~MLArray();
    
    MLArray& operator=(const MLArray& original);
    MLArray& operator=(const double& val);
    void resize(unsigned long newSize);

    // overload operands
    MLArray& operator+=(const MLArray& operand);
    MLArray& operator-=(const MLArray& operand);
    MLArray& operator*=(const MLArray& operand);
    MLArray& operator/=(const MLArray& operand);
    
    MLArray& operator+=(const double& operand);
    MLArray& operator-=(const double& operand);
    MLArray& operator*=(const double& operand);
    MLArray& operator/=(const double& operand);
    
    MLArray apply(double f(double)) const; // apply function f
    
    inline double operator[](unsigned long i) const;
    inline double& operator[](unsigned long i);
    
    inline unsigned long size() const;
    
    double sum() const;
    double min() const;
    double max() const;
    
private:
    double* valuePtr;
    double* EndPtr;
    
    unsigned long Size;
    unsigned long Capacity;

};

// range checking
inline double MLArray::operator[](unsigned long i) const {
#ifdef RANGE_CHECKING
    if (i >= Size) {
        throw("Index out of range");
    }
#endif
    return valuePtr[i];
}

inline double& MLArray::operator[](unsigned long i) {
#ifdef RANGE_CHECKING
    if (i >= Size) {
        throw("Index out of range");
    }
#endif
    return valuePtr[i];
}

inline unsigned long MLArray::size() const {
    return Size;
}


#endif /* USE_VAL_ARRAY */

#endif /* MLArrays_hpp */
