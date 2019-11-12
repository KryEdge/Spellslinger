#pragma once
#include "raylib.h"

namespace sSlinger {
	class Enemy1
	{
	private:
	
	int _life;

	public:
		Vector2 pos;
		Enemy1();
		~Enemy1();
		void setLife(int life);
		float calculateSin(float w, float phase);
		void movement();
	};


}
