#pragma once

#include <cassert>
#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


/** A four dimensional vector with integer coordinates. */
struct Vector4I
{
    int32 x = 0;
    int32 y = 0;
    int32 z = 0;
    int32 w = 0;

    Vector4I()
    {
    }

    Vector4I(int32 x, int32 y, int32 z, int32 w)
        :x(x), y(y), z(z), w(w)
    {
    }

    int32 operator[] (size_t i) const
    {
        assert(i < 4);

        switch (i)
        {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        case 3: return w;
        default: return 0;
        }
    }

    int32& operator[] (size_t i)
    {
        assert(i < 4);

        switch (i)
        {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        case 3: return w;
        default: return x;
        }
    }

    Vector4I& operator= (const Vector4I& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        w = rhs.w;

        return *this;
    }

    bool operator== (const Vector4I& rhs) const
    {
        return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
    }

    bool operator!= (const Vector4I& rhs) const
    {
        return !operator==(rhs);
    }
};


} // end of namespace ToyUtility