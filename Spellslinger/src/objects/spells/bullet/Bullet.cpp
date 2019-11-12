#include "Bullet.h"

Bullet::Bullet() {
	_target.x = GetMouseX();
	_target.y = GetMouseY();
	_aoe = 50.0f;
	_hitbox = 10.0f;
	_trigger = false;
	_dmg = 20.0f;
	_active = false;
	_pos.x = 40.0f;
	_pos.y = 430.0f;
	_distance.x = NULL;
	_distance.y = NULL;
}
Bullet::~Bullet() {

}
void Bullet::setTrigger(bool trigger) {
	_trigger = trigger;
}
bool Bullet::getTrigger() {
	return _trigger;
}
float Bullet::getHitbox() {
	return _hitbox;
}
bool Bullet::getActive() {
	return _active;
}
void Bullet::setActive(bool active) {
	_active = active;
}

Vector2 Bullet::getPos() {
	return _pos;
}

void Bullet::vecBullet() {
	_distance.x = _target.x - _pos.x;
	_distance.y = _target.y - _pos.y;
}
void Bullet::moveBullet() {
	
	_pos.x += _distance.x / 60;
	_pos.y += _distance.y/ 60;

}