#include "Vector3.h"

NS_BEGIN

Vector3::Vector3() :x(), y(), z(){}
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z){}

Vector3& Vector3::operator=(const Vector3& v)
{
	_mm_store_ps(&x, _mm_set_ps(v.x, v.y, v.z, 0.0f));
	return *this;
}

Vector3 Vector3::operator-()
{
	Vector3 ret;
	_mm_store_ps(&ret.x, _mm_sub_ps(_mm_setzero_ps(), Load()));
	return ret;
}

bool Vector3::operator==(const Vector3& v)
{
	return !_mm_movemask_ps(_mm_cmpeq_ps(Load(), v.Load()));
}

bool Vector3::operator!=(const Vector3& v)
{
	return !!_mm_movemask_ps(_mm_cmpneq_ps(Load(), v.Load()));
}

Vector3 Vector3::operator+(const Vector3& v)
{
	Vector3 ret;
	_mm_store_ps(&ret.x, _mm_add_ps(Load(), v.Load()));
	return ret;
}

Vector3& Vector3::operator+=(const Vector3& v)
{
	_mm_store_ps(&x, _mm_add_ps(Load(), v.Load()));
	return *this;
}

Vector3 Vector3::operator-(const Vector3& v)
{
	Vector3 ret;
	_mm_store_ps(&ret.x, _mm_sub_ps(Load(), v.Load()));
	return ret;
}

Vector3& Vector3::operator-=(const Vector3& v)
{
	_mm_store_ps(&x, _mm_sub_ps(Load(), v.Load()));
	return *this;
}

Vector3 Vector3::operator*(const Vector3& v)
{
	Vector3 ret;
	_mm_store_ps(&ret.x, _mm_mul_ps(Load(), v.Load()));
	return ret;
}

Vector3& Vector3::operator*=(const Vector3& v)
{
	_mm_store_ps(&x, _mm_mul_ps(Load(), v.Load()));
	return *this;
}

Vector3 Vector3::operator/(const Vector3& v)
{
	Vector3 ret;
	_mm_store_ps(&ret.x, _mm_div_ps(Load(), v.Load()));
	return ret;
}

Vector3& Vector3::operator/=(const Vector3& v)
{
	_mm_store_ps(&x, _mm_div_ps(Load(), v.Load()));
	return *this;
}

void* Vector3::operator new[](size_t x)
{
	return _aligned_malloc(x, 16);
}

void Vector3::operator delete[](void* x)
{
	if (x) _aligned_free(x);
}

std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
	os << "X: " << v.x << " Y: " << v.y << " Z: " << v.z;
	return os;
}

inline __m128 Vector3::Load()const
{
	return _mm_set_ps(0.0f, z, y, x);
}

NS_END