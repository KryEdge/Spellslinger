#include "Player.h"
#include "raylib.h"

namespace sSlinger {
	Player::Player(){
		_rec.height = 20.0f;
		_rec.width = 20.0f;
		_rec.x = 20.0f;
		_rec.y = 330.0f;
		_sprite = LoadTexture("../res/Assets/mage-1.png");
		_sprite.height /= 5;
		_sprite.width /= 5;
		_lives = 8;
	}
	Player::~Player(){
		UnloadTexture(_sprite);
	}
	Rectangle Player::getRec() {
		return _rec;
	}
	void Player::draw() {
		int pos1 = 10;
		DrawTexture(_sprite, _rec.x - _sprite.width / 3, _rec.y - _sprite.height / 1.66, WHITE);
		for (int i = 0; i < _lives; i++)
		{
			DrawRectangle(((pos1+10)*i)+10, 50, 10, 20, GREEN);
		}
	}
}
	