#pragma once
#include "raylib.h"
#include "logic/TextureManager.h"

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
		float _timer;
		bool _shocked;
		bool _frozen;
		int _startPoint;
	public:
		Enemy1();
		~Enemy1();
		void setLife(int life);
		void setSpeed(int x, int y);
		Vector2 getPos();
		void movement();
		float getSpeedX();
		float getSpeedY();
		float getTimer();
		void increaseTimer(float increase);
		void moveToPoint(Vector2 Point);
		bool getShocked();
		void setShocked(bool set);
		void setFrozen(bool set);
		void draw();
	};


}
