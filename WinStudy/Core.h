#pragma once
#include "pch.h"
#include "Object.h"
#include "TimeMg.h"
class Core
{
	// 싱글턴
	SINGLE(Core)

public:
	// 초기화
	void Init(HWND _hWnd, POINT _size);
	// 게임 진행
	void Progress();
private:
	void Update();
	void Rendering();

private:
	HWND m_hWnd;
	HDC m_hDC;
	Object m_obj;
};
