#pragma once
#include "pch.h"
class Object
{
private:
	vec2 m_pos;
	vec2 m_scale;
public:
	vec2 GetPos() const
	{
		return m_pos;
	}
	void SetPos(vec2 _val)
	{
		m_pos = _val;
	}

	vec2 GetScale() const
	{
		return m_scale;
	}
	void SetScale(vec2 _val)
	{
		m_scale = _val;
	}
public:
	Object();
	Object(vec2 _pos, vec2 _scale);
	~Object();
	RECT GetRect();
};

