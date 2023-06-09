#pragma once
#include "KeyMg.h"
#include "TimeMg.h"
#include "pch.h"
class Object
{
private:
	Vec2 m_pos;
	Vec2 m_scale;
public:
	Vec2 GetPos() const
	{
		return m_pos;
	}
	void SetPos(Vec2 _val)
	{
		m_pos = _val;
	}

	Vec2 GetScale() const
	{
		return m_scale;
	}
	void SetScale(Vec2 _val)
	{
		m_scale = _val;
	}

	virtual void Update() = 0;
	virtual void Render(HDC _dc) = 0;

public:
	Object();
	Object(Vec2 _pos, Vec2 _scale);
	virtual ~Object();
	RECT GetRect();
};

