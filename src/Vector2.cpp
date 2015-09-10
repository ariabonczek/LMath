#include "Vector2.h"

NS_BEGIN

Vector2::Vector2() :x(), y(){}
Vector2::Vector2(float x, float y) :x(x), y(y){}

Vector2& Vector2::operator=(const Vector2& v)
{
	_mm_storel_pi((__m64*)&x, _mm_set_ps(v.x, v.y, 0.0f, 0.0f));
	return *this;
}

Vector2 Vector2::operator-()
{
	Vector2 ret;
	_mm_storel_pi((__m64*)&ret, _mm_sub_ps(_mm_set1_ps(0.0f), Load()));
	return ret;
}

bool Vector2::operator==(const Vector2& v)
{
	return !_mm_movemask_ps(_mm_cmpeq_ps(Load(), v.Load()));
}

bool Vector2::operator!=(const Vector2& v)
{
	return !!_mm_movemask_ps(_mm_cmpneq_ps(Load(), v.Load()));
}

Vector2 Vector2::operator+(const Vector2& v)
{
	Vector2 ret;
	_mm_storel_pi((__m64*)&ret, _mm_add_ps(Load(), v.Load()));
	return ret;
}

Vector2& Vector2::operator+=(const Vector2& v)
{
	_mm_storel_pi((__m64*)&x, _mm_add_ps(Load(), v.Load()));
	return *this;
}

Vector2 Vector2::operator-(const Vector2& v)
{
	Vector2 ret;
	_mm_storel_pi((__m64*)&ret, _mm_sub_ps(Load(), v.Load()));
	return ret;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	_mm_storel_pi((__m64*)&x, _mm_sub_ps(Load(), v.Load()));
	return *this;
}

Vector2 Vector2::operator*(const Vector2& v)
{
	Vector2 ret;
	_mm_storel_pi((__m64*)&ret, _mm_mul_ps(Load(), v.Load()));
	return ret;
}

Vector2& Vector2::operator*=(const Vector2& v)
{
	_mm_storel_pi((__m64*)&x, _mm_mul_ps(Load(), v.Load()));
	return *this;
}

Vector2 Vector2::operator/(const Vector2& v)
{
	Vector2 ret;
	_mm_storel_pi((__m64*)&ret, _mm_div_ps(Load(), v.Load()));
	return ret;
}

Vector2& Vector2::operator/=(const Vector2& v)
{
	_mm_storel_pi((__m64*)&x, _mm_div_ps(Load(), v.Load()));
	return *this;
}

void* Vector2::operator new[](size_t x)
{
	return _aligned_malloc(x, 16);
}

void Vector2::operator delete[](void* x)
{
	if (x) _aligned_free(x);
}

std::ostream& operator<<(std::ostream& os, const Vector2& v)
{
	os << "X: " << v.x << " Y: " << v.y;
	return os;
}

inline __m128 Vector2::Load()const
{
	return _mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&x);
}

NS_END