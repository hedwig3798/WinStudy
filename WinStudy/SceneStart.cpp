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

	float term = (screenSize.x - (75.0f * 2)) / 4;
	Monster* mobj = nullptr;
	for (int i = 0; i < 5; i++)
	{
		mobj = new Monster;
		mobj->SetPos(Vec2{ 75 + term * i, 50.0f });
		mobj->SetScale(Vec2{ 50, 50 });
		mobj->SetCenterPos(mobj->GetPos());
		AddObject(mobj, GROUP_TYPE::MONSTER);
	}
	
}

void SceneStart::Exit()
{

}
