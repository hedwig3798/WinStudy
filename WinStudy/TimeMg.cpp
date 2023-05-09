#include "TimeMg.h"


TimeMg::TimeMg()
	:m_tickCount{},
	m_frequency{},
	m_preTickCount{},
	m_dTime(0.0f),
	m_callCount(0),
	m_acc(0.0f),
	m_FPS(0)
{
}

TimeMg::~TimeMg()
{
}

void TimeMg::Init()
{
	QueryPerformanceCounter(&m_preTickCount);
	QueryPerformanceFrequency(&m_frequency);
}

void TimeMg::Update()
{
	QueryPerformanceCounter(&m_tickCount);
	m_dTime = (float)(m_tickCount.QuadPart - m_preTickCount.QuadPart) / (float)m_frequency.QuadPart;
	m_acc += m_dTime;

	m_preTickCount = m_tickCount;
	m_callCount++;

	if (m_acc >= 1.0f) 
	{
		m_acc = 0.0f;
		m_FPS = m_callCount;
		m_callCount = 0;
	}
}

float TimeMg::GetDt()
{
	return m_dTime;
}
