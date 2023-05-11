#pragma once
#include "Object.h"
class Missile :
    public Object
{
private:
    float m_speed;
    int m_direction;
public:
    Missile();
    ~Missile();

    virtual void Update();

    virtual void Render(HDC _dc);

	float GetSpeed() const
	{
		return m_speed;
	}
	void SetSpeed(float val)
	{
		m_speed = val;
	}
	int GetDirection() const
	{
		return m_direction;
	}
	void SetDirection(int val)
	{
		m_direction = val;
	}


};

