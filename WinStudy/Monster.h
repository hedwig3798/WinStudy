#pragma once
#include "Object.h"
class Monster :
	public Object
{
public:
	Monster();
	~Monster();

	virtual void Update();
	virtual void Render(HDC _dc);

	void SetCenterPos(Vec2 val)
	{
		m_centerPos = val;
	}
private:
	float m_speed;
	Vec2 m_centerPos;
	float m_moveRange;
	int m_dir;
};

