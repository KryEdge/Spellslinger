#include "Player.h"
#include "raylib.h"

namespace sSlinger {
	Player::Player(){
		_rec.height = 20.0f;
		_rec.width = 20.0f;
		_rec.x = 20.0f;
		_rec.y = 330.0f;
		_lives = 8;
	}
	Player::~Player(){

	}
	Rectangle Player::getRec() {
		return _rec;
	}
	void Player::draw() {
		int pos1 = 10;
		DrawTexture(TextureManager::getPlayerSprite(), _rec.x - TextureManager::getPlayerSprite().width / 3, _rec.y - TextureManager::getPlayerSprite().height / 1.66, WHITE);
		for (int i = 0; i < _lives; i++)
		{
			DrawRectangle(((pos1+10)*i)+10, 50, 10, 20, GREEN);
		}

		if (_lives == 0) {
			if (!IsSoundPlaying(SoundManager::getDeathSfx())) PlaySound(SoundManager::getDeathSfx());
		}
	}
}
	