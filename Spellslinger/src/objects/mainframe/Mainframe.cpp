#include "objects/mainframe/Mainframe.h"
#include "raylib.h"
#include"objects/spells/Shockgate.h"
#include "objects/spells/Vacuum.h"


namespace sSlinger {
	Player* player;
	Enemy1* flyer;
	Bullet* fireball;
	Shockgate* shockgate;
	FFreeze* fFreeze;
	Vacuum* vacuum;
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
		bool vacuumBool = false;
		bool shockBool = false;
		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(BLACK);
			DrawRectangleRec(player->getRec(), ballColor);
			DrawRectangle(player->getRec().x - 30, player->getRec().y + 20, 60, 40, SKYBLUE);
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

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellManager->getSelected() == 2) {
				if(shockgate == NULL)shockgate = new Shockgate;
				if(!shockgate->getActive()) shockgate->setMousePos1(GetMouseX(), GetMouseY());
				shockgate->setTrigger(true);
				shockgate->setMousePos2(GetMouseX(), GetMouseY());
				shockBool = true;
			}

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellManager->getSelected() == 3) {
				FFreezeBool = true;
				fFreeze = new FFreeze;
			}
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellManager->getSelected() == 4) {
				vacuum = new Vacuum;
				vacuum->setTarget(Vector2{ static_cast<float>(GetMouseX()),static_cast<float>(GetMouseY()) });
				vacuum->vecBullet();
				vacuum->setTrigger(true);
				vacuumBool = true;
			}

			if (vacuumBool) {
				if (vacuum->getPos().x >= vacuum->getTarget().x || vacuum->getPos().y <= vacuum->getTarget().y) {
					vacuum->setPos(vacuum->getPos());
					vacuum->effect();
					vacuum->increaseTimer(0.05);
					vacuum->setTrigger(false);
					if (CheckCollisionCircles(vacuum->getPos(), vacuum->getAoe(), flyer->getPos(), 10)) {
						flyer->setSpeed(0, 0);
						flyer->moveToPoint(vacuum->getPos());
					}
				}
			}

			if (shockBool) {
				DrawCircleV(shockgate->getMousePos1(), 10, YELLOW);
				DrawCircleV(shockgate->getMousePos2(), 10, YELLOW);
				DrawLineV(shockgate->getMousePos1(), shockgate->getMousePos2(), GOLD);
				shockgate->increaseTimer(0.05);
				if (shockgate->getTimer() > 12.0f) {
					shockBool = false;
					delete shockgate;
					shockgate = NULL;
				}

			}

			if (FFreezeBool) {
				timer += 1 * GetFrameTime();
				if (timer >= 4.0f) {
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
			if (vacuum != NULL)
				if (vacuum->getActive()) {
					vacuum->moveBullet();
					DrawCircleV({ vacuum->getPos().x, vacuum->getPos().y }, 10.0f, WHITE);
				}

			EndDrawing();
			if (vacuum != NULL)
				if (vacuum->getTimer() > 6.0f) {
					vacuumBool = false;
					delete vacuum;
					vacuum = NULL;
				}

			if (fireball != NULL && flyer != NULL)
				if (CheckCollisionCircles(flyer->getPos(), 20, fireball->getPos(), fireball->getHitbox())) {
					delete fireball;
					fireball = NULL;
					delete flyer;
					flyer = NULL;
					flyer = new Enemy1;
				}
			if (flyer->getPos().x < 0) {
				delete flyer;
				flyer = NULL;
				flyer = new Enemy1;
			}
		}
			CloseWindow();
		}
	}

	




	