#pragma once
#include "raylib.h"

class Vacuum {
private:
	float _aoe;
	float _timer;
	bool _trigger;
	Vector2 _target;
	Vector2 _pos;
public:
	Vacuum();
	~Vacuum();
	void effect();
	void setTrigger(bool trigger);
	//bool getTrigger();
	void setPos(Vector2 bulletPos);	
	Vector2 getPos();
	void setTarget(Vector2 target);
	Vector2 getTarget();
	float getAoe();
	float getTimer();
	void increaseTimer(float increase);
};

