#include "ToyUtility/Math/Degree.h"
#include "ToyUtility/Math/Math.h"
#include "ToyUtility/Math/Radian.h"


namespace ToyUtility
{

Degree::Degree(const Radian& r)
    :m_Deg(r.ValueDegrees())
{
}

Degree Degree::Wrap()
{
    m_Deg = fmod(m_Deg, 360.0f);

    if (m_Deg < 0)
        m_Deg += 360.0f;

    return *this;
}

Degree& Degree::operator= (const Radian& r)
{
    m_Deg = r.ValueDegrees();
    return *this;
}

Degree Degree::operator+ (const Radian& r) const
{
    return Degree(m_Deg + r.ValueDegrees());
}

Degree& Degree::operator+= (const Radian& r)
{
    m_Deg += r.ValueDegrees();
    return *this;
}

Degree Degree::operator- (const Radian& r) const
{
    return Degree(m_Deg - r.ValueDegrees());
}

Degree& Degree::operator-= (const Radian& r)
{
    m_Deg -= r.ValueDegrees();
    return *this;
}

float Degree::ValueRadians() const
{
    return m_Deg * Math::DEG2RAD;
}

} // end of namespace ToyUtility