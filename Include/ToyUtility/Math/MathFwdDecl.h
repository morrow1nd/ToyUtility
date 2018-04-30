#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


// Enum used for object construction specifying the object should be zero initializes
enum TU_ZERO
{
    TuZero
};

// Enum used for matrix/quaternion constructor specifying it should be initialized with an identity value
enum TU_IDENTITY
{
    TuIdentity
};

// Values that represent in which order are euler angles applied when used in transformations
enum class EulerAngleOrder
{
    XYZ,
    XZY,
    YXZ,
    YZX,
    ZXY,
    ZYX
};


} // end of namespace ToyUtility