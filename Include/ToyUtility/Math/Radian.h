#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


class Degree;

class Radian
{
public:
    explicit Radian(float r = 0.0f) : m_Rad(r) { }
    Radian(const Degree& d);

    Radian& operator=(const float& f) { m_Rad = f; return *this; }
    Radian& operator=(const Radian& r) { m_Rad = r.m_Rad; return *this; }
    Radian& operator=(const Degree& d);

    // Return the value of the angle in degrees
    float ValueDegrees() const;

    // Return the value of the angle in radians
    float ValueRadians() const { return m_Rad; }

    // Wraps the angle in [0, 2 * PI) range
    Radian Wrap();

    const Radian& operator+ () const { return *this; }
    Radian operator+ (const Radian& r) const { return Radian (m_Rad + r.m_Rad); }
    Radian operator+ (const Degree& d) const;
    Radian& operator+= (const Radian& r) { m_Rad += r.m_Rad; return *this; }
    Radian& operator+= (const Degree& d);
    Radian operator- () const { return Radian(-m_Rad); }
    Radian operator- (const Radian& r) const { return Radian (m_Rad - r.m_Rad); }
    Radian operator- (const Degree& d) const;
    Radian& operator-= (const Radian& r) { m_Rad -= r.m_Rad; return *this; }
    Radian& operator-= (const Degree& d);
    Radian operator* (float f) const { return Radian (m_Rad * f); }
    Radian operator* (const Radian& f) const { return Radian (m_Rad * f.m_Rad); }
    Radian& operator*= (float f) { m_Rad *= f; return *this; }
    Radian operator/ (float f) const { return Radian (m_Rad / f); }
    Radian& operator/= (float f) { m_Rad /= f; return *this; }

    friend Radian operator* (float lhs, const Radian& rhs) { return Radian(lhs * rhs.m_Rad); }
    friend Radian operator/ (float lhs, const Radian& rhs) { return Radian(lhs / rhs.m_Rad); }
    friend Radian operator+ (Radian& lhs, float rhs) { return Radian(lhs.m_Rad + rhs); }
    friend Radian operator+ (float lhs, const Radian& rhs) { return Radian(lhs + rhs.m_Rad); }
    friend Radian operator- (const Radian& lhs, float rhs) { return Radian(lhs.m_Rad - rhs); }
    friend Radian operator- (const float lhs, const Radian& rhs) { return Radian(lhs - rhs.m_Rad); }

    bool operator<  (const Radian& r) const { return m_Rad <  r.m_Rad; }
    bool operator<= (const Radian& r) const { return m_Rad <= r.m_Rad; }
    bool operator== (const Radian& r) const { return m_Rad == r.m_Rad; }
    bool operator!= (const Radian& r) const { return m_Rad != r.m_Rad; }
    bool operator>= (const Radian& r) const { return m_Rad >= r.m_Rad; }
    bool operator>  (const Radian& r) const { return m_Rad >  r.m_Rad; }


private:
    float m_Rad;
};


} // end of namespace ToyUtility