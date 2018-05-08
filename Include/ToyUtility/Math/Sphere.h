#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Math/Vector3.h"


namespace ToyUtility
{


class Plane;
class Matrix4;
class AABox;
class Sphere;
class Ray;


/** A sphere represented by a center point and a radius. */
class Sphere
{
public:
    /** Default constructor. Creates a unit sphere around the origin. */
    Sphere() : mRadius(1.0), mCenter(Vector3::ZERO)
    {
    }

    Sphere(const Vector3& center, float radius)
        :mRadius(radius), mCenter(center)
    {
    }

    /** Returns the radius of the sphere. */
    float getRadius() const
    {
        return mRadius;
    }

    /** Sets the radius of the sphere. */
    void setRadius(float radius)
    {
        mRadius = radius;
    }

    /** Returns the center point of the sphere. */
    const Vector3& getCenter() const
    {
        return mCenter;
    }

    /** Sets the center point of the sphere. */
    void setCenter(const Vector3& center)
    {
        mCenter = center;
    }

    /** Merges the two spheres, creating a new sphere that encapsulates them both. */
    void merge(const Sphere& rhs);

    /** Expands the sphere so it includes the provided point. */
    void merge(const Vector3& point);

    /** Transforms the sphere by the given matrix. */
    void transform(const Matrix4& matrix);

    /** Returns whether or not this sphere contains the provided point. */
    inline bool contains(const Vector3& v) const;

    /** Returns whether or not this sphere intersects another sphere. */
    bool intersects(const Sphere& s) const;

    /** Returns whether or not this sphere intersects a box. */
    bool intersects(const AABox& box) const;

    /** Returns whether or not this sphere intersects a plane. */
    bool intersects(const Plane& plane) const;

    /**
    * Ray/sphere intersection, returns boolean result and distance to nearest intersection.
    *
    * @param[in]	ray				Ray to intersect with the sphere.
    * @param[in]	discardInside	(optional) If true the intersection will be discarded if ray origin
    * 								is located within the sphere.
    */
    std::pair<bool, float> intersects(const Ray& ray, bool discardInside = true) const;

private:
    float mRadius;
    Vector3 mCenter;
};


} // end of namespace ToyUtility