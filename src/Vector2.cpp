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
	_mm_storel_pi((__m64*)&ret, _mm_sub_ps(_mm_set1_ps(0.0f), _mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&x)));
	return ret;
}

bool Vector2::operator==(const Vector2& v)
{
	return !_mm_movemask_ps(_mm_cmpeq_ps(_mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&x), _mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&v.x)));
}

bool Vector2::operator!=(const Vector2& v)
{
	return !!_mm_movemask_ps(_mm_cmpneq_ps(_mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&x), _mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&v.x)));
}

Vector2 Vector2::operator+(const Vector2& v)
{
	Vector2 ret;
	_mm_storel_pi((__m64*)&ret, _mm_add_ps(_mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&x), _mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&v.x)));
	return ret;
}

Vector2& Vector2::operator+=(const Vector2& v)
{
	_mm_storel_pi((__m64*)&x, _mm_add_ps(_mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&x), _mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&v.x)));
	return *this;
}

Vector2 Vector2::operator-(const Vector2& v)
{
	Vector2 ret;
	_mm_storel_pi((__m64*)&ret, _mm_sub_ps(_mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&x), _mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&v.x)));
	return ret;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	_mm_storel_pi((__m64*)&x, _mm_sub_ps(_mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&x), _mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&v.x)));
	return *this;
}

Vector2 Vector2::operator*(const Vector2& v)
{
	Vector2 ret;
	_mm_storel_pi((__m64*)&ret, _mm_mul_ps(_mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&x), _mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&v.x)));
	return ret;
}

Vector2& Vector2::operator*=(const Vector2& v)
{
	_mm_storel_pi((__m64*)&x, _mm_mul_ps(_mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&x), _mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&v.x)));
	return *this;
}

Vector2 Vector2::operator/(const Vector2& v)
{
	Vector2 ret;
	_mm_storel_pi((__m64*)&ret, _mm_div_ps(_mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&x), _mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&v.x)));
	return ret;
}

Vector2& Vector2::operator/=(const Vector2& v)
{
	_mm_storel_pi((__m64*)&x, _mm_div_ps(_mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&x), _mm_loadl_pi(_mm_setzero_ps(), (const __m64*)&v.x)));
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
NS_END