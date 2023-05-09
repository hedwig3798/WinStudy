#include "Core.h"
Core::Core()
	: m_hWnd(0),
	m_hDC(0),
	m_obj{}
{

}

Core::~Core()
{

}

void Core::Update()
{
	

	if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
	{
		vec2 nowPos = m_obj.GetPos();
		m_obj.SetPos({ (nowPos.x - 100.0f * DT) , nowPos.y});
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vec2 nowPos = m_obj.GetPos();
		m_obj.SetPos({ nowPos.x + 100.0f * DT, nowPos.y });
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		vec2 nowPos = m_obj.GetPos();
		m_obj.SetPos({ nowPos.x , nowPos.y - 100.0f * DT });
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		vec2 nowPos = m_obj.GetPos();
		m_obj.SetPos({ nowPos.x , nowPos.y + 100.0f * TimeMg::GetInst()->GetDt() });
	}

}

void Core::Rendering()
{
	RECT rt = m_obj.GetRect();
	Rectangle(m_hDC, rt.left, rt.top, rt.right, rt.bottom);
}

void Core::Init(HWND hWnd, POINT size)
{
	m_hWnd = hWnd;

	// 창 사각형 크기 조정
	RECT rt = { 0, 0, size.x, size.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, FALSE);

	SetWindowPos(m_hWnd, NULL, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
	m_obj = Object(vec2{ (int)(rt.right - rt.left) / 2, (int)(rt.bottom - rt.top) / 2 }, vec2{ 100, 100 });

	m_hDC = GetDC(hWnd);

	// 매니저 초기화
	TimeMg::GetInst()->Init();
}

void Core::Progress()
{
	TimeMg::GetInst()->Update();
	Update();
	Rendering();
}
