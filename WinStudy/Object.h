#pragma once
#include "pch.h"
class Object
{
private:
	vec2 pos;
	vec2 scale;
public:
	vec2 GetPos() const { return pos; }
	void SetPos(vec2 val) { pos = val; }

	vec2 GetScale() const { return scale; }
	void SetScale(vec2 val) { scale = val; }
public:
	Object();
	Object(vec2 _pos, vec2 _scale);
	~Object();
};

