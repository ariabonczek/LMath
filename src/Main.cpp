#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

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

int main(int argc, char** argv)
{
	Vector2 v1(1.0f, 1.0f);
	Vector2 v2(1.0f, 1.0f);

	oper(v1, v2);
	scalar(v1, v2);

	return 0;
}	