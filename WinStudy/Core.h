#pragma once
#include "pch.h"
class Core
{
	SINGLE(Core)

public:
	void Init(HWND hWnd, POINT size);
	void Progress();
private:
	void Update();
	void Rendering();

private:
	HWND	m_hWnd;
};
