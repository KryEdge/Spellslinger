#include "objects/mainframe/Mainframe.h"
#include "raylib.h"


namespace sSlinger {
	Player* player;
	Enemy1* flyer;
	Bullet* fireball;
	FFreeze* fFreeze;
	SpellManager* spellManager;
	static float timer = 0;

	Mainframe::Mainframe() {
		_winWidth = 800;
		_winHeight = 450;

	}
	Mainframe::~Mainframe() {

	}

	void Mainframe::initProgram() {
		InitWindow(_winWidth, _winHeight, "Spellslinger");
		player = new Player();
		SetTargetFPS(60);
		flyer = new Enemy1;
		spellManager = new SpellManager;
		spellManager->initializeButtons();
	}
		
	void Mainframe::runProgram() {
		initProgram();
		Color ballColor = DARKBLUE;
		bool FFreezeBool = false;
		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(BLACK);
			DrawRectangleRec(player->getRec(), ballColor);
			DrawRectangle(player->getRec().x-30, player->getRec().y + 20, 60, 40, SKYBLUE);
			DrawCircleLines(GetMouseX(), GetMouseY(), 15, ballColor);
			DrawText(FormatText("v 0.1"), GetScreenWidth() - 50, 1, 20, { 255,255,255,100 });
			if (flyer != NULL) {
				DrawCircleV(flyer->getPos(), 10, YELLOW);
				flyer->movement();
			}

			spellManager->spellmanager();

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellManager->getSelected() == 1) {
				fireball = new Bullet;
				fireball->setActive(true);
				fireball->vecBullet();
			}

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellManager->getSelected() == 3) {
				FFreezeBool = true;
				fFreeze = new FFreeze;

			}

			if (FFreezeBool) {
				timer += 1 * GetFrameTime();
				if (timer >= 2.5f) {
					FFreezeBool = false;
					timer = 0;
				}
			}

			if (fireball != NULL)
				if (fireball->getActive()) {
					fireball->moveBullet();
					DrawCircleV({ fireball->getPos().x, fireball->getPos().y }, fireball->getHitbox(), RED);
					if (fireball->getPos().x > _winWidth || fireball->getPos().x < 0 || fireball->getPos().y > _winHeight || fireball->getPos().y < 0) {
						fireball->setActive(false);
						delete fireball;
						fireball = NULL;
					}
				}
			EndDrawing();

			if (fireball != NULL && flyer != NULL)
				if (CheckCollisionCircles(flyer->getPos(), 20, fireball->getPos(), fireball->getHitbox())) {
					delete fireball;
					fireball = NULL;
					delete flyer;
					flyer = NULL;

					flyer = new Enemy1;
				}
		}
		CloseWindow();
	}
}




	