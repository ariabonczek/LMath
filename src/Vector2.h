#ifndef VECTOR2_H
#define VECTOR2_H

#include "Config.h"

NS_BEGIN

__declspec(align(16))
struct Vector2
{
	float x, y;
	Vector2();
	Vector2(float x, float y);

	Vector2& operator=(const Vector2& v);
	Vector2 operator-();
	bool operator==(const Vector2& v);
	bool operator!=(const Vector2& v);
	Vector2 operator+(const Vector2& v);
	Vector2& operator+=(const Vector2& v);
	Vector2 operator-(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2 operator*(const Vector2& v);
	Vector2& operator*=(const Vector2& v);
	Vector2 operator/(const Vector2& v);
	Vector2& operator/=(const Vector2& v);
	void* operator new[](size_t x);
	void  operator delete[](void* x);
	friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
};

NS_END

#endif