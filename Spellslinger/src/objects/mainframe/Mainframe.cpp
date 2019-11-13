#include "objects/mainframe/Mainframe.h"
#include "raylib.h"
#include "objects/player/Player.h"
#include "objects/enemy1/Enemy1.h"
#include "objects/spells/bullet/Bullet.h"
#include "logic/Spellmanager.h"

namespace sSlinger {
	Mainframe::Mainframe() {
		_winWidth = 800;
		_winHeight = 450;

	}
	Mainframe::~Mainframe() {

	}
	Vector2 bullet{ 20,430 };
	Player jojo;
	Enemy1* flyer;
	Bullet* spell;

	void Mainframe::initProgram() {
		InitWindow(_winWidth, _winHeight, "Spellslinger");
		SetTargetFPS(60);
		Color ballColor = DARKBLUE;
		SetTargetFPS(60);
		flyer = new Enemy1;

		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(BLACK);
			DrawRectangleRec(jojo._rec, ballColor);
			DrawCircleLines(GetMouseX(), GetMouseY(), 15, ballColor);
			if (flyer != NULL) {
				
				DrawCircleV(flyer->getPos(), 20, YELLOW);
				flyer->movement();
			}
			spellmanager();


			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				spell = new Bullet;
				spell->setActive(true);
				spell->vecBullet();
			}

			if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
				flyer->setSpeed(0, 0);
			}


		
			if (spell != NULL)
			if (spell->getActive()) {
				spell->moveBullet();
				DrawCircleV({ spell->getPos().x, spell->getPos().y }, spell->getHitbox(), RED);
				if (spell->getPos().x > _winWidth || spell->getPos().x < 0 || spell->getPos().y > _winHeight || spell->getPos().y < 0) {
					spell->setActive(false);
					delete spell;
					spell = NULL;
				}
			}
			EndDrawing();

			if (spell !=NULL&&flyer!=NULL)
				if (CheckCollisionCircles(flyer->getPos(), 20, spell->getPos(), spell->getHitbox())) {
					delete spell;
					spell = NULL;
					delete flyer;
					flyer = NULL;

					flyer = new Enemy1;
				}
		}
		CloseWindow();
	}


}
	