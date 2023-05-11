#include "Monster.h"

Monster::Monster()
	:m_speed(100.0f),
	m_centerPos(Vec2{ 0.0f, 0.0f }),
	m_moveRange(50.0f),
	m_dir(1)
{

}

Monster::~Monster()
{

}

void Monster::Update()
{
	Vec2 curPos = GetPos();
	curPos.x += m_speed * m_dir * DT;

	float overDistence = abs(curPos.x - m_centerPos.x) - GetMoveRange();

	if (overDistence > 0.0f)
	{
		m_dir *= -1;
		curPos.x += overDistence * m_dir;
	}

	SetPos(curPos);
}

void Monster::Render(HDC _dc)
{
	RECT rt;
	rt = GetRect();

	Rectangle(_dc, rt.left, rt.top, rt.right, rt.bottom);
}
