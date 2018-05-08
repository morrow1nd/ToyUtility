#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Math/Vector3.h"


namespace ToyUtility
{


class Ray;


/**
* Represents a torus at the world center. Outer radius represents the distance from the center, and inner radius
* represents the radius of the tube. Inner radius must be less or equal than the outer radius.
*/
class Torus
{
public:
    Torus();
    Torus(const Vector3& normal, float outerRadius, float innerRadius);

    /** Ray/torus intersection, returns boolean result and distance to nearest intersection point. */
    std::pair<bool, float> intersects(const Ray& ray) const;

    Vector3 normal;
    float outerRadius;
    float innerRadius;
};


} // end of namespace ToyUtility