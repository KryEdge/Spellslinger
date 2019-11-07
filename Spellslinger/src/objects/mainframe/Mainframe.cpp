#include "objects/mainframe/Mainframe.h"
#include "raylib.h"
using namespace sSlinger;

	
	Mainframe::Mainframe() {
		_winWidth = 800;
		_winHeight = 450;

	}
	Mainframe::~Mainframe() {

	}

	void Mainframe::initProgram() {
		InitWindow(_winWidth, _winHeight, "Spellslinger");
		SetTargetFPS(60);

		Color ballColor = DARKBLUE;
		SetTargetFPS(60);



		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(BLACK);
			DrawCircleLines(GetMouseX(), GetMouseY(), 15, ballColor);
			EndDrawing();
		}
		CloseWindow();
	}

