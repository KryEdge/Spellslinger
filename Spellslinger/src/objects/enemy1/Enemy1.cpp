#include "objects/enemy1/Enemy1.h"
#include "objects/mainframe/Mainframe.h"
#include <cmath>

namespace sSlinger {
	Enemy1::Enemy1(){
		_winWidth = 750;
		_winHeight = 450;
		_pos.x = _winWidth;
		_pos.y = _winHeight / 2;
		_life = 20;
		_speedY = 1.0f;
		_speedX = 3.0f;
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
		_pos.x -= _speedX;
		_pos.y += _speedY;

		if (_pos.y > 350) {
			_speedY = -1.0;	
			_speedX = 3.0;
			_inc = 0.05f;
		}
		else if (_pos.y < 135) {
			_speedY = 1.0;
			_speedX = 3.0;
			_inc = 0.05f;
		}
		else if (_pos.y > 135 && _pos.y < 350) {
			if (_speedY < 0) {
				_speedY -= _inc;
				_speedX -= 0.05f;
				_inc += 0.08f;
			}
			else {
				_speedY += _inc;
				_speedX -= 0.05f;
				_inc += 0.08f;
			}
		}
		
	}
}
