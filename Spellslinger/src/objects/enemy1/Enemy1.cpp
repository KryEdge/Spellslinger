#include "objects/enemy1/Enemy1.h"
#include "objects/mainframe/Mainframe.h"
#include<cmath>

namespace sSlinger {
	float oscilation = 1.5f;
	float Pi = static_cast<float>(3.1416);
	float w = (2 * Pi * oscilation);
	float Amp = 25.f;
	int winWidth = 800;
	int winHeight = 450;
	Enemy1::Enemy1()
	{
		pos.x = winWidth - 100;
		pos.y = winHeight / 2;
	}
	Enemy1::~Enemy1()
	{
	}
	float Enemy1::calculateSin(float w, float phase) {
		float sinArgument = ((w * pos.x) + phase);
		float sin(sinArgument);
		return sin;
	}
	void Enemy1::setLife(int life){
		_life = life;
	}

	void Enemy1::movement() {
		pos.x -= 5;
		pos.y = Amp * calculateSin(w, 10.f);
	}

}
