#include "Scenes.h"
#include "objects/mainframe/Mainframe.h"

Scenes scenes;

void controlsScene() {

	Rectangle _rec1;
	_rec1.height = 30;
	_rec1.width = 30;
	_rec1.x = GetScreenWidth() / 3 + 40;
	_rec1.y = menuPlayTextY - 50;
	Rectangle _rec2;
	_rec2.height = 30;
	_rec2.width = 30;
	_rec2.x = GetScreenWidth() / 3 + 80;
	_rec2.y = menuPlayTextY - 50;
	Rectangle _rec3;
	_rec3.height = 30;
	_rec3.width = 30;
	_rec3.x = GetScreenWidth() / 3 + 120;
	_rec3.y = menuPlayTextY - 50;
	Rectangle _rec4;
	_rec4.height = 30;
	_rec4.width = 30;
	_rec4.x = GetScreenWidth() / 3 + 160;
	_rec4.y = menuPlayTextY - 50;

	DrawRectangleRec(_rec1, WHITE);
	DrawRectangleLinesEx(_rec1, 5, RED);
	DrawRectangleRec(_rec2, WHITE);
	DrawRectangleLinesEx(_rec2, 5, YELLOW);
	DrawRectangleRec(_rec3, WHITE);
	DrawRectangleLinesEx(_rec3, 5, SKYBLUE);
	DrawRectangleRec(_rec4, WHITE);
	DrawRectangleLinesEx(_rec4, 5, LIGHTGRAY);
	DrawText(FormatText("Q"), GetScreenWidth()/3+ 40, menuPlayTextY, promptFontSize, WHITE);
	DrawText(FormatText("W"), GetScreenWidth()/3+ 80, menuPlayTextY, promptFontSize, WHITE);
	DrawText(FormatText("R"), GetScreenWidth()/3+ 160, menuPlayTextY, promptFontSize, WHITE);
	DrawText(FormatText("E"), GetScreenWidth()/3+ 120, menuPlayTextY, promptFontSize, WHITE);

	DrawText(FormatText("Left Mouse to shoot your spell"), GetScreenWidth() / 3 + 40, menuPlayTextY+60, promptFontSize-5, WHITE);
	DrawText(FormatText("Don't let the enemies reach the castle"), GetScreenWidth() / 3 + 40, menuPlayTextY + 100, promptFontSize - 5, WHITE);

}
void menuScene() {
	bool menuBool = true;
	bool controlsBool = false;

	Rectangle playButton;
	playButton.x = menuPlayTextX;
	playButton.y = menuPlayTextY;
	playButton.height = 30;
	playButton.width = 65;
	Rectangle controlsButton;
	controlsButton.x = menuPlayTextX;
	controlsButton.y = menuPlayTextY + 50;
	controlsButton.height = 30;
	controlsButton.width = 113;
	Rectangle creditsButton;
	creditsButton.x = menuPlayTextX;
	creditsButton.y = menuPlayTextY + 100;
	creditsButton.height = 30;
	creditsButton.width = 113;
	Rectangle closeButton;
	closeButton.x = menuPlayTextX;
	closeButton.y = menuPlayTextY + 150;
	closeButton.height = 30;
	closeButton.width = 81.25f;
	Texture2D logo = LoadTexture("../res/Assets/logo.png");

	while (menuBool) {
		BeginDrawing();
		ClearBackground(BLACK);

		DrawTexture(logo, titlePosX, titlePosY, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), playButton))
			DrawText(FormatText("Play"), menuPlayTextX, menuPlayTextY, promptFontSize, RED);
		else
			DrawText(FormatText("Play"), menuPlayTextX, menuPlayTextY, promptFontSize, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), controlsButton))
			DrawText(FormatText("Controls"), menuPlayTextX, menuPlayTextY + 50, promptFontSize, RED);
		else
			DrawText(FormatText("Controls"), menuPlayTextX, menuPlayTextY + 50, promptFontSize, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), creditsButton))
			DrawText(FormatText("Credits"), menuPlayTextX, menuPlayTextY + 100, promptFontSize, RED);
		else
			DrawText(FormatText("Credits"), menuPlayTextX, menuPlayTextY + 100, promptFontSize, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), closeButton))
			DrawText(FormatText("Close"), menuPlayTextX, menuPlayTextY + 150, promptFontSize, RED);
		else
			DrawText(FormatText("Close"), menuPlayTextX, menuPlayTextY + 150, promptFontSize, WHITE);

		if(controlsBool)
			controlsScene();

		DrawText(FormatText("v 0.3"), GetScreenWidth() - 50, 1, 20, WHITE);

		EndDrawing();

		if (CheckCollisionPointRec(GetMousePosition(), playButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			menuBool = false;
			scenes = gameplay;
		}
		if (CheckCollisionPointRec(GetMousePosition(), controlsButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			if (!controlsBool)
				controlsBool = true;
			else
				controlsBool = false;
		}

		if (CheckCollisionPointRec(GetMousePosition(), closeButton) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			exit(0);
		}
		if (CheckCollisionPointRec(GetMousePosition(), creditsButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			menuBool = false;
			scenes = credits;
		}
	}
}

void creditScene() {
	bool creditBool = true;

	Rectangle creditsButton;
	creditsButton.x = menuPlayTextX;
	creditsButton.y = menuPlayTextY + 160;
	creditsButton.height = 30;
	creditsButton.width = 113;

	while (creditBool) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText(FormatText("Spellslinger"), titlePosX, titlePosY, titleFontSize, WHITE);
		//DrawText(FormatText("Lead Programmer"), creditsTitle1X, creditsTitle1Y, 30, WHITE);
		//DrawText(FormatText("Matias Karplus"), creditsSub1X, creditsSub1Y, 20, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), creditsButton))
			DrawText(FormatText("Credits"), menuPlayTextX, menuPlayTextY + 160, promptFontSize, RED);
		else
			DrawText(FormatText("Credits"), menuPlayTextX, menuPlayTextY + 160, promptFontSize, WHITE);
		EndDrawing();



		if (CheckCollisionPointRec(GetMousePosition(), creditsButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			creditBool = false;
			scenes = menu;
		}

		if (IsKeyPressed(KEY_BACKSPACE)) {
			exit(0);
		}
	}
}
int pauseScene() {
	bool pauseBool = true;
	Rectangle resumeButton;
	resumeButton.x = menuPlayTextX;
	resumeButton.y = menuPlayTextY;
	resumeButton.height = 30;
	resumeButton.width = 97.5f;
	Rectangle menuButton;
	menuButton.x = menuPlayTextX;
	menuButton.y = menuPlayTextY + 50;
	menuButton.height = 30;
	menuButton.width = 66.0f;

	while (pauseBool) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText(FormatText("PAUSED"), titlePosX, 1, titleFontSize, WHITE);
		if (CheckCollisionPointRec(GetMousePosition(), resumeButton))
			DrawText(FormatText("Resume"), menuPlayTextX, menuPlayTextY, promptFontSize, RED);
		else
			DrawText(FormatText("Resume"), menuPlayTextX, menuPlayTextY, promptFontSize, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), menuButton))
			DrawText(FormatText("Menu"), menuPlayTextX, menuPlayTextY + 50, promptFontSize, RED);
		else
			DrawText(FormatText("Menu"), menuPlayTextX, menuPlayTextY + 50, promptFontSize, WHITE);
		EndDrawing();

		if (CheckCollisionPointRec(GetMousePosition(), resumeButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			pauseBool = false;
		}
		if (CheckCollisionPointRec(GetMousePosition(), menuButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			pauseBool = false;
			scenes = menu;
			return 1;
		}
	}
}
