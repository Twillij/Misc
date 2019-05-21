#pragma once
#include <iostream>

class Vector3
{
public:
	Vector3();
	Vector3(float x0, float y0, float z0);
	~Vector3();

	float x, y, z;

	Vector3 operator + (Vector3 other)
	{
		return { x + other.x, y + other.y, z + other.z };
	}

	Vector3 operator - (Vector3 other)
	{
		return { x - other.x, y - other.y, z - other.z };
	}

	Vector3 operator * (float scalar)
	{
		return { x * scalar, y * scalar, z * scalar };
	}

	Vector3 operator / (float scalar)
	{
		return { x / scalar, y / scalar, z / scalar };
	}

	void operator += (Vector3 other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}

	void operator -= (Vector3 other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}

	void operator *= (float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}

	void operator /= (float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
	}

	void operator = (Vector3 other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}

	float magnitude()
	{
		return sqrtf(x * x + y * y + z * z);
	}

	float magnitudeSqr()
	{
		return x * x + y * y + z * z;
	}

	float distance(Vector3 other)
	{
		float diffX = x - other.x;
		float diffY = y - other.y;
		float diffZ = z - other.z;
		return sqrtf(diffX * diffX + diffY * diffY + diffZ * diffZ);
	}

	float distanceSqr(Vector3 other)
	{
		float diffX = x - other.x;
		float diffY = y - other.y;
		float diffZ = z - other.z;
		return diffX * diffX + diffY * diffY + diffZ * diffZ;
	}

	void normalise()
	{
		float mag = sqrtf(x * x + y * y);
		x /= mag;
		y /= mag;
		z /= mag;
	}

	Vector3 normalised()
	{
		return { x / magnitude(), y / magnitude(), z / magnitude() };
	}

	float dot(Vector3 other)
	{
		return x * other.x + y * other.y + z * other.z;
	}

	Vector3 cross(Vector3 other)
	{
		return
		{
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		};
	}

	float angle(Vector3 other)
	{
		Vector3 a = normalised();
		Vector3 b = other.normalised();

		return acos(a.dot(b));
	}
};