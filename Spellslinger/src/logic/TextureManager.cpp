#include "logic/TextureManager.h"
#include "raylib.h"

namespace sSlinger {

	Texture2D TextureManager::_ghostSprite = Texture2D();	
	Texture2D TextureManager::_playerSprite = Texture2D();	
	Texture2D TextureManager::_background = Texture2D();

	void TextureManager::loadTextures() {
		_ghostSprite = LoadTexture("../res/Assets/Flyer_Float.png");
		_playerSprite = LoadTexture("../res/Assets/mage-1.png");
		_background = LoadTexture("../res/Assets/background.png");
	}

	void TextureManager::unloadTextures() {
		UnloadTexture(_ghostSprite);
		UnloadTexture(_playerSprite);
		UnloadTexture(_background);
	}
	Texture2D TextureManager::getGhostSprite() {
		_ghostSprite.height *= 2.2;
		_ghostSprite.width *= 2.2;
		return _ghostSprite;
	}
	Texture2D TextureManager::getPlayerSprite() {
		_playerSprite.height /= 5;
		_playerSprite.width /= 5;
		return _playerSprite;
	}
	Texture2D TextureManager::getBackground() {
		return _background;
	}
}