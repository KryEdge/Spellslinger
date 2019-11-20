#pragma once


namespace sSlinger {
	class TextureManager {
	private:
		Texture2D _ghostSprite;
		Texture2D _playerSprite;
		Texture2D _background;

	public:
		void loadTextures();
	};
}
	
