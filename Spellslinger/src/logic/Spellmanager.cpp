#include "raylib.h"
#include "logic/Spellmanager.h"

namespace sSlinger{
	SpellManager::SpellManager() {
		_mouseColor = RED;
		_spellButton[4];
		_selectedSpell = { 10,10,30,30 };
		_buttonSize = { 30,30 };
		_elementSelected = 1;
	}
	void SpellManager::initializeButtons() {
		for (int i = 0; i < 4; i++)
		{
			if (i == 0) {
				_spellButton[i].x = 10;
			}
			else {
				_spellButton[i].x = _spellButton[i - 1].x + 40;
			}
			_spellButton[i].y = 10;
		}
	}
	int SpellManager::getSelected() {
		return _elementSelected;
	}
	void SpellManager::setSelected(int selected) {
		_elementSelected = selected;
	}

	void SpellManager::spellmanager() {
		DrawCircleLines(GetMouseX(), GetMouseY(), 15, _mouseColor);
		for (int i = 0; i < 4; i++){
			DrawRectangleV(_spellButton[0], _buttonSize, WHITE);
			DrawRectangleV(_spellButton[1], _buttonSize, WHITE);
			DrawRectangleV(_spellButton[2], _buttonSize, WHITE);
			DrawRectangleV(_spellButton[3], _buttonSize, WHITE);
			DrawRectangleLinesEx(_selectedSpell, 5, _mouseColor);
		}

		if (IsKeyPressed(KEY_Q) || IsKeyPressed(KEY_ONE)) {
			_mouseColor = RED;
			_selectedSpell.x = 10;
			_elementSelected = 1;
		}		
		if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_TWO)) {
			_mouseColor = YELLOW;
			_selectedSpell.x = 50;
			_elementSelected = 2;
		}		
		if (IsKeyPressed(KEY_E) || IsKeyPressed(KEY_THREE)) {
			_mouseColor = SKYBLUE;
			_selectedSpell.x = 90;
			_elementSelected = 3;
		}	
		if (IsKeyPressed(KEY_R) || IsKeyPressed(KEY_FOUR)) {
			_mouseColor = LIGHTGRAY;
			_selectedSpell.x = 130;
			_elementSelected = 4;
		}
	}

	
}