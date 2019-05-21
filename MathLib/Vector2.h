#pragma once
#include <iostream>

using namespace std;

class Vector2
{
public:
	Vector2();
	Vector2(float x0, float y0);
	~Vector2();

	float x, y;

	//void operator[] (int index) const { return data[index]; }

	Vector2 operator + (Vector2 other)
	{
		return { x + other.x, y + other.y };
	}

	Vector2 operator - (Vector2 other)
	{
		return { x - other.x, y - other.y };
	}

	Vector2 operator * (float scalar)
	{
		return { x * scalar, y * scalar };
	}

	Vector2 operator / (float scalar)
	{
		return { x / scalar, y / scalar };
	}

	void operator += (Vector2 other)
	{
		x += other.x;
		y += other.y;
	}

	void operator -= (Vector2 other)
	{
		x -= other.x;
		y -= other.y;
	}

	void operator *= (float scalar)
	{
		x *= scalar;
		y *= scalar;
	}

	void operator /= (float scalar)
	{
		x /= scalar;
		y /= scalar;
	}

	void operator = (Vector2 other)
	{
		x = other.x;
		y = other.y;
	}

	float magnitude()
	{
		return sqrtf(x * x + y * y);
	}

	float magnitudeSqr()
	{
		return x * x + y * y;
	}

	float distance(Vector2 other)
	{
		float diffX = x - other.x;
		float diffY = y - other.y;
		return sqrtf(diffX * diffX + diffY * diffY);
	}

	float distanceSqr(Vector2 other)
	{
		float diffX = x - other.x;
		float diffY = y - other.y;
		return diffX * diffX + diffY * diffY;
	}

	void normalise()
	{
		x /= magnitude();
		y /= magnitude();
	}

	Vector2 normalised()
	{
		return { x / magnitude(), y / magnitude() };
	}

	float dot(Vector2 other)
	{
		return x * other.x + y * other.y;
	}

	Vector2 getPerpendicularRH()
	{
		return { -y, x };
	}

	Vector2 getPerpendicularLH()
	{
		return { y, -x };
	}

	float angle(Vector2 other)
	{
		Vector2 a = normalised();
		Vector2 b = other.normalised();

		return acos(a.dot(b));
	}
};