#pragma once
#include "pch.h"

enum KEY_STATE
{
	NONE,	// ������ �ʾҰ�, �������� ������ ���� ����
	DOWN,	// �� ���� ����
	HOLD,	// ������ �ִ�
	UP,	// �� �� ����
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,
	Z,
	X,
	C,
	V,
	B,
	N,
	M,

	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LAST,
};

struct keyInfo
{
	KEY_STATE	state;		// Ű�� ���°�
	bool		prevPush;		// ���� �����ӿ��� ���ȴ��� ����
};

class KeyMg
{
	SINGLE(KeyMg)
	
public:
	void Init();
	void Update();

public:
	KEY_STATE GetKeyState(KEY key) 
	{ 
		return m_key[(int)key].state; 
	}

private:
	vector<keyInfo> m_key;
};

