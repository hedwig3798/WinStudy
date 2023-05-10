#pragma once
#include "pch.h"
#include "Object.h"
#include "TimeMg.h"
class Core
{
	SINGLE(Core)

public:
	void Init(HWND _hWnd, POINT _size);
	void Progress();
private:
	void Update();
	void Rendering();

private:
	HWND m_hWnd;
	HDC m_hDC;
	Object m_obj;
	POINT m_screenSize;

	HBITMAP m_hBitmap;
	HDC m_memDC;
};
