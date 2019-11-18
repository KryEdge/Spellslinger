#pragma once
#include "raylib.h"

class FFreeze {
private:
	float _aoe;
	bool _trigger;
	Vector2 _target;
	Vector2 _pos;
public:
	FFreeze();
	~FFreeze();
	void setTrigger(bool trigger);
	bool getTrigger();
	Vector2 getPos();
	void timer();
};
