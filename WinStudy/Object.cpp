#include "Object.h"
#include "pch.h"

Object::Object()
{
	SetPos(vec2{ 0, 0 });
	SetScale(vec2{ 0, 0 });
}

Object::Object(vec2 _pos, vec2 _scale)
{
	SetPos(_pos);
	SetScale(_scale);
}

Object::~Object()
{

}

RECT Object::GetRect()
{
	vec2 _nowPos = GetPos();
	vec2 _nowScale = GetScale();

	RECT rt = {_nowPos.x - _nowScale.x / 2,
				_nowPos.y - _nowScale.y / 2 ,
				_nowPos.x + _nowScale.x / 2 ,
				_nowPos.y + _nowScale.y / 2 };

	return rt;
}
