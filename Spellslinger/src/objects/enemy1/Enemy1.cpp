#include "objects/enemy1/Enemy1.h"

namespace sSlinger {
	Enemy1::Enemy1(){
		_winWidth = 810;
		_winHeight = 450;
		_pos.x = _winWidth;
		_pos.y = _winHeight / 2;
		_life = 20;
		_speedY = 125.0f;
		_speedX = 155.0f;
		_inc = 0.05f;
		_timer = 0.0f;
		_shocked = false;
		_frozen = false;
	}
	Enemy1::~Enemy1(){

	}

	void Enemy1::setLife(int life){
		_life = life;
	}
	Vector2 Enemy1::getPos() {
		return _pos;
	}
	void Enemy1::movement() {
		if (!_frozen) {
			_pos.x -= _speedX * GetFrameTime();
			_pos.y += _speedY * GetFrameTime();
		}

		if (_pos.y >= 280) {
			if (!_shocked) { _speedY = -125.0; _speedX = 155.0;}
			else { _speedY = -62.5; _speedX = 75.0;}
			_inc = 10.05f;
		}
		else if (_pos.y <= 155) {
			if (!_shocked) { _speedY = 125.0; _speedX = 155.0; }
			else { _speedY = 62.5; _speedX = 75.0;	}
			_inc = 10.05f;
		}
		else if (_pos.y > 155 && _pos.y < 280) {
			if (_speedY < 0) {
				_speedY -= _inc;
				_inc += 2.5f;
			}
			else {
				_speedY += _inc;
				_inc += 2.5f;
			}
		}
		
	}
	void Enemy1::setSpeed(int x, int y) {
		_speedX = x;
		_speedY = y;
	}
	float Enemy1::getSpeedX() {
		return _speedX;
	}

	float Enemy1::getSpeedY() {
		return _speedY;
	}

	void Enemy1::moveToPoint(Vector2 Point) {
		if (_pos.x != Point.x) {
			if (Point.x > _pos.x)
				_pos.x += 2.5;
			else
				_pos.x -= 2.5;
		}
		if (_pos.y != Point.y) {
			if (Point.y > _pos.y)
				_pos.y += 2.5;
			else
				_pos.y -= 2.5;
		}
	}
	float Enemy1::getTimer() {
		return _timer;
	}
	void Enemy1::increaseTimer(float increase) {
		_timer += increase;
	}
	bool Enemy1::getShocked() {
		return _shocked;
	}
	void Enemy1::setShocked(bool set) {
		_shocked = set;
	}
	void Enemy1::setFrozen(bool set) {
		_frozen = set;
	}
}
