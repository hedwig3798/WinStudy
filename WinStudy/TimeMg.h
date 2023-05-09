#pragma once
#include "pch.h"
class TimeMg
{
	SINGLE(TimeMg)
private:
	LARGE_INTEGER m_tickCount;
	LARGE_INTEGER m_preTickCount;
	LARGE_INTEGER m_frequency;
	float m_dTime;
	float m_acc;
	UINT m_callCount;
	UINT m_FPS;
public:
	void Init();
	void Update();

	float GetDt();
};

