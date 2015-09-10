#ifndef VECTOR3_H
#define VECTOR3_H

#include "Config.h"

NS_BEGIN

__declspec(align(16))
struct Vector3
{
	float x, y, z;
	Vector3();
	Vector3(float x, float y, float z);

	Vector3& operator=(const Vector3& v);
	Vector3 operator-();
	bool operator==(const Vector3& v);
	bool operator!=(const Vector3& v);
	Vector3 operator+(const Vector3& v);
	Vector3& operator+=(const Vector3& v);
	Vector3 operator-(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
	Vector3 operator*(const Vector3& v);
	Vector3& operator*=(const Vector3& v);
	Vector3 operator/(const Vector3& v);
	Vector3& operator/=(const Vector3& v);
	void* operator new[](size_t x);
	void  operator delete[](void* x);
	friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
private:
	/// <summary>
	/// Syntactic sugar for loading
	/// </summary>
	inline __m128 Load()const;
};

NS_END

#endif