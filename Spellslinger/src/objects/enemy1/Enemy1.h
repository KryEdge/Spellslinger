#pragma once
#include "raylib.h"

namespace sSlinger {
	class Enemy1{
	private:
		Vector2 _pos;
		int _life;
		int _winWidth;
		int _winHeight;
		float _speedY;
		float _speedX;
		float _inc;
	public:
		Enemy1();
		~Enemy1();
		void setLife(int life);
		void setSpeed(int x, int y);
		Vector2 getPos();
		void movement();
		float getSpeedX();
		float getSpeedY();
		void moveToPoint(Vector2 Point);
	};


}
