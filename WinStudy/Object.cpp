#include "Object.h"
#include "KeyMg.h"
#include "TimeMg.h"
#include "pch.h"

void Object::Update()
{
	if (KEY_HOLD(KEY::W))
	{
		m_pos.y -= 200.0f * DT;
	}	
	if (KEY_HOLD(KEY::S))
	{
		m_pos.y += 200.0f * DT;
	}	
	if (KEY_HOLD(KEY::A))
	{
		m_pos.x -= 200.0f * DT;
	}	
	if (KEY_HOLD(KEY::D))
	{
		m_pos.x += 200.0f * DT;
	}
}

void Object::Render(HDC _dc)
{
	RECT rt;
	rt = GetRect();

	Rectangle(_dc, rt.left, rt.top, rt.right, rt.bottom);
}

Object::Object()
{
	SetPos(Vec2{ 0, 0 });
	SetScale(Vec2{ 0, 0 });
}

Object::Object(Vec2 _pos, Vec2 _scale)
{
	SetPos(_pos);
	SetScale(_scale);
}

Object::~Object()
{

}

RECT Object::GetRect()
{
	Vec2 _nowPos = GetPos();
	Vec2 _nowScale = GetScale();

	RECT rt = {(int)(_nowPos.x - _nowScale.x / 2),
				(int)(_nowPos.y - _nowScale.y / 2) ,
				(int)(_nowPos.x + _nowScale.x / 2) ,
				(int)(_nowPos.y + _nowScale.y / 2) };

	return rt;
}
