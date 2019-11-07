#include "objects/mainframe/Mainframe.h"
#include "raylib.h"
#include "objects/player/Player.h"
#include "objects/shooting/Shooting.h"

namespace sSlinger {
	Mainframe::Mainframe() {
		_winWidth = 800;
		_winHeight = 450;

	}
	Mainframe::~Mainframe() {

	}
	int temp1 = 20;
	int temp2 = 430;
	bool shot = true;	
	Vector2 bullet{ 20,430 };
	Player jojo;

	void Mainframe::initProgram() {
		InitWindow(_winWidth, _winHeight, "Spellslinger");
		SetTargetFPS(60);
		Color ballColor = DARKBLUE;
		SetTargetFPS(60);

		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(BLACK);
			DrawRectangleRec(jojo._rec, ballColor); 
			DrawCircleLines(GetMouseX(), GetMouseY(), 15, ballColor);

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				shoot(bullet);//ME TIRA UN ERROR RARISIMO DE "DEMASIADOS ARGUMENTOS". ME ESTOY VOLVIENDO LOCO
				shot = true;
			}
				
			if (shot) {

				DrawCircleV(bullet, 5, RED);
			}

			EndDrawing();
		}
		CloseWindow();
	}


}
	