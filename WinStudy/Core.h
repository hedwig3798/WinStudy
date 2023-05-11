#pragma once
#include "pch.h"
#include "Object.h"
#include "TimeMg.h"
#include "KeyMg.h"
#include "SceneMg.h"
class Core
{
	SINGLE(Core)
public:
	void Init(HWND _hWnd, POINT _size);
	void Progress();


private:
	HWND m_hWnd;
	HDC m_hDC;
	POINT m_screenSize;

	HBITMAP m_hBitmap;
	HDC m_memDC;
};
