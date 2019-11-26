#include "Vacuum.h"

Vacuum::Vacuum() {
	_aoe = 150.0f;
	_trigger = false;
	_target.x = GetMouseX();
	_target.y = GetMouseY();
	_pos.x = 40.0f;
	_pos.y = 330.0f;
	_timer = 0.0f;
	_distance.x = NULL;
	_distance.y = NULL;
}
Vacuum::~Vacuum() {

}
void Vacuum::effect() {
	Color effectColor = WHITE;
	DrawCircleV(getPos(), _aoe, Fade(effectColor, 0.2f));
}
void Vacuum::setTrigger(bool trigger) {
	_trigger = trigger;	
}
bool Vacuum::getActive() {
	return _trigger;
}
float Vacuum::getTimer() {
	return _timer;
}
void Vacuum::increaseTimer(float increase) {
	_timer += increase;
}
Vector2 Vacuum::getPos() {
	return _pos;
}
Vector2 Vacuum::getTarget() {
	return _target;
}
void Vacuum::setPos(Vector2 bulletPos) {
	_pos = bulletPos;
}
void Vacuum::setTarget(Vector2 target) {
	_target = target;
}
float Vacuum::getAoe() {
	return _aoe;
}
void Vacuum::vecBullet() {
	_distance.x = _target.x - _pos.x;
	_distance.y = _target.y - _pos.y;
}
void Vacuum::moveBullet() {

	_pos.x += _distance.x / 60;
	_pos.y += _distance.y / 60;

}