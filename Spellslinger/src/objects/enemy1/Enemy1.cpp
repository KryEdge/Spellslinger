#include "objects/enemy1/Enemy1.h"
#include "objects/mainframe/Mainframe.h"
#include<cmath>

namespace sSlinger {
	int winWidth = 750;
	int winHeight = 450;
	float speedY = 1.0f;
	float speedX = 3.0f;
	float inc = 0.05f;
	Enemy1::Enemy1()
	{
		pos.x = winWidth;
		pos.y = winHeight / 2;
	}
	Enemy1::~Enemy1()
	{
	}

	void Enemy1::setLife(int life){
		_life = life;
	}

	void Enemy1::movement() {
		pos.x -= speedX;
		pos.y += speedY;

		if (pos.y > 350) {
			speedY = -1.0;	
			speedX = 3.0;
			inc = 0.05f;
		}
		else if (pos.y < 135) {
			speedY = 1.0;
			speedX = 3.0;
			inc = 0.05f;
		}
		else if (pos.y > 135 && pos.y < 350) {
			if (speedY < 0) {
				speedY -= inc;
				speedX -= 0.05f;
				inc += 0.08f;
			}
			else {
				speedY += inc;
				speedX -= 0.05f;
				inc += 0.08f;
			}
		}
		
	}

}
