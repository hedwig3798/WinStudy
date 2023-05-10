#include "Object.h"
#include "pch.h"

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
