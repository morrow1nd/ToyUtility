#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


class Radian;

class Degree
{
public:
	explicit Degree(float d = 0.0f) : m_Deg(d) {}
	Degree(const Radian& r);
	Degree& operator= (const float& f) { m_Deg = f; return *this; }
	Degree& operator= (const Degree& d) { m_Deg = d.m_Deg; return *this; }
	Degree& operator= (const Radian& r);

	// Returns the value of the angle in degrees
	float ValueDegrees() const { return m_Deg; }

	// Returns the value of the angle in radians
	float ValueRadians() const;

	// Wraps the angle in [0, 360) range
	Degree Wrap();

	const Degree& operator+ () const { return *this; }
	Degree operator+ (const Degree& d) const { return Degree (m_Deg + d.m_Deg); }
	Degree operator+ (const Radian& r) const;
	Degree& operator+= (const Degree& d) { m_Deg += d.m_Deg; return *this; }
	Degree& operator+= (const Radian& r);
	Degree operator- () const { return Degree(-m_Deg); }
	Degree operator- (const Degree& d) const { return Degree (m_Deg - d.m_Deg); }
	Degree operator- (const Radian& r) const;
	Degree& operator-= (const Degree& d) { m_Deg -= d.m_Deg; return *this; }
	Degree& operator-= (const Radian& r);
	Degree operator* (float f) const { return Degree (m_Deg * f); }
	Degree operator* (const Degree& f) const { return Degree (m_Deg * f.m_Deg); }
	Degree& operator*= (float f) { m_Deg *= f; return *this; }
	Degree operator/ (float f) const { return Degree (m_Deg / f); }
	Degree& operator/= (float f) { m_Deg /= f; return *this; }

	friend Degree operator* (float lhs, const Degree& rhs) { return Degree(lhs * rhs.m_Deg); }
	friend Degree operator/ (float lhs, const Degree& rhs) { return Degree(lhs / rhs.m_Deg); }
	friend Degree operator+ (Degree& lhs, float rhs) { return Degree(lhs.m_Deg + rhs); }
	friend Degree operator+ (float lhs, const Degree& rhs) { return Degree(lhs + rhs.m_Deg); }
	friend Degree operator- (const Degree& lhs, float rhs) { return Degree(lhs.m_Deg - rhs); }
	friend Degree operator- (const float lhs, const Degree& rhs) { return Degree(lhs - rhs.m_Deg); }

	bool operator<  (const Degree& d) const { return m_Deg <  d.m_Deg; }
	bool operator<= (const Degree& d) const { return m_Deg <= d.m_Deg; }
	bool operator== (const Degree& d) const { return m_Deg == d.m_Deg; }
	bool operator!= (const Degree& d) const { return m_Deg != d.m_Deg; }
	bool operator>= (const Degree& d) const { return m_Deg >= d.m_Deg; }
	bool operator>  (const Degree& d) const { return m_Deg >  d.m_Deg; }

private:
	float m_Deg;
};


} // end of namespace ToyUtility