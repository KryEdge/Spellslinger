#pragma once

namespace sSlinger {

	class SpellManager {
	private:
		int _elementSelected;
		Color _mouseColor;
		float _crosshairSize;
		Vector2 _spellButton[4];
		Rectangle _selectedSpell;
		Vector2 _buttonSize;

	public:
		SpellManager();
		void initializeButtons();
		void spellmanager();
		int getSelected();
		void setSelected(int selected);
		
	};
}