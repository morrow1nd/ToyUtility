#include "ToyUtility/Math/Math.h"
#include "ToyUtility/Math/Vector2.h"
#include "ToyUtility/Math/Vector3.h"
#include "ToyUtility/Math/Vector4.h"
#include "ToyUtility/Math/Quaternion.h"


namespace ToyUtility
{


const float Math::LOG2 = std::log(2.0f);

Radian Math::ACos(float val)
{
    if (-1.0f < val)
    {
        if(val < 1.0f)
            return Radian(std::acos(val));
        else
            return Radian(0.0f);
    }
    else
    {
        return Radian(PI);
    }
}

Radian Math::ASin(float val)
{
    if (-1.0f < val)
    {
        if (val < 1.0f)
            return Radian(std::asin(val));
        else
            return Radian(HALF_PI);
    }
    else
    {
        return Radian(-HALF_PI);
    }
}

float Math::Sign(float val)
{
    if (val > 0.0f)
        return 1.0f;

    if (val < 0.0f)
        return -1.0f;

    return 0.0f;
}

float Math::InvSqrt(float val)
{
    return 1.0f / sqrt(val);
}

bool Math::ApproxEquals(const Vector2& a, const Vector2& b, float tolerance)
{
    return fabs(b.x - a.x) <= tolerance && fabs(b.y - a.y) <= tolerance;
}

bool Math::ApproxEquals(const Vector3& a, const Vector3& b, float tolerance)
{
    return fabs(b.x - a.x) <= tolerance && fabs(b.y - a.y) <= tolerance && fabs(b.z - a.z) <= tolerance;
}

bool Math::ApproxEquals(const Vector4& a, const Vector4& b, float tolerance)
{
    return fabs(b.x - a.x) <= tolerance && fabs(b.y - a.y) <= tolerance && fabs(b.z - a.z) <= tolerance &&
        fabs(b.w - a.w) <= tolerance;
}

bool Math::ApproxEquals(const Quaternion& a, const Quaternion& b, float tolerance)
{
    return fabs(b.x - a.x) <= tolerance && fabs(b.y - a.y) <= tolerance && fabs(b.z - a.z) <= tolerance &&
        fabs(b.w - a.w) <= tolerance;
}

Vector3 Math::CalculateTriTangent(const Vector3& position1, const Vector3& position2,
    const Vector3& position3, float u1, float v1, float u2, float v2, float u3, float v3)
{
    Vector3 side0 = position1 - position2;
    Vector3 side1 = position3 - position1;

    // Calculate face normal
    Vector3 normal = side1.cross(side0);
    normal.normalize();

    // Now we use a formula to calculate the tangent. 
    float deltaV0 = v1 - v2;
    float deltaV1 = v3 - v1;
    Vector3 tangent = deltaV1 * side0 - deltaV0 * side1;
    tangent.normalize();

    // Calculate binormal
    float deltaU0 = u1 - u2;
    float deltaU1 = u3 - u1;
    Vector3 binormal = deltaU1 * side0 - deltaU0 * side1;
    binormal.normalize();

    // Now, we take the cross product of the tangents to get a vector which 
    // should point in the same direction as our normal calculated above. 
    // If it points in the opposite direction (the dot product between the normals is less than zero), 
    // then we need to reverse the s and t tangents. 
    // This is because the triangle has been mirrored when going from tangent space to object space.
    // reverse tangents if necessary.
    Vector3 tangentCross = tangent.cross(binormal);
    if (tangentCross.dot(normal) < 0.0f)
    {
        tangent = -tangent;
        binormal = -binormal;
    }

    return tangent;
}


} // end of namespace ToyUtility