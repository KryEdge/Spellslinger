#include "Vacuum.h"

Vacuum::Vacuum() {
	_aoe = 150.0f;
	_trigger = false;
	_target.x = GetMouseX();
	_target.y = GetMouseY();
	_pos.x = 40.0f;
	_pos.y = 430.0f;
	_timer = 0.0f;
}
Vacuum::~Vacuum() {

}
void Vacuum::effect() {
	DrawCircleV(getPos(), _aoe, WHITE);
}
void Vacuum::setTrigger(bool trigger) {
	_trigger = trigger;
}
float Vacuum::getTimer() {
	return _timer;
}
void Vacuum::increaseTimer(float increase) {
	_timer += increase;
}
/*
bool Vacuum::getTrigger() {
	return _trigger;
}*/
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