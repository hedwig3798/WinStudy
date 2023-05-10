#include "KeyMg.h"

int g_arrVK[(int)KEY::LAST] =
{
	VK_LEFT,	//LEFT,
	VK_RIGHT,	//RIGHT,
	VK_UP,		//UP,
	VK_DOWN,	//DOWN,
	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',
	'Z',
	'X',
	'C',
	'V',
	'B',
	'N',
	'M',

	VK_MENU,
	VK_CONTROL,
	VK_LSHIFT,
	VK_SPACE,
	VK_RETURN,
	VK_ESCAPE,
};

KeyMg::KeyMg()
{
}

KeyMg::~KeyMg()
{
}

void KeyMg::Init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_key.push_back(keyInfo{ KEY_STATE::NONE, false });
	}
}

void KeyMg::Update()
{
	HWND hWnd = GetFocus();

	if (hWnd != NULL)
	{
		for (int i = 0; i < (int)KEY::LAST; i++)
		{
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
			{
				if (m_key[i].prevPush)
				{
					m_key[i].state = KEY_STATE::HOLD;
				}
				else
				{
					m_key[i].state = KEY_STATE::DOWN;
				}
				m_key[i].prevPush = TRUE;
			}
			else
			{
				if (m_key[i].prevPush)
				{
					m_key[i].state = KEY_STATE::UP;
				}
				else
				{
					m_key[i].state = KEY_STATE::NONE;
				}
				m_key[i].prevPush = FALSE;
			}
		}
	}
	else
	{
		for (int i = 0; i < (int)KEY::LAST; i++)
		{
			m_key[i].prevPush = false;

			if (m_key[i].state == KEY_STATE::DOWN || m_key[i].state == KEY_STATE::HOLD)
			{
				m_key[i].state = KEY_STATE::UP;
			}
			else if (m_key[i].state == KEY_STATE::UP)
			{
				m_key[i].state = KEY_STATE::NONE;
			}
		}
	}
}
