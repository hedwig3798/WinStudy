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

	SetCurScene(m_arrScene[(UINT)SCENE_TYPE::START]);
	GetCurScene()->Enter();
}

void SceneMg::Update()
{
	GetCurScene()->Update();
}

void SceneMg::Render(HDC _dc)
{
	GetCurScene()->Render(_dc);
}
