#include "objects/mainframe/Mainframe.h"
#include "raylib.h"


namespace sSlinger {
	Player* player;
	Enemy1* flyer[E1MAX];
	Crawler* crawler[E1MAX];
	Bullet* fireball;
	Shockgate* shockgate;
	FFreeze* fFreeze;
	Vacuum* vacuum;
	SpellManager* spellManager;
	static float timer = 0;
	int Crawler::ID = 0;
	int Enemy1::ID = 0;

	
	Mainframe::Mainframe() {
		_winWidth = 800;
		_winHeight = 450;
		_floor = { 0.0f,static_cast<float>(_winHeight),static_cast<float>(_winWidth),10.0f };
		_Espawn = true;
	}
	Mainframe::~Mainframe() {

	}

	void Mainframe::initProgram() {
		InitWindow(_winWidth, _winHeight, "Spellslinger");
		InitAudioDevice();
		SetTargetFPS(60);

	}

	void Mainframe::runProgram() {
		player = new Player();
		for (int i = 0; i < E1MAX; i++) {
			flyer[i] = NULL;
			flyer[i] = new Enemy1;
			crawler[i] = NULL;
			crawler[i] = new Crawler();
		}
		spellManager = new SpellManager;
		spellManager->initializeButtons();
		_gameBool = true;
		TextureManager::loadTextures();
		SoundManager::loadSounds();
		SetMusicVolume(SoundManager::getMainTheme(), 0.12);

		int fireball_frameCounter = 0;
		Color ballColor = RED;
		bool FFreezeBool = false;
		bool vacuumBool = false;
		bool shockBool = false;

		while (_gameBool) {
			HideCursor();
			fireball_frameCounter++;
			BeginDrawing();
			ClearBackground(BLACK);
			DrawTexture(TextureManager::getBackground(), 0, 0, WHITE);
			DrawRectangleRec(_floor, RED);
			DrawRectangle(player->getRec().x + 5, player->getRec().y - 15, 15, 10, spellManager->getColor());
			player->draw();
			DrawTexture(TextureManager::getBrick(), player->getRec().x - 20, player->getRec().y + 20, WHITE);	
			DrawCircleLines(GetMouseX(), GetMouseY(), 15, ballColor);
			DrawText(FormatText("v 0.3"), GetScreenWidth() - 50, 1, 20, { 255,255,255,100 });
			if (!IsMusicPlaying(SoundManager::getMainTheme()))
				PlayMusicStream(SoundManager::getMainTheme());
			UpdateMusicStream(SoundManager::getMainTheme());
			enemyManager();

			for (int i = 0; i < E1MAX; i++) {
				if (flyer[i] != NULL && flyer[i]->getActive()) {
					if (!FFreezeBool) {
						flyer[i]->movement();
					}
					flyer[i]->draw();
				}
			}

			for (int i = 0; i < E1MAX; i++) {
				if (crawler[i] != NULL && crawler[i]->getActive()) {
					if (!FFreezeBool) {
						crawler[i]->movement();
					}
					crawler[i]->draw();
				}
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

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellManager->getSelected() == 3) {
				FFreezeBool = true;
				fFreeze = new FFreeze;
			}
			if (FFreezeBool) {
				DrawTexture(TextureManager::getFFreeze(), GetMouseX()-20, GetMouseY()-18, WHITE); //ESTO SE PUEDE CAMBIAR, NO SE COMO GRAFICAR EL FFREEZE
				timer += 1 * GetFrameTime();
				if (timer >= 2.0f) {
					FFreezeBool = false;
					timer = 0;
				}
			}

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellManager->getSelected() == 4) {
				vacuum = new Vacuum;
				vacuum->setTarget(Vector2{ static_cast<float>(GetMouseX()),static_cast<float>(GetMouseY()) });
				vacuum->vecBullet();
				vacuum->setTrigger(true);
				vacuumBool = true;
			}

			if (vacuumBool) {
				if ((vacuum->getPos().x >= vacuum->getTarget().x)) {
					vacuum->effect();
					vacuum->increaseTimer(0.05);
					vacuum->setTrigger(false);
					for (int i = 0; i < E1MAX; i++) {
						if (flyer[i] != NULL && CheckCollisionCircles(vacuum->getPos(), vacuum->getAoe(), flyer[i]->getPos(), 10)) {
							flyer[i]->setSpeed(0, 0);
							flyer[i]->moveToPoint(vacuum->getPos());
						}
						if (crawler[i] != NULL && CheckCollisionCircles(vacuum->getPos(), vacuum->getAoe(), crawler[i]->getPos(), 10)) {
							crawler[i]->setSpeed(0, 0);
							crawler[i]->moveToPoint(vacuum->getPos());							
						}
					}
				}
			}

			if (fireball != NULL) {
				int fireball_currentFrame = 0;
				if (fireball->getActive()) {
					fireball->moveBullet();
					DrawCircleV({ fireball->getPos().x, fireball->getPos().y }, fireball->getHitbox(), RED);
					if (fireball->getPos().x > _winWidth || fireball->getPos().x < 0 || fireball->getPos().y > _winHeight || fireball->getPos().y < 0) {
						fireball->setActive(false);
						delete fireball;
						fireball = NULL;
					}

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

			for (int i = 0; i < E1MAX; i++){
				if (shockgate != NULL) {

					if (flyer[i] != NULL && shockgate->hitboxCheckFlyers(flyer[i]->getPos())) {
						flyer[i]->setShocked(true);
					}

					if (crawler[i] != NULL && shockgate->hitboxCheckFlyers(crawler[i]->getPos())) {
						crawler[i]->setShocked(true);
					}

					if (flyer[i] != NULL) {
						if (flyer[i]->getShocked()) {
							flyer[i]->increaseTimer(0.05);
							if (flyer[i]->getTimer() > 15.0) {
								flyer[i]->setShocked(false);
							}
						}
					}

					if (crawler[i] != NULL) {
						if (crawler[i]->getShocked()) {
							crawler[i]->increaseTimer(0.05);
							if (crawler[i]->getTimer() > 15.0) {
								crawler[i]->setShocked(false);
							}
						}
					}
				}		
			}

			for (int i = 0; i < E1MAX; i++) {
				if (fireball != NULL && flyer[i] != NULL) {
					if (CheckCollisionCircles(flyer[i]->getPos(), 20, fireball->getPos(), fireball->getHitbox())) {
							delete fireball;
							fireball = NULL;
							delete flyer[i];
							flyer[i] = NULL;
					}
				}
					
			}
			for (int i = 0; i < E1MAX; i++) {
				if (fireball != NULL && crawler[i] != NULL) {
					if (CheckCollisionCircles(crawler[i]->getPos(), 20, fireball->getPos(), fireball->getHitbox())) {
						delete fireball;
						fireball = NULL;
						delete crawler[i];
						crawler[i] = NULL;
					}
				}
			}

			if (IsKeyReleased(KEY_P)) {
				ShowCursor();
				if (pauseScene() == 1)
					setGameBool(false);	
			}
			for (int i = 0; i < E1MAX; i++){
				if (flyer[i]!=NULL)
					if (flyer[i]->getPos().x<0){
						flyer[i]->setActive(false);
						
					}
				if (crawler[i] != NULL)
					if (crawler[i]->getPos().x < 0) {
						crawler[i]->setActive(false);
					}
			}

		}
	
	}

	void Mainframe::setGameBool(bool result) {
		_gameBool = result;
	}


	float EMTimer = 0;
	int EMCounter = 0;
	void Mainframe::enemyManager() {
		EMTimer += GetFrameTime();
		if (EMTimer > 5.0f&&_Espawn) {
			for (int i = 0; i < 3; i++) {
				crawler[EMCounter]->setActive(true);
				flyer[EMCounter]->setActive(true);
				EMCounter++;
				if (i == 2)
					EMTimer = 0;
				if (EMCounter >= 40) {
					_Espawn = false;
				}
			}
		}
		
	}
}








