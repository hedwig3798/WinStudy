#pragma once
#include "pch.h"
class Res
{
private:
	wstring m_strKey;
	wstring m_relativePath;
public:
	Res();
	~Res();

	const wstring& GetRelativePath()
	{
		return m_relativePath;
	}
	void SetRelativePath(const wstring& val)
	{
		m_relativePath = val;
	}
	const wstring& GetKey()
	{
		return m_strKey;
	}
	void SetKey(const wstring& val)
	{
		m_strKey = val;
	}
};

