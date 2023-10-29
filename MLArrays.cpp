//
//  MLArrays.cpp
//  MLArray
//
//  Created by Matthew liew on 17.08.23.
//

#include "MLArrays.hpp"
#include <algorithm>
#include <numeric>

MLArray::MLArray(unsigned long size) : Size(size), Capacity(size) {
    if (Size > 0) {
        valuePtr = new double[size];
        EndPtr = valuePtr;
        EndPtr += size;
    } else {
        valuePtr = 0;
        EndPtr = 0;
    }
}

MLArray::MLArray (const MLArray& original)
: Size(original.Size), Capacity(original.Size) {
    if (Size > 0) {
        valuePtr = new double[Size];
        EndPtr = valuePtr + Size;
        
        std::copy(original.valuePtr, original.EndPtr, valuePtr);
    } else {
        valuePtr = EndPtr = 0;
    }
}

MLArray::~MLArray() {
    if (valuePtr) delete [] valuePtr;
}

MLArray& MLArray::operator=(const MLArray& original) {
    if (&original == this) {
        return *this;
    }
    
    if (original.Size > Capacity) {
        if (Capacity > 0) delete [] valuePtr;
        valuePtr = new double[original.Size];
        Capacity = original.Size;
     }
    Size = original.Size;
    
    EndPtr = valuePtr + Size;
    
    std::copy(original.valuePtr, original.EndPtr, valuePtr);
    
    return *this;
}

void MLArray::resize(unsigned long newSize) {
    if (newSize > Capacity) {
        if (Capacity > 0) delete [] valuePtr;
        valuePtr = new double[newSize];
        Capacity = newSize;
    }
    Size = newSize;
    
    EndPtr = valuePtr + Size;
}

// operator overload
//
MLArray& MLArray::operator+=(const MLArray& operand) {
#ifdef RANGE_CHECKING
    if (Size != operand.size()) {
        throw "operator of two arrays must be of same size";
    }
#endif
    for (unsigned long i=0; i < Size; i++) {
        valuePtr[i] += operand[i];
    }
    return *this;
}

MLArray& MLArray::operator-=(const MLArray& operand) {
#ifdef RANGE_CHECKING
    if (Size != operand.size()) {
        throw "operator of two arrays must be of same size";
    }
#endif
    for (unsigned long i=0; i < Size; i++) {
        valuePtr[i] -= operand[i];
    }
    return *this;
}

MLArray& MLArray::operator*=(const MLArray& operand) {
#ifdef RANGE_CHECKING
    if (Size != operand.size()) {
        throw "operator of two arrays must be of same size";
    }
#endif
    for (unsigned long i=0; i < Size; i++) {
        valuePtr[i] *= operand[i];
    }
    return *this;
}

MLArray& MLArray::operator/=(const MLArray& operand) {
#ifdef RANGE_CHECKING
    if (Size != operand.size()) {
        throw "operator of two arrays must be of same size";
    }
#endif
    for (unsigned long i=0; i < Size; i++) {
        valuePtr[i] /= operand[i];
    }
    return *this;
}
//
MLArray& MLArray::operator+=(const double& operand) {
#ifdef RANGE_CHECKING
    if (Size != operand.size()) {
        throw "operator of two arrays must be of same size";
    }
#endif
    for (unsigned long i=0; i < Size; i++) {
        valuePtr[i] += operand;
    }
    return *this;
}

MLArray& MLArray::operator-=(const double& operand) {
#ifdef RANGE_CHECKING
    if (Size != operand.size()) {
        throw "operator of two arrays must be of same size";
    }
#endif
    for (unsigned long i=0; i < Size; i++) {
        valuePtr[i] -= operand;
    }
    return *this;
}

MLArray& MLArray::operator*=(const double& operand) {
#ifdef RANGE_CHECKING
    if (Size != operand.size()) {
        throw "operator of two arrays must be of same size";
    }
#endif
    for (unsigned long i=0; i < Size; i++) {
        valuePtr[i] *= operand;
    }
    return *this;
}

MLArray& MLArray::operator/=(const double& operand) {
#ifdef RANGE_CHECKING
    if (Size != operand.size()) {
        throw "operator of two arrays must be of same size";
    }
#endif// RANGE_CHECKING
    for (unsigned long i=0; i < Size; i++) {
        valuePtr[i] /= operand;
    }
    return *this;
}

// ---- apply operator ----

MLArray MLArray::apply(double f(double)) const {
    MLArray result(size());
    
    std::transform(valuePtr, EndPtr, result.valuePtr, f);
    
    return result;
}

// ---- end operators ----

MLArray& MLArray::operator=(const double& val) {
    for (unsigned long i=0; i < Size; i++) {
        valuePtr[i] = val;
    }
    return *this;
}

// sum min max
double MLArray::sum() const {
    return std::accumulate(valuePtr, EndPtr, 0.0);
}

double MLArray::min() const {
#ifdef RANGE_CHECKING
    if (Size == 0) throw("cannot take min of empty array")
#endif //RANGE_CHECKING
    double* tmp = valuePtr;
    double* endTmp = EndPtr;
    
    return *std::min_element(tmp, endTmp);
}

double MLArray::max() const {
#ifdef RANGE_CHECKING
    if (Size == 0) throw("cannot take max of empty array")
#endif //RANGE_CHECKING
    double* tmp = valuePtr;
    double* endTmp = EndPtr;
    
    return *std::max_element(tmp, endTmp);
}

