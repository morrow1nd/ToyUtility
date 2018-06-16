#pragma once

#include <cassert>
#include <utility>
#include <algorithm>
#include "ToyUtility/Math/Math.h"


namespace ToyUtility
{


class Rational
{
public:
    Rational()
        :
        m_Numerator(0),
        m_Denominator(1)
    {}

    Rational(uint32 numerator, uint32 denominator)
        :
        m_Numerator(numerator),
        m_Denominator(denominator)
    {}

    uint32 Numerator() const { return m_Numerator; }
    uint32 Denominator() const { return m_Denominator; }


private:
    uint32 m_Numerator;
    uint32 m_Denominator;
};


} // end of namespace ToyUtility