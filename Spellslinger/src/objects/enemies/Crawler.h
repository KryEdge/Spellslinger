#pragma once
#include "raylib.h"
#include "logic/TextureManager.h"


namespace sSlinger {
	class Crawler {
	private:
		Vector2 _pos;
		int _life;
		int _winWidth;
		int _winHeight;
		float _speedY;
		float _speedX;
		float _timer;
		bool _shocked;
		bool _frozen;
		int _startPoint;
		bool _active;
		int _ID;
	public:
		static int ID;
		Crawler();
		~Crawler();
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
		bool getActive();
		void setActive(bool active);
		void draw();
	};


}
