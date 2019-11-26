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
		bool _active;
	public:
		static int ID;
		Enemy1();
		~Enemy1();
		void setLife(int life);
		Vector2 getPos();
		void movement();
		void setSpeed(int x, int y);
		float getSpeedX();
		float getSpeedY();
		void moveToPoint(Vector2 Point);
		float getTimer();
		void increaseTimer(float increase);
		bool getShocked();
		void setShocked(bool set);
		void setFrozen(bool set);
		void draw();
		bool getActive();
		void setActive(bool active);
	};


}
