#include "objects/spells/Shockgate.h"

Shockgate::Shockgate() {
	_radius = 150.0f;
	_trigger = false;
	_target.x = GetMouseX();
	_target.y = GetMouseY();
	_pos.x = 40.0f;
	_pos.y = 330.0f;
	_timer = 0.0f;
	_distance.x = NULL;
	_distance.y = NULL;
	_mousePos1.x = 0.0f;
	_mousePos1.y = 0.0f;
	_mousePos2.x = 0.0f;
	_mousePos2.y = 0.0f;
}
Shockgate::~Shockgate() {

}
void Shockgate::effect() {
	Color effectColor = GOLD;
	DrawCircleV(getPos(), _radius, Fade(effectColor, 0.2f));
}
void Shockgate::setTrigger(bool trigger) {
	_trigger = trigger;
}
bool Shockgate::getActive() {
	return _trigger;
}
float Shockgate::getTimer() {
	return _timer;
}
void Shockgate::increaseTimer(float increase) {
	_timer += increase;
}

Vector2 Shockgate::getPos() {
	return _pos;
}
Vector2 Shockgate::getTarget() {
	return _target;
}
void Shockgate::setPos(Vector2 bulletPos) {
	_pos = bulletPos;
}
void Shockgate::setTarget(Vector2 target) {
	_target = target;
}
void Shockgate::setMousePos1(int mouseX, int mouseY) {
	_mousePos1.x = static_cast<float>(mouseX);
	_mousePos1.y = static_cast<float>(mouseY);
}
void Shockgate::setMousePos2(int mouseX, int mouseY) {
	_mousePos2.x = static_cast<float>(mouseX);
	_mousePos2.y = static_cast<float>(mouseY);
}
Vector2 Shockgate::getMousePos1() {
	return _mousePos1;
}
Vector2 Shockgate::getMousePos2() {
	return _mousePos2;
}

float Shockgate::getAoe() {
	return _radius;
}
void Shockgate::vecBullet() {
	_distance.x = _target.x - _pos.x;
	_distance.y = _target.y - _pos.y;
}
void Shockgate::moveBullet() {

	_pos.x += _distance.x / 60;
	_pos.y += _distance.y / 60;

}