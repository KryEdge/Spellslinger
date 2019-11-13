#include "Player.h"
#include "raylib.h"

namespace sSlinger {
	Player::Player(){
		_rec.height = 20.0f;
		_rec.width = 20.0f;
		_rec.x = 20.0f;
		_rec.y = 430.0f;
	}
	Player::~Player(){

	}
	Rectangle Player::getRec() {
		return _rec;
	}
}
	