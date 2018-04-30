#pragma once

#include <cmath>
#include <limits>
#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Math/MathFwdDecl.h"
#include "ToyUtility/Math/Radian.h"
#include "ToyUtility/Math/Degree.h"


namespace ToyUtility
{


class Vector2;
class Vector3;
class Vector4;
class Quaternion;


class Math
{
public:
    // Inverse cosine
    static Radian ACos(float val);
    static Radian ASin(float val);
    static Radian ATan(float val) { return Radian(std::atan(val)); }
    // Inverse tangent with two arguments, returns angle between the X axis and the point
    static Radian ATan2(float y, float x) { return Radian(std::atan2(y, x)); }
    static float Cos(const Radian& val) { return (float)std::cos(val.ValueRadians()); }
    static float Cos(float val) { return (float)std::cos(val); }
    static float Sin(const Radian& val) { return (float)std::sin(val.ValueRadians()); }
    static float Sin(float val) { return (float)std::sin(val); }
    static float Tan(const Radian& val) { return (float)std::tan(val.ValueRadians()); }
    static float Tan(float val) { return (float)std::tan(val); }
    // Square root
    static float Sqrt(float val) { return (float)std::sqrt(val); }
    // Square root
    static Radian Sqrt(const Radian& val) { return Radian(std::sqrt(val.ValueRadians())); }
    // Square root
    static Degree Sqrt(const Degree& val) { return Degree(std::sqrt(val.ValueRadians())); }
    // Square of the value
    static float Sqr(float val) { return val*val; }

    // Returns base raised to the provided power
    static float Pow(float base, float exponent) { return (float)std::pow(base, exponent); }

    // Returns euler number (e) raised to the provided power
    static float Exp(float val) { return (float)std::exp(val); }

    // Returns natural (base e) logarithm of the provided value
    static float Log(float val) { return (float)std::log(val); }

    // Returns base 2 logarithm of the provided value
    static float Log2(float val) { return (float)(std::log(val)/LOG2); }

    // Returns base N logarithm of the provided value
    static float LogN(float base, float val) { return (float)(std::log(val)/std::log(base)); }

    // Returns the sign of the provided value as 1 or -1
    static float Sign(float val);

    // Returns the sign of the provided value as 1 or -1
    static Radian Sign(const Radian& val) { return Radian(Sign(val.ValueRadians())); }

    // Returns the sign of the provided value as 1 or -1
    static Degree Sign(const Degree& val) { return Degree(Sign(val.ValueDegrees())); }

    // Square root followed by an inverse
    static float InvSqrt(float val);

    // Returns the absolute value
    static float Abs(float val) { return float(std::fabs(val)); }

    // Returns the absolute value
    static Degree Abs(const Degree& val) { return Degree(std::fabs(val.ValueDegrees())); }

    // Returns the absolute value
    static Radian Abs(const Radian& val) { return Radian(std::fabs(val.ValueRadians())); }
    
    // Returns the nearest integer equal or higher to the provided value
    static float Ceil(float val) { return (float)std::ceil(val); }

    // Returns the nearest integer equal or higher to the provided value
    static int CeilToInt(float val) { return (int)std::ceil(val); }

    // Returns the integer nearest to the provided value
    static float Round(float val) { return (float)std::floor(val + 0.5f); }

    // Returns the integer nearest to the provided value
    static int RoundToInt(float val) { return (int)std::floor(val + 0.5f); }

    // Divides an integer by another integer and returns the result, rounded up. Only works if both integers are
    // positive. 
    template<class T>
    static constexpr T DivideAndRoundUp(T n, T d) { return (n + d - 1) / d; }

    // Returns the nearest integer equal or lower of the provided value
    static float Floor(float val) { return (float)std::floor(val); }

    // Returns the nearest integer equal or lower of the provided value
    static int FloorToInt(float val) { return (int)std::floor(val); }

    // Clamp a value within an inclusive range
    template<typename T>
    static T Clamp(T val, T minval, T maxval)
    {
	    assert (minval <= maxval && "Invalid clamp range");
	    return std::max(std::min(val, maxval), minval);
    }

    // Clamp a value within an inclusive range [0..1]
    template<typename T>
    static T Clamp01(T val)
    {
	    return std::max(std::min(val, (T)1), (T)0);
    }

    // Checks if the value is a valid number
    static bool IsNaN(float f)
    {
	    return f != f;
    }

    // Compare two floats, using tolerance for inaccuracies
    static bool ApproxEquals(float a, float b, 
	    float tolerance = std::numeric_limits<float>::epsilon())
    {
	    return fabs(b - a) <= tolerance;
    }

    // Compare two doubles, using tolerance for inaccuracies
    static bool ApproxEquals(double a, double b, 
	    double tolerance = std::numeric_limits<double>::epsilon())
    {
	    return fabs(b - a) <= tolerance;
    }

    // Compare two 2D vectors, using tolerance for inaccuracies
    static bool ApproxEquals(const Vector2& a, const Vector2& b, 
	    float tolerance = std::numeric_limits<float>::epsilon());

    // Compare two 3D vectors, using tolerance for inaccuracies
    static bool ApproxEquals(const Vector3& a, const Vector3& b, 
	    float tolerance = std::numeric_limits<float>::epsilon());

    // Compare two 4D vectors, using tolerance for inaccuracies
    static bool ApproxEquals(const Vector4& a, const Vector4& b, 
	    float tolerance = std::numeric_limits<float>::epsilon());

    // Compare two quaternions, using tolerance for inaccuracies
    static bool ApproxEquals(const Quaternion& a, const Quaternion& b, 
	    float tolerance = std::numeric_limits<float>::epsilon());

    // Calculates the tangent space vector for a given set of positions / texture coords
    static Vector3 CalculateTriTangent(const Vector3& position1, const Vector3& position2, 
	    const Vector3& position3, float u1, float v1, float u2, float v2, float u3, float v3);

    static constexpr float POS_INFINITY = std::numeric_limits<float>::infinity();
    static constexpr float NEG_INFINITY = -std::numeric_limits<float>::infinity();
    static constexpr float PI = 3.14159265358979323846f;
    static constexpr float TWO_PI = (float)(2.0f * PI);
    static constexpr float HALF_PI = (float)(0.5f * PI);
    static constexpr float DEG2RAD = PI / 180.0f;
    static constexpr float RAD2DEG = 180.0f / PI;
    static const float LOG2;
};


} // end of namespace ToyUtility