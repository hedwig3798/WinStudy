#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Update()
{
	Vec2 curPos = GetPos();
	if (KEY_HOLD(KEY::W))
	{
		curPos.y -= 200.0f * DT;
	}
	if (KEY_HOLD(KEY::S))
	{
		curPos.y += 200.0f * DT;
	}
	if (KEY_HOLD(KEY::A))
	{
		curPos.x -= 200.0f * DT;
	}
	if (KEY_HOLD(KEY::D))
	{
		curPos.x += 200.0f * DT;
	}

	SetPos(curPos);
}

void Player::Render(HDC _dc)
{
	RECT rt;
	rt = GetRect();

	Rectangle(_dc, rt.left, rt.top, rt.right, rt.bottom);
}
