#include "Core.h"
#include "pch.h"
Core::Core()
	: m_hWnd(0)
{

}

Core::~Core()
{

}

void Core::Update()
{

}

void Core::Rendering()
{

}

void Core::Init(HWND hWnd, POINT size)
{
	m_hWnd = hWnd;

	RECT rt = { 0, 0, size.x, size.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, FALSE);

	SetWindowPos(m_hWnd, NULL, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
}

void Core::Progress()
{
	Update();
	Rendering();
}
