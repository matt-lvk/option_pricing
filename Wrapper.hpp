//
//  Wrapper.hpp
//  joshi_chp5
//
//  Created by Matthew liew on 22.10.23.
//

#ifndef Wrapper_hpp
#define Wrapper_hpp

template < class T>
class Wrapper {
private:
    T* DataPtr;
    
public:
    Wrapper() { DataPtr = 0; }
    
    Wrapper(const T& inner) {
        DataPtr = inner.clone();
    }
    
    ~Wrapper() {
        if (DataPtr != 0) {
            delete DataPtr;
        }
    }
    
    Wrapper(const Wrapper<T>& original) {
        if (original.DataPtr != 0) {
            DataPtr = original.DataPtr -> clone();
        } else {
            DataPtr = 0;
        }
    }
    
    Wrapper& operator = (const Wrapper<T>& original) {
        if (this != &original) {
            if (DataPtr != 0) {
                delete DataPtr;
            }
            
            DataPtr = (original.DataPtr != 0) ? original.DataPtr -> clone() : 0;
        }
        
        return *this;
    }
    
    T& operator* () {
        return *DataPtr;
    }
    
    const T& operator*() const {
        return *DataPtr;
    }

    T* operator -> () {
        return DataPtr;
    }
    
    const T* const operator->() const {
        return DataPtr;
    }
    
};
#endif /* Wrapper_hpp */
