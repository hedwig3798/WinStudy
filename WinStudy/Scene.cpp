#include "Scene.h"
#include "Object.h"

Scene::Scene()
{

}

Scene::~Scene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for(auto obj : m_arrObject[i])
		{
			delete obj;
		}
	}
}

void Scene::Update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for(auto obj : m_arrObject[i])
		{
			obj->Update();
		}
	}
}

void Scene::Render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for (auto obj : m_arrObject[i])
		{
			obj->Render(_dc);
		}
	}
}

