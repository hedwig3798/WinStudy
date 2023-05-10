#pragma once
#include "pch.h"

enum KEY_STATE
{
	NONE,	// 눌리지 않았고, 이전에도 눌리지 않은 상태
	DOWN,	// 막 누른 시점
	HOLD,	// 누르고 있는
	UP,	// 막 땐 시점
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
	KEY_STATE	state;		// 키의 상태값
	bool		prevPush;		// 이전 프레임에서 눌렸는지 여부
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

