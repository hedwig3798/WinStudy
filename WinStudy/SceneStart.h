#pragma once
#include "Scene.h"
#include "pch.h"
class SceneStart :
    public Scene
{
public:
    SceneStart();
    ~SceneStart();

    virtual void Enter();
    virtual void Exit();
};

