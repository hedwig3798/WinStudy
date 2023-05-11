#pragma once
#include "pch.h"
#include "Res.h"
class Texture 
	: public Res
{
private:
	HDC m_dc;
	BITMAP m_bitmap;
public:
	Texture();
	~Texture();
};

