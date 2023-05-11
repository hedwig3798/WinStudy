#pragma once
#include "Object.h"
class Player :
    public Object
{
public:
    Player();
    ~Player();

    virtual void Update();
    virtual void Render(HDC _dc);

private:
	void CreateMissile();
};

