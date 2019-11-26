#pragma once
#include "raylib.h"

class Vacuum {
private:
	float _aoe;
	float _timer;
	bool _trigger;
	Vector2 _target;
	Vector2 _pos;
	Vector2 _distance;
public:
	Vacuum();
	~Vacuum();
	void effect();
	void setTrigger(bool trigger);
	bool getActive();
	float getTimer();
	void increaseTimer(float increase);
	Vector2 getPos();
	Vector2 getTarget();
	void setPos(Vector2 bulletPos);	
	void setTarget(Vector2 target);
	float getAoe();
	void vecBullet();
	void moveBullet();
};

