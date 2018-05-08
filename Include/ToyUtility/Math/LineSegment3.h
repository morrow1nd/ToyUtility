#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Math/Vector3.h"
#include <array>
#include <utility>


namespace ToyUtility
{


class Ray;


/** Represents a line segment in three dimensional space defined by a start and an end point. */
class LineSegment3
{
public:
    LineSegment3();
    LineSegment3(const Vector3& start, const Vector3& end);

    /**
    * Find the nearest point on the line segment and the provided ray.
    *
    * @return	Set of nearest points and distance from the points. First nearest point is a point along the ray,
    *			while the second is along the line segment.
    *
    * @note	If segment and ray are parallel the set of points at the segment origin are returned.
    */
    std::pair<std::array<Vector3, 2>, float> getNearestPoint(const Ray& ray) const;

    /** Returns the starting point of the line segment. */
    const Vector3& getStart() const
    {
        return mStart;
    }

    /** Returns the ending point of the line segment. */
    const Vector3& getEnd() const
    {
        return mEnd;
    }

    /** Returns the length of the line segment. */
    float getLength() const
    {
        return mStart.distance(mEnd);
    }

    /** Returns the center point along the line segment. */
    Vector3 getCenter() const
    {
        return mStart + (mEnd - mStart) * 0.5f;
    }
private:
    Vector3 mStart, mEnd;
};


} // end of namespace ToyUtility