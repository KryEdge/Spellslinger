#include "raylib.h"
#include "objects/mainframe/Mainframe.h"


namespace sSlinger {
	int speed = 8;
	int _winWidth = 450;

	void moveBullet(Vector2 &bullet) {
		int posX = GetMouseX();
		int posY = GetMouseY();
		int realY = _winWidth - posY;
		if (posX > _winWidth - posY) {
			bullet.x += (speed * (posX / realY));
			bullet.y -= speed;
		}
		else {
			bullet.x += 7;
			bullet.y -= (speed * (posY/ realY));
		}
	}

	float calculateIncline(float x1, float y1, float x2, float y2)
	{
		float m;
		m = (y2 - y1) / (x2 - x1);
		return m;
	}

	void returnBullet(Vector2 &bullet) {
		bullet.x = 20;
		bullet.y = 430;
	}
}
