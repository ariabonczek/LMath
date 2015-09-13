#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "LVector.h"

using namespace LMath;

void oper(Vector2& v1, Vector2&v2)
{
	for (int i = 0; i < 100000; i++)
	{
		v1 + v2;
	}
}

void scalar(Vector2& v1, Vector2& v2)
{
	for (int i = 0; i < 100000; i++)
	{
		Vector2 ret;
		ret = Vector2(v1.x + v2.x, v1.y + v2.y);
	}
}

void loaded(VECTOR& v1, VECTOR v2)
{
	for (int i = 0; i < 100000; i++)
	{
		LVector::Add(v1, v2);
	}
}

int main(int argc, char** argv)
{
	Vector2 v1(1.0f, 1.0f);
	Vector2 v2(1.0f, 1.0f);

	VECTOR v1v = LVector::Load(&v1.x);
	VECTOR v2v = LVector::Load(&v2.x);

	oper(v1, v2);
	scalar(v1, v2);
	loaded(v1v, v2v);

	return 0;
}	