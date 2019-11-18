#include "FFreeze.h"

FFreeze::FFreeze() {
	_aoe = 100;
	_trigger = false;
	_target.x = GetMouseX();
	_target.y = GetMouseY();
	_pos = { 0, 0 };
}
FFreeze::~FFreeze(){

}

bool FFreeze::getTrigger() {
	return _trigger;
}

void FFreeze::setTrigger(bool trigger) {
	_trigger = trigger;
}

Vector2 FFreeze::getPos() {
	return _pos;
}