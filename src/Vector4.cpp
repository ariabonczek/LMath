#include "Vector4.h"

NS_BEGIN

Vector4::Vector4() :x(), y(), z(), w(){}
Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){}

Vector4& Vector4::operator=(const Vector4& v)
{
	_mm_store_ps(&x, _mm_set_ps(v.x, v.y, v.z, v.w));
	return *this;
}

Vector4 Vector4::operator-()
{
	Vector4 ret;
	_mm_store_ps(&ret.x, _mm_sub_ps(_mm_set1_ps(0.0f), Load()));
	return ret;
}

bool Vector4::operator==(const Vector4& v)
{
	return !_mm_movemask_ps(_mm_cmpeq_ps(Load(), v.Load()));
}

bool Vector4::operator!=(const Vector4& v)
{
	return !!_mm_movemask_ps(_mm_cmpneq_ps(Load(), v.Load()));
}

Vector4 Vector4::operator+(const Vector4& v)
{
	Vector4 ret;
	_mm_store_ps(&ret.x, _mm_add_ps(Load(), v.Load()));
	return ret;
}

Vector4& Vector4::operator+=(const Vector4& v)
{
	_mm_store_ps(&x, _mm_add_ps(Load(), v.Load()));
	return *this;
}

Vector4 Vector4::operator-(const Vector4& v)
{
	Vector4 ret;
	_mm_store_ps(&ret.x, _mm_sub_ps(Load(), v.Load()));
	return ret;
}

Vector4& Vector4::operator-=(const Vector4& v)
{
	_mm_store_ps(&x, _mm_sub_ps(Load(), v.Load()));
	return *this;
}

Vector4 Vector4::operator*(const Vector4& v)
{
	Vector4 ret;
	_mm_store_ps(&ret.x, _mm_mul_ps(Load(), v.Load()));
	return ret;
}

Vector4& Vector4::operator*=(const Vector4& v)
{
	_mm_store_ps(&x, _mm_mul_ps(Load(), v.Load()));
	return *this;
}

Vector4 Vector4::operator/(const Vector4& v)
{
	Vector4 ret;
	_mm_store_ps(&ret.x, _mm_div_ps(Load(), v.Load()));
	return ret;
}

Vector4& Vector4::operator/=(const Vector4& v)
{
	_mm_store_ps(&x, _mm_div_ps(Load(), v.Load()));
	return *this;
}

void* Vector4::operator new[](size_t x)
{
	return _aligned_malloc(x, 16);
}

void Vector4::operator delete[](void* x)
{
	if (x) _aligned_free(x);
}

std::ostream& operator<<(std::ostream& os, const Vector4& v)
{
	os << "X: " << v.x << " Y: " << v.y << " Z: " << v.z << " W: " << v.w;
	return os;
}

inline __m128 Vector4::Load()const
{
	return _mm_load_ps(&x);
}

NS_END