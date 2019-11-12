#include "raylib.h"

class Bullet {
private:
	float _aoe;
	bool _trigger;
	Vector2 _target;
	float _dmg;
public:
	Bullet();
	~Bullet();
	void setTrigger();
	bool getTrigger();
};