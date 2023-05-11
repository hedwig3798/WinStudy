#include "Missile.h"

Missile::Missile()
	:m_speed(200.0f),
	m_direction(0)
{

}

Missile::~Missile()
{

}

void Missile::Update()
{
	Vec2 curPos = GetPos();
	curPos.y += m_speed * DT * m_direction;
	SetPos(curPos);
}

void Missile::Render(HDC _dc)
{
	RECT rt;
	rt = GetRect();
	Ellipse(_dc, rt.left, rt.top, rt.right, rt.bottom);
}

