#pragma once
struct vec2
{
	float x;
	float y;
public:
	vec2()
		: x(0.0f),
		y(0.0f)
	{
	}

	vec2(float _a, float _b)
		:x(_a),
		y(_b)
	{
	}

	vec2(int _a, int _b)
		:x((float)_a),
		y((float)_b)
	{
	}
};