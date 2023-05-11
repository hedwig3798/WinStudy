#include "Player.h"
#include "Missile.h"
#include "SceneMg.h"
#include "Scene.h"
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
	if (KEY_DOWN(KEY::SPACE))
	{
		CreateMissile();
	}
	SetPos(curPos);
}

void Player::Render(HDC _dc)
{
	RECT rt;
	rt = GetRect();

	Rectangle(_dc, rt.left, rt.top, rt.right, rt.bottom);
}

void Player::CreateMissile()
{
	Vec2 missilePos = GetPos();
	missilePos.y -= 20;

	Missile* missile = new Missile;
	missile->SetPos(missilePos);
	missile->SetScale(Vec2{ 25, 25 });
	missile->SetDirection(-1);

	Scene* curScene = SceneMg::GetInst()->GetCurScene();
	curScene->AddObject(missile, GROUP_TYPE::MISSILE);
}
