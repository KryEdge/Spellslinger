#include "raylib.h"
#include "logic/Spellmanager.h"

namespace sSlinger{
	SpellManager::SpellManager() {
		_mouseColor = RED;
		_spellButton[4];
		_selectedSpell = { 10,10,50,50 };
		_buttonSize = { 50,50 };
		_selected = 1;
	}
	void SpellManager::initializeButtons() {
		for (int i = 0; i < 4; i++)
		{
			if (i == 0) {
				_spellButton[i].x = 10;
			}
			else {
				_spellButton[i].x = _spellButton[i - 1].x + 70;
			}
			_spellButton[i].y = 10;
		}
	}


	void SpellManager::spellmanager() {
		DrawCircleLines(GetMouseX(), GetMouseY(), 15, _mouseColor);
		for (int i = 0; i < 4; i++){
			DrawRectangleV(_spellButton[0], _buttonSize, WHITE);
			DrawRectangleV(_spellButton[1], _buttonSize, WHITE);
			DrawRectangleV(_spellButton[2], _buttonSize, WHITE);
			DrawRectangleV(_spellButton[3], _buttonSize, WHITE);
			DrawRectangleLinesEx(_selectedSpell, 10, _mouseColor);
		}

		if (IsKeyPressed(KEY_Q) || IsKeyPressed(KEY_ONE)) {
			_mouseColor = RED;
			_selectedSpell.x = 10;
			_selected = 1;
		}		
		if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_TWO)) {
			_mouseColor = YELLOW;
			_selectedSpell.x = 80;
			_selected = 2;
		}		
		if (IsKeyPressed(KEY_E) || IsKeyPressed(KEY_THREE)) {
			_mouseColor = SKYBLUE;
			_selectedSpell.x = 150;
			_selected = 3;
		}	
		if (IsKeyPressed(KEY_R) || IsKeyPressed(KEY_FOUR)) {
			_mouseColor = LIGHTGRAY;
			_selectedSpell.x = 220;
			_selected = 4;
		}
	}

	int SpellManager::getSelected() {
		return _selected;
	}
	void SpellManager::setSelected(int selected) {
		_selected = selected;
	}

	
}