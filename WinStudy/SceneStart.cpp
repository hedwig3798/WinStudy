#include "SceneStart.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"
SceneStart::SceneStart()
{

}

SceneStart::~SceneStart()
{

}

void SceneStart::Enter()
{
	Object* obj = new Player;
	obj->SetPos(Vec2{ 620, 384 });
	obj->SetScale(Vec2{ 100, 100 });
	AddObject(obj, GROUP_TYPE::PLAYER);

	Vec2 screenSize = Core::GetInst()->GetScreenSize();

	int monsterCount = 20;
	float movement = 25;
	
	float scale = 50;
	float term = (screenSize.x - ((movement + scale / 2) * 2)) / (monsterCount - 1);
	Monster* mobj = nullptr;
	for (int i = 0; i < monsterCount; i++)
	{
		mobj = new Monster;
		mobj->SetMoveRange(movement);
		mobj->SetPos(Vec2{ (movement + scale / 2) + term * i, 50.0f });
		mobj->SetScale(Vec2{ 50, 50 });
		mobj->SetCenterPos(mobj->GetPos());
		AddObject(mobj, GROUP_TYPE::MONSTER);
	}	
}

void SceneStart::Exit()
{

}
