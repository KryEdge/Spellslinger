#include "Scenes.h"
#include "objects/mainframe/Mainframe.h"

Scenes scenes;

void menuScene() {
	bool menuBool = true;

	Rectangle playButton;
	playButton.x = menuPlayTextX;
	playButton.y = menuPlayTextY;
	playButton.height = 30;
	playButton.width = 65;
	Rectangle closeButton;
	closeButton.x = menuPlayTextX;
	closeButton.y = menuPlayTextY + 50;
	closeButton.height = 30;
	closeButton.width = 81.25f;
	Rectangle creditsButton;
	creditsButton.x = menuPlayTextX;
	creditsButton.y = menuPlayTextY + 100;
	creditsButton.height = 30;
	creditsButton.width = 113;


	while (menuBool) {
		BeginDrawing();
		ClearBackground(BLACK);

		DrawText(FormatText("Spellslinger"), titlePosX, titlePosY, titleFontSize, WHITE);
		if (CheckCollisionPointRec(GetMousePosition(), playButton))
			DrawText(FormatText("Play"), menuPlayTextX, menuPlayTextY, promptFontSize, RED);
		else
			DrawText(FormatText("Play"), menuPlayTextX, menuPlayTextY, promptFontSize, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), closeButton))
			DrawText(FormatText("Close"), menuPlayTextX, menuPlayTextY + 50, promptFontSize, RED);
		else
			DrawText(FormatText("Close"), menuPlayTextX, menuPlayTextY + 50, promptFontSize, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), creditsButton))
			DrawText(FormatText("Credits"), menuPlayTextX, menuPlayTextY + 100, promptFontSize, RED);
		else
			DrawText(FormatText("Credits"), menuPlayTextX, menuPlayTextY + 100, promptFontSize, WHITE);

		DrawText(FormatText("v 0.1"), GetScreenWidth() - 50, 1, 20, WHITE);

		EndDrawing();

		if (CheckCollisionPointRec(GetMousePosition(), playButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			menuBool = false;
			scenes = gameplay;
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
	creditsButton.x = screenWidth / 2 - 40;
	creditsButton.y = menuPlayTextY + 160;
	creditsButton.height = 30;
	creditsButton.width = 113;

	while (creditBool) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText(FormatText("Gradius probs"), titlePosX, titlePosY, titleFontSize, WHITE);
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
