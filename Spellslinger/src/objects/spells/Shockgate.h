#pragma once
#include "raylib.h"

class Shockgate {
private:
	float _radius;
	float _timer;
	bool _trigger;
	Vector2 _target;
	Vector2 _pos;
	Vector2 _distance;
	Vector2 _mousePos1;
	Vector2 _mousePos2;
public:
	Shockgate();
	~Shockgate();
	void effect();
	void setTrigger(bool trigger);
	bool getActive();
	void setPos(Vector2 bulletPos);
	Vector2 getPos();
	void setTarget(Vector2 target);
	Vector2 getTarget();
	void setMousePos1(int mouseX, int mouseY);
	void setMousePos2(int mouseX, int mouseY);
	Vector2 getMousePos1();
	Vector2 getMousePos2();
	float getAoe();
	float getTimer();
	void increaseTimer(float increase);
	void vecBullet();
	void moveBullet();
};

