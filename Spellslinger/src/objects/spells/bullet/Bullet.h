#pragma once
#include "raylib.h"
#include "logic/TextureManager.h"

class Bullet {
private:
	float _hitbox;
	float _aoe;
	bool _trigger;
	Vector2 _target;
	Vector2 _pos;
	Vector2 _distance;
	float _dmg;
	bool _active;
public:
	Bullet();
	~Bullet();
	void setTrigger(bool trigger);
	bool getTrigger();
	float getHitbox();
	void setActive(bool active);
	bool getActive();
	Vector2 getPos();
	void moveBullet();
	void vecBullet();
};