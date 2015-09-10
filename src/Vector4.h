#ifndef VECTOR4_H
#define VECTOR4_H

#include "Config.h"

NS_BEGIN

__declspec(align(16))
struct Vector4
{
	float x, y, z, w;
	Vector4();
	Vector4(float x, float y, float z, float w);

	Vector4& operator=(const Vector4& v);
	Vector4 operator-();
	bool operator==(const Vector4& v);
	bool operator!=(const Vector4& v);
	Vector4 operator+(const Vector4& v);
	Vector4& operator+=(const Vector4& v);
	Vector4 operator-(const Vector4& v);
	Vector4& operator-=(const Vector4& v);
	Vector4 operator*(const Vector4& v);
	Vector4& operator*=(const Vector4& v);
	Vector4 operator/(const Vector4& v);
	Vector4& operator/=(const Vector4& v);
	void* operator new[](size_t x);
	void  operator delete[](void* x);
	friend std::ostream& operator<<(std::ostream& os, const Vector4& v);
private:
	/// <summary>
	/// Syntactic sugar for loading
	/// </summary>
	inline __m128 Load()const;
};

NS_END

#endif