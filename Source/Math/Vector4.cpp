#include "ToyUtility/Math/Vector4.h"
#include "ToyUtility/Math/Math.h"


namespace ToyUtility
{


const Vector4 Vector4::ZERO(0, 0, 0, 0);

bool Vector4::isNaN() const
{
    return Math::IsNaN(x) || Math::IsNaN(y) || Math::IsNaN(z) || Math::IsNaN(w);
}


} // end of namespace ToyUtility