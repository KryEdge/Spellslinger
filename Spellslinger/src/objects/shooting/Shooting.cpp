#include "raylib.h"


namespace sSlinger {
	void shoot(Vector2 bullet) {
		int posX = GetMouseX();
		int posY = GetMouseY();		

		while (bullet.x <= posX && bullet.y >= posY) {
			bullet.x += 7;
			bullet.y -= 7;
		}

	}
}
