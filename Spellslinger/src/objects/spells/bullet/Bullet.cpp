#include "objects/spells/bullet/Bullet.h"

Bullet::Bullet() {
	_target.x = GetMouseX();
	_target.y = GetMouseY();
	_aoe = 15.0f;
	_trigger = false;
	_dmg = 20.0f;
}
Bullet::~Bullet() {

}
void Bullet::setTrigger() {
	_trigger = true;
}
bool Bullet::getTrigger() {
	return _trigger;
}