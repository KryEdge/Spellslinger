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
		void setActive(bool active);
		bool getActive();
		void draw();
	};


}
