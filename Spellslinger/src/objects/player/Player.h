#pragma once
#include "raylib.h"
#include "logic/SoundManager.h"
#include "logic/TextureManager.h"

namespace sSlinger {
	class Player {
	private:
		Color _color;
		Rectangle _rec;
		int _lives;
	public:
		Player();
		~Player();
		Rectangle getRec();
		void draw();
	};


}
