#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Math/Vector2.h"


namespace ToyUtility
{


/** A line in 2D space represented with an origin and direction. */
class Line2
{
public:
    Line2()
        :mOrigin(Vector2::ZERO), mDirection(Vector2::UNIT_X)
    {
    }

    Line2(const Vector2& origin, const Vector2& direction)
        :mOrigin(origin), mDirection(direction)
    {
    }

    void setOrigin(const Vector2& origin)
    {
        mOrigin = origin;
    }
    const Vector2& getOrigin(void) const
    {
        return mOrigin;
    }

    void setDirection(const Vector2& dir)
    {
        mDirection = dir;
    }
    const Vector2& getDirection(void) const
    {
        return mDirection;
    }

    /** Gets the position of a point t units along the line. */
    Vector2 getPoint(float t) const
    {
        return Vector2(mOrigin + (mDirection * t));
    }

    /** Gets the position of a point t units along the line. */
    Vector2 operator*(float t) const
    {
        return getPoint(t);
    }

    /** Line/Line intersection, returns boolean result and distance to intersection point. */
    std::pair<bool, float> intersects(const Line2& line) const;

protected:
    Vector2 mOrigin;
    Vector2 mDirection;
};


} // end of namespace ToyUtility