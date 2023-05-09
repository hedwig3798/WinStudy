#pragma once
#include "pch.h"
#include "Object.h"
#include "TimeMg.h"
class Core
{
	// �̱���
	SINGLE(Core)

public:
	// �ʱ�ȭ
	void Init(HWND _hWnd, POINT _size);
	// ���� ����
	void Progress();
private:
	void Update();
	void Rendering();

private:
	HWND m_hWnd;
	HDC m_hDC;
	Object m_obj;
};
