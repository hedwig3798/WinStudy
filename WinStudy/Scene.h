#pragma once
#include "pch.h"

class Object;

class Scene
{
private:
	vector<Object*> m_arrObject[(UINT)GROUP_TYPE::END];
	wstring m_sceneName;
public:
	Scene();
	~Scene();

	const wstring& GetSceneName() const
	{
		return m_sceneName;
	}
	void SetSceneName(wstring& val)
	{
		m_sceneName = val;
	}
};

