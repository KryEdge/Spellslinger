#include "raylib.h"
#include "logic/Spellmanager.h"

namespace sSlinger{
	Color mouseColor = BLUE;
	Vector2 spellButton[4];
	Rectangle selectedSpell{10,10,50,50};
	Vector2 buttonSize{ 50,50 };

	void initializeButtons() {
		for (int i = 0; i < 4; i++)
		{
			if (i == 0) {
				spellButton[i].x = 10;
			}
			else {
				spellButton[i].x = spellButton[i - 1].x + 70;
			}
			spellButton[i].y = 10;
		}
	}


	void spellmanager() {
		initializeButtons();
		DrawCircleLines(GetMouseX(), GetMouseY(), 15, mouseColor);
		for (int i = 0; i < 4; i++)
		{
			DrawRectangleV(spellButton[0], buttonSize, WHITE);
			DrawRectangleV(spellButton[1], buttonSize, WHITE);
			DrawRectangleV(spellButton[2], buttonSize, WHITE);
			DrawRectangleV(spellButton[3], buttonSize, WHITE);

			DrawRectangleLinesEx(selectedSpell, 10, mouseColor);
		}
		if (IsKeyPressed(KEY_Q) || IsKeyPressed(KEY_ONE)) {
			mouseColor = RED;
			selectedSpell.x = 10;
		}		
		if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_TWO)) {
			mouseColor = YELLOW;
			selectedSpell.x = 80;
		}		
		if (IsKeyPressed(KEY_E) || IsKeyPressed(KEY_THREE)) {
			mouseColor = SKYBLUE;
			selectedSpell.x = 150;
		}		
		if (IsKeyPressed(KEY_R) || IsKeyPressed(KEY_FOUR)) {
			mouseColor = LIGHTGRAY;
			selectedSpell.x = 220;
		}
	}

	
}