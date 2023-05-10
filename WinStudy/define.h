#pragma once

#define SINGLE(type) public:\
					 static type* GetInst()\
					{\
						static type mgr;\
						return &mgr;\
					}\
					 private:\
						type(); \
						~type();

#define DT TimeMg::GetInst()->GetDt()

#define KEY_CHECK(key, state) KeyMg::GetInst()->GetKeyState(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_UP(key) KEY_CHECK(key, KEY_STATE::UP)
#define KEY_DOWN(key) KEY_CHECK(key, KEY_STATE::DOWN)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)

enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MISSILE,
	MONSTER,
	END = 32,
};
