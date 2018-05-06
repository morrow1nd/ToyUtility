#pragma once

//#include <cmath>
#include <cassert>
#include <utility>
#include <algorithm>
#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Math/Math.h"


namespace ToyUtility
{


/** A three dimensional vector with integer coordinates. */
struct Vector3I
{
    int32 x = 0;
    int32 y = 0;
    int32 z = 0;

    Vector3I()
    {
    }

    Vector3I(int32 x, int32 y, int32 z)
        :x(x), y(y), z(z)
    {
    }

    int32 operator[] (size_t i) const
    {
        assert(i < 3);

        switch (i)
        {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: return 0;
        }
    }

    int32& operator[] (size_t i)
    {
        assert(i < 3);

        switch (i)
        {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: return x;
        }
    }

    Vector3I& operator= (const Vector3I& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;

        return *this;
    }

    bool operator== (const Vector3I& rhs) const
    {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    bool operator!= (const Vector3I& rhs) const
    {
        return !operator==(rhs);
    }
};


} // end of namespace ToyUtility