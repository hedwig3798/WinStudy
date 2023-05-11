#include "SceneMg.h"
#include "SceneStart.h"

class SceneStart;

SceneMg::SceneMg()
	:m_arrScene{},
	m_curScene(nullptr)
{
}

SceneMg::~SceneMg()
{
	for (int i = 0; i < (UINT)SCENE_TYPE::END; i++)
	{
		if (m_arrScene[i] != nullptr)
		{
			delete m_arrScene[i];
		}
	}
}

void SceneMg::Init()
{
	m_arrScene[(UINT)SCENE_TYPE::START] = new SceneStart;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetSceneName(L"Start Scene");

	m_curScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_curScene->Enter();
}

void SceneMg::Update()
{
	m_curScene->Update();
}

void SceneMg::Render(HDC _dc)
{
	m_curScene->Render(_dc);
}
