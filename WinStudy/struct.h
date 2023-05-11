#pragma once
struct Vec2
{
	float x;
	float y;

public:
	Vec2& operator = (POINT _pt)
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}
public:
	Vec2()
		: x(0.0f),
		y(0.0f)
	{
	}

	Vec2(float _a, float _b)
		:x(_a),
		y(_b)
	{
	}

	Vec2(int _a, int _b)
		:x((float)_a),
		y((float)_b)
	{
	}

	Vec2(const POINT& _pt)
		:x((float)_pt.x),
		y((float)_pt.y)
	{
	}
};