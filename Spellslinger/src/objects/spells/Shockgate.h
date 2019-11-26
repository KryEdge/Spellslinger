#pragma once
#include "raylib.h"
#include "objects/enemies/Crawler.h"
#include "objects/enemies/Enemy1.h"

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
	float getTimer();
	void increaseTimer(float increase);
	Vector2 getPos();
	Vector2 getTarget();
	void setPos(Vector2 bulletPos);
	void setTarget(Vector2 target);
	void setMousePos1(int mouseX, int mouseY);
	void setMousePos2(int mouseX, int mouseY);
	Vector2 getMousePos1();
	Vector2 getMousePos2();
	float getAoe();
	void vecBullet();
	void moveBullet();
	bool hitboxCheckFlyers(Vector2 posFlyer);
	bool hitboxCheckCrawlers(Vector2 posCrawler);
};

