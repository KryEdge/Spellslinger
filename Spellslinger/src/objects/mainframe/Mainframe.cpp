#include "objects/mainframe/Mainframe.h"
#include "raylib.h"


namespace sSlinger {
	Player* player;
	Enemy1* flyer;
	Bullet* spell;
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
		bool FFreeze = false;
		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(BLACK);
			DrawRectangleRec(player->getRec(), ballColor);
			DrawCircleLines(GetMouseX(), GetMouseY(), 15, ballColor);
			DrawText(FormatText("v 0.1"), GetScreenWidth() - 50, 1, 20, { 255,255,255,100 });
			if (flyer != NULL) {
				DrawCircleV(flyer->getPos(), 10, YELLOW);
				flyer->movement();
			}

			spellManager->spellmanager();

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellManager->getSelected() == 1) {
				spell = new Bullet;
				spell->setActive(true);
				spell->vecBullet();
			}

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellManager->getSelected() == 3) {
				FFreeze = true;
			}

			if (FFreeze) {
				timer += 1 * GetFrameTime();
				if (timer >= 2.5f) {
					FFreeze = false;
					timer = 0;
				}
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

			if (spell != NULL && flyer != NULL)
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




	