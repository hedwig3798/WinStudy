#pragma once
#include "pch.h"
#include "Object.h"
#include "TimeMg.h"
#include "KeyMg.h"
class Core
{
	SINGLE(Core)
private:
	void Update();
	void Rendering();
public:
	void Init(HWND _hWnd, POINT _size);
	void Progress();


private:
	HWND m_hWnd;
	HDC m_hDC;
	Object m_obj;
	POINT m_screenSize;

	HBITMAP m_hBitmap;
	HDC m_memDC;
};
