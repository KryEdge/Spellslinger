#include "logic/TextureManager.h"
#include "raylib.h"

namespace sSlinger {

	Texture2D TextureManager::_ghostSprite = Texture2D();	
	Texture2D TextureManager::_crawlerSprite = Texture2D();	
	Texture2D TextureManager::_playerSprite = Texture2D();	
	Texture2D TextureManager::_background = Texture2D();
	Texture2D TextureManager::_brick = Texture2D();
	Texture2D TextureManager::_flashFreeze = Texture2D();

	void TextureManager::loadTextures() {
		_ghostSprite = LoadTexture("Assets/Flyer_Float.png");
		_ghostSprite.height *= 2.2;
		_ghostSprite.width *= 2.2;
		_crawlerSprite = LoadTexture("Assets/Crawler_Crawl.png");
		_crawlerSprite.height *= 2.2;
		_crawlerSprite.width *= 2.2;
		_playerSprite = LoadTexture("Assets/mage-1.png");
		_playerSprite.height /= 5;
		_playerSprite.width /= 5;
		_background = LoadTexture("Assets/background.png");
		_brick = LoadTexture("Assets/brick.png");
		_flashFreeze = LoadTexture("Assets/freeze.png");
	}

	void TextureManager::unloadTextures() {
		UnloadTexture(_ghostSprite);
		UnloadTexture(_crawlerSprite);
		UnloadTexture(_playerSprite);
		UnloadTexture(_background);
		UnloadTexture(_brick);
		UnloadTexture(_flashFreeze);
	}

	Texture2D TextureManager::getGhostSprite() {
		return _ghostSprite;
	}	
	
	Texture2D TextureManager::getCrawlerSprite() {
		return _crawlerSprite;
	}

	Texture2D TextureManager::getPlayerSprite() {
		return _playerSprite;
	}

	Texture2D TextureManager::getBackground() {
		return _background;
	}	
	
	Texture2D TextureManager::getBrick() {
		return _brick;
	}	
	
	Texture2D TextureManager::getFFreeze() {
		return _flashFreeze;
	}
	
}