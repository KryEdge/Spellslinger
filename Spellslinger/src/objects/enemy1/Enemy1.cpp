#include "objects/enemy1/Enemy1.h"
#include <cmath>

namespace sSlinger {
	Enemy1::Enemy1(){
		_winWidth = 810;
		_winHeight = 450;
		_pos.x = _winWidth;
		_pos.y = _winHeight / 2;
		_life = 20;
		_speedY = 50.0f;
		_speedX = 205.0f;
		_inc = 0.05f;
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
		_pos.x -= _speedX * GetFrameTime();
		_pos.y += _speedY * GetFrameTime();

		if (_pos.y > 350) {
			_speedY = -75.0;	
			_speedX = 205.0;
			_inc = 0.05f;
		}
		else if (_pos.y < 135) {
			_speedY = 75.0;
			_speedX = 205.0;
			_inc = 10.05f;
		}
		else if (_pos.y > 135 && _pos.y < 350) {
			if (_speedY < 0) {
				_speedY -= _inc;
				_speedX -= 5.0f;
				_inc += 2.5f;
			}
			else {
				_speedY += _inc;
				_speedX -= 5.0f;
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
}
