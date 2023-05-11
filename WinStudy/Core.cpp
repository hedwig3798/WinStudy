#include "Core.h"
Core::Core()
	: m_hWnd(0),
	m_hDC(0),
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
	SetScreenSize(_size);


	// 창 사각형 크기 조정
	RECT rt = { 0, 0, _size.x, _size.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, FALSE);

	SetWindowPos(m_hWnd, NULL, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	// 더블 버퍼링
	m_hDC = GetDC(_hWnd);

	m_hBitmap = CreateCompatibleBitmap(m_hDC, GetScreenSize().x, GetScreenSize().y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_memDC, m_hBitmap);
	DeleteObject(hOldBitmap);

	// 매니저 초기화
	TimeMg::GetInst()->Init();
	KeyMg::GetInst()->Init();
	SceneMg::GetInst()->Init();
}

void Core::Progress()
{
	TimeMg::GetInst()->Update();
	KeyMg::GetInst()->Update();
	SceneMg::GetInst()->Update();

	Rectangle(m_memDC, -1, -1, GetScreenSize().x + 1, GetScreenSize().y + 1);

	SceneMg::GetInst()->Render(m_hDC);

	BitBlt(m_hDC, 0, 0, GetScreenSize().x, GetScreenSize().y, m_memDC, 0, 0, SRCCOPY);
}
