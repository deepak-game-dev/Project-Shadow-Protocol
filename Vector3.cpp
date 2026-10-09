#include "Vector3.h" 
#include <cmath> 

Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
{
}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
}

float Vector3::Magnitude() const
{
	return std::sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::Normalized() const
{
	float magnitude = Magnitude();
	if (magnitude == 0.0f)
	{
		return Vector3(0.0f, 0.0f, 0.0f);
	}
	else
	{
		return Vector3(x / magnitude, y / magnitude, z / magnitude);
	}
}

Vector3 Vector3::operator+(const Vector3& other) const
{
	return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const
{
	return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(float value) const
{
	return Vector3(x * value, y * value, z * value);
}