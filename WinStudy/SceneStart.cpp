#include "SceneStart.h"
#include "Object.h"
SceneStart::SceneStart()
{

}

SceneStart::~SceneStart()
{

}

void SceneStart::Enter()
{
	Object* obj = new Object;
	obj->SetPos(Vec2{ 620, 384 });
	obj->SetScale(Vec2{ 100, 100 });
	AddObject(obj, GROUP_TYPE::DEFAULT);
}

void SceneStart::Exit()
{

}
