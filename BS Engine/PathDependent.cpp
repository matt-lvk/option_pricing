//
//  PathDependent.cpp
//  joshi_chp7
//
//  Created by Matthew liew on 31.10.23.
//

#include "PathDependent.hpp"

PathDependent::PathDependent(const MJArray& LookAtTimes_)
: LookAtTimes(LookAtTimes_) {}

const MJArray& PathDependent::GetLookAtTimes() const {
    return LookAtTimes;
}
