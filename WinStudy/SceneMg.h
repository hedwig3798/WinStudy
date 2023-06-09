#pragma once
#include "pch.h"

class Scene;

class SceneMg
{
	SINGLE(SceneMg)
private:
	Scene* m_arrScene[(int)SCENE_TYPE::END];
	Scene* m_curScene;
public:
	void Init();
	void Update();
	void Render(HDC _dc);
	Scene* GetCurScene() const
	{
		return m_curScene;
	}
	void SetCurScene(Scene* val)
	{
		m_curScene = val;
	}
};

