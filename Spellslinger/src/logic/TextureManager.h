#pragma once
#include "raylib.h"

namespace sSlinger {
	class TextureManager {
	private:
		static Texture2D _ghostSprite;
		static Texture2D _crawlerSprite;
		static Texture2D _playerSprite;
		static Texture2D _background;
		static Texture2D _brick;
	public:
		static void loadTextures();
		static void unloadTextures();
		static Texture2D getGhostSprite();
		static Texture2D getCrawlerSprite();
		static Texture2D getPlayerSprite();
		static Texture2D getBackground();
		static Texture2D getBrick();
	};
}
	
