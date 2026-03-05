#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include "core/constants.h"
#include <cmath>

namespace rtc
{
    inline bool float_equals(float a, float b)
    {
        return std::fabs(a - b) < EPSILON;
    }
}

#endif // !MATH_UTILS_H
