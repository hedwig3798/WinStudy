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
