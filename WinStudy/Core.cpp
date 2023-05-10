#include "Core.h"
Core::Core()
	: m_hWnd(0),
	m_hDC(0),
	m_obj{},
	m_screenSize{}, 
	m_hBitmap(0),
	m_memDC(0)
{

}

Core::~Core()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteObject(m_memDC);
	DeleteObject(m_hBitmap);
}

void Core::Init(HWND _hWnd, POINT _size)
{
	m_hWnd = _hWnd;
	m_screenSize = _size;


	// 창 사각형 크기 조정
	RECT rt = { 0, 0, _size.x, _size.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, FALSE);

	SetWindowPos(m_hWnd, NULL, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
	m_obj = Object(vec2{ (int)(rt.right - rt.left) / 2, (int)(rt.bottom - rt.top) / 2 }, vec2{ 100, 100 });

	// 더블 버퍼링
	m_hDC = GetDC(_hWnd);

	m_hBitmap = CreateCompatibleBitmap(m_hDC, m_screenSize.x, m_screenSize.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_memDC, m_hBitmap);
	DeleteObject(hOldBitmap);

	// 매니저 초기화
	TimeMg::GetInst()->Init();
	KeyMg::GetInst()->Init();
}

void Core::Update()
{
	if (KEY_HOLD(KEY::LEFT))
	{
		vec2 nowPos = m_obj.GetPos();
		m_obj.SetPos({ (nowPos.x - 100.0f * DT) , nowPos.y});
	}
	if (KEY_HOLD(KEY::RIGHT))
	{
		vec2 nowPos = m_obj.GetPos();
		m_obj.SetPos({ nowPos.x + 100.0f * DT, nowPos.y });
	}
	if (KEY_HOLD(KEY::UP))
	{
		vec2 nowPos = m_obj.GetPos();
		m_obj.SetPos({ nowPos.x , nowPos.y - 100.0f * DT });
	}
	if (KEY_HOLD(KEY::DOWN))
	{
		vec2 nowPos = m_obj.GetPos();
		m_obj.SetPos({ nowPos.x , nowPos.y + 100.0f * TimeMg::GetInst()->GetDt() });
	}

}

void Core::Rendering()
{
	Rectangle(m_memDC, -1, -1, m_screenSize.x + 1, m_screenSize.y + 1);

	RECT rt = m_obj.GetRect();
	Rectangle(m_memDC, rt.left, rt.top, rt.right, rt.bottom);
	
	BitBlt(m_hDC, 0, 0, m_screenSize.x, m_screenSize.y, m_memDC, 0, 0, SRCCOPY);

}

void Core::Progress()
{
	TimeMg::GetInst()->Update();
	KeyMg::GetInst()->Update();
	Update();
	Rendering();
}
