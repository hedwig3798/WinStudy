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
	virtual ~Scene();

	const wstring& GetSceneName() const
	{
		return m_sceneName;
	}
	void SetSceneName(const wstring& val)
	{
		m_sceneName = val;
	}

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	void Update();
	void Render(HDC _dc);

protected:
	void AddObject(Object* _obj, GROUP_TYPE _type)
	{
		m_arrObject[(UINT)_type].push_back(_obj);
	}
};

