#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Math/Vector3.h"
#include "ToyUtility/Math/Quaternion.h"
#include "ToyUtility/Math/Matrix4.h"


namespace ToyUtility
{


class TransformPRS
{
public:
    TransformPRS();
    TransformPRS(const Vector3& position, const Quaternion& rotation, const Vector3& scale);

    // Set the local position
    void SetPosition(const Vector3& position)
    {
        m_LocalPosition = position;
    }

    // Get the local position
    const Vector3& GetPosition() const
    {
        return m_LocalPosition;
    }

    // Shorthand for GetPosition()
    const Vector3& Pos() const
    {
        return m_LocalPosition;
    }

    // Set the local rotation
    void SetRotation(const Quaternion& rotation)
    {
        m_LocalRotation = rotation;
    }

    // Get the local rotation
    const Quaternion& GetRotation() const
    {
        return m_LocalRotation;
    }

    // Shorthand for GetRotation()
    const Quaternion& Rot() const
    {
        return m_LocalRotation;
    }

    // Set the local scale
    void SetScale(const Vector3& scale)
    {
        m_LocalScale = scale;
    }

    // Get the local scale
    const Vector3& GetScale() const
    {
        return m_LocalScale;
    }

    // Shorthand for GetScale()
    const Vector3& Scl() const
    {
        return m_LocalScale;
    }

    // Convert the provided world position to a space relative to the provided parent, and sets it as the current
    // transform's position. 
    void SetWorldPosition(const Vector3& position, const TransformPRS& parent);

    // Convert the provided world rotation to a space relative to the provided parent, and sets it as the current
    // transform's rotation. 
    void SetWorldRotation(const Quaternion& rotation, const TransformPRS& parent);

    // Convert the provided world scale to a space relative to the provided parent, and sets it as the current
    // transform's scale. 
    void SetWorldScale(const Vector3& scale, const TransformPRS& parent);

    // Build the transform matrix from current translation, rotation and scale properties
    Matrix4 GetMatrix() const;

    // Build the inverse transform matrix from current translation, rotation and scale properties
    Matrix4 GetInverseMatrix() const;

    // Make the current transform relative to the provided transform. In another words, converts from a world 
    // coordinate system to one local to the provided transform.
    void MakeLocal(const TransformPRS& parent);

    // Makes the current transform absolute.In another words, converts from a local coordinate system relative to
    // the provided transform, to a world coordinate system.
    void MakeWorld(const TransformPRS& parent);

    // Orients the object so it is looking at the provided @p location(world space) where @p up is used for
    // determining the location of the object's Y axis.
    void LookAt(const Vector3& location, const Vector3& up = Vector3::UNIT_Y);

    // Move the object's position by the vector offset provided along world axes
    void Move(const Vector3& vec);

    // Moves the object's position by the vector offset provided along it's own axes (relative to orientation)
    void MoveRelative(const Vector3& vec);

    // Get the Z (forward) axis of the object
    Vector3 GetForward() const
    {
        return GetRotation().rotate(-Vector3::UNIT_Z);
    }

    // Get the Y (up) axis of the object
    Vector3 GetUp() const
    {
        return GetRotation().rotate(Vector3::UNIT_Y);
    }

    // Get the X (right) axis of the object
    Vector3 GetRight() const
    {
        return GetRotation().rotate(Vector3::UNIT_X);
    }

    // Rotate the game object so it's forward axis faces the provided direction.
    // @note	Local forward axis is considered to be negative Z.
    void SetForward(const Vector3& forwardDir);

    // Rotate the object around an arbitrary axis
    void Rotate(const Vector3& axis, const Radian& angle);

    // Rotate the object around an arbitrary axis using a Quaternion
    void Rotate(const Quaternion& q);

    // Rotate around local Z axis
    void Roll(const Radian& angle);

    // Rotates around Y axis
    void Yaw(const Radian& angle);

    // Rotates around X axis
    void Pitch(const Radian& angle);


private:
    Quaternion                  m_LocalRotation;
    Vector3                     m_LocalPosition;
    Vector3                     m_LocalScale;
};


} // end of namespace ToyUtility