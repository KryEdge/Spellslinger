#include "objects/mainframe/Mainframe.h"
#include "raylib.h"


namespace sSlinger {
	Player* player;
	Enemy1* flyer[E1MAX];
	Bullet* fireball;
	Crawler* crawler;
	Shockgate* shockgate;
	FFreeze* fFreeze;
	Vacuum* vacuum;
	SpellManager* spellManager;
	static float timer = 0;
	
	Mainframe::Mainframe() {
		_winWidth = 800;
		_winHeight = 450;
		_floor = { 0.0f,static_cast<float>(_winHeight),static_cast<float>(_winWidth),10.0f };
	}
	Mainframe::~Mainframe() {

	}

	void Mainframe::initProgram() {
		InitWindow(_winWidth, _winHeight, "Spellslinger");
		SetTargetFPS(60);
		player = new Player();
		SetTargetFPS(60);
		for (int i = 0; i < E1MAX; i++) {
			flyer[i] = NULL;
			flyer[i] = new Enemy1;
		}
		crawler = new Crawler();
		spellManager = new SpellManager;
		spellManager->initializeButtons();
	}

	void Mainframe::runProgram() {

		Color ballColor = RED;
		bool FFreezeBool = false;
		bool vacuumBool = false;
		bool shockBool = false;
		_gameBool = true;
		TextureManager::loadTextures();

		while (_gameBool) {
			BeginDrawing();
			ClearBackground(BLACK);
			DrawTexture(TextureManager::getBackground(), 0, 0, WHITE);
			DrawRectangleRec(_floor, RED);
			player->draw();
			DrawRectangle(player->getRec().x - 30, player->getRec().y + 20, 60, 40, SKYBLUE);
			DrawCircleLines(GetMouseX(), GetMouseY(), 15, ballColor);
			DrawText(FormatText("v 0.1.5"), GetScreenWidth() - 50, 1, 20, { 255,255,255,100 });
			for (int i = 0; i < E1MAX; i++) {
				if (flyer[i] != NULL) {
					if (!FFreezeBool) {//NO ES REDUNDANTE ESTO CON EL CHEQUEO DE FREEZE QUE TIENE EL MOVEMENT?
						flyer[i]->movement();
					}
					flyer[i]->draw();
				}
			}
			if (crawler != NULL) {
				crawler->draw();
				crawler->movement();
			}
	
			spellManager->spellmanager();

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellManager->getSelected() == 1) {
				fireball = new Bullet;
				fireball->setActive(true);
				fireball->vecBullet();
			}

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellManager->getSelected() == 2) {
				if (shockgate == NULL)shockgate = new Shockgate;
				if (!shockgate->getActive()) shockgate->setMousePos1(GetMouseX(), GetMouseY());
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
				if (vacuum->getPos().x >= vacuum->getTarget().x || vacuum->getPos().y <= vacuum->getTarget().y || IsMouseButtonReleased(MOUSE_RIGHT_BUTTON) && spellManager->getSelected() == 4) {
					vacuum->effect();
					vacuum->increaseTimer(0.05);
					vacuum->setTrigger(false);
					for (size_t i = 0; i < E1MAX; i++)
						if (CheckCollisionCircles(vacuum->getPos(), vacuum->getAoe(), flyer[i]->getPos(), 10)) {
							for (size_t i = 0; i < E1MAX; i++) {
								flyer[i]->setSpeed(0, 0);
								flyer[i]->moveToPoint(vacuum->getPos());
							}
						}
					crawler->moveToPoint(vacuum->getPos());
				}
			}

			if (shockBool) {
				DrawCircleV(shockgate->getMousePos1(), 10, YELLOW);
				DrawCircleV(shockgate->getMousePos2(), 10, YELLOW);
				DrawTriangle(shockgate->getMousePos1(), shockgate->getMousePos2(),
				Vector2{ shockgate->getMousePos2().x + 2,shockgate->getMousePos2().y + 2 }, GOLD);
				shockgate->increaseTimer(0.05);
				if (shockgate->getTimer() > 12.0f) {
					shockBool = false;
					delete shockgate;
					shockgate = NULL;
				}

			}

			if (FFreezeBool) {
				timer += 1 * GetFrameTime();
				if (timer >= 2.0f) {
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

			for (size_t i = 0; i < E1MAX; i++)
			{
				if (shockgate != NULL)//HAY QUE MEJORAR ESTE CHEQUEO HORRENDO, DESPUES HAGO UNA FUNCION
					if (CheckCollisionPointTriangle(flyer[i]->getPos(), shockgate->getMousePos1(), shockgate->getMousePos2(),
						Vector2{ shockgate->getMousePos1().x + 10,shockgate->getMousePos1().y + 10 }) ||
						CheckCollisionPointTriangle(flyer[i]->getPos(), shockgate->getMousePos1(), shockgate->getMousePos2(),
						Vector2{ shockgate->getMousePos2().x + 10,shockgate->getMousePos2().y + 10 }) ||
						CheckCollisionPointTriangle(crawler->getPos(), shockgate->getMousePos1(), shockgate->getMousePos2(),
						Vector2{ shockgate->getMousePos1().x + 10,shockgate->getMousePos1().y + 10 }) ||
						CheckCollisionPointTriangle(crawler->getPos(), shockgate->getMousePos1(), shockgate->getMousePos2(),
						Vector2{ shockgate->getMousePos2().x + 10,shockgate->getMousePos2().y + 10 })
						) {
						flyer[i]->setShocked(true);
						crawler->setShocked(true);
					}

				if (flyer[i]->getShocked()) {
					flyer[i]->increaseTimer(0.05);
					if (flyer[i]->getTimer() > 15.0) {
						flyer[i]->setShocked(false);
					}
				}
				if (crawler->getShocked()) {
					crawler->increaseTimer(0.05);
					if (crawler->getTimer() > 15.0) {
						crawler->setShocked(false);
					}
				}
			}

			for (size_t i = 0; i < E1MAX; i++) {
				if (fireball != NULL && flyer[i] != NULL)
					if (CheckCollisionCircles(flyer[i]->getPos(), 20, fireball->getPos(), fireball->getHitbox())) {
						delete fireball;
						fireball = NULL;
						delete flyer[i];
						flyer[i] = NULL;
						flyer[i] = new Enemy1;
					}

			}
			if (fireball != NULL && crawler != NULL) {
				if (CheckCollisionCircles(crawler->getPos(), 20, fireball->getPos(), fireball->getHitbox())) {
					delete fireball;
					fireball = NULL;
					delete crawler;
					crawler = NULL;
					crawler = new Crawler;
				}
			}

			for (size_t i = 0; i < E1MAX; i++) {
				if (flyer[i]->getPos().x < 0 && flyer[i] != NULL) {
					delete flyer[i];
					flyer[i] = NULL;
					flyer[i] = new Enemy1;
				}
			}
			if (IsKeyReleased(KEY_P)) {
				if (pauseScene() == 1);
					setGameBool(false);	
			}
		}
	
	}

	void Mainframe::setGameBool(bool result) {
		_gameBool = result;
	}
}








