#include "objects/enemies/Crawler.h"

namespace sSlinger {
	Crawler::Crawler() {
		_winWidth = 810;
		_winHeight = 450;
		_pos.x = GetRandomValue(830, 1100);
		_pos.y = 440;
		_life = 50;
		_speedY = 100.0f;
		_speedX = 100.0f;
		_timer = 0.0f;
		_shocked = false;
		_frozen = false;
		_startPoint = _pos.y;
		_active = false;
		_ID = ID;
		ID++;
	}
	Crawler::~Crawler() {
		ID--;
	}

	void Crawler::setLife(int life) {
		_life = life;
	}
	Vector2 Crawler::getPos() {
		return _pos;
	}
	void Crawler::movement() {
		if (!_shocked) { _speedY = 100.0; _speedX = 100.0; }
		else { _speedY = 50.0; _speedX = 50.0; };
		if (!_frozen) {
			_pos.x -= _speedX * GetFrameTime();
			if (_pos.y < 440) {
				_pos.y += _speedY * GetFrameTime();
			}
		}
	}
	void Crawler::setSpeed(int x, int y) {
		_speedX = x;
		_speedY = y;
	}
	float Crawler::getSpeedX() {
		return _speedX;
	}

	float Crawler::getSpeedY() {
		return _speedY;
	}

	void Crawler::moveToPoint(Vector2 Point) {
		if (_pos.x != Point.x) {
			if (Point.x > _pos.x)
				_pos.x += 2.5;
			else
				_pos.x -= 2.5;
		}
		if (_pos.y != Point.y) {
			if (Point.y > _pos.y)
				_pos.y += 2.5;
			else
				_pos.y -= 2.5;
		}
	}
	float Crawler::getTimer() {
		return _timer;
	}
	void Crawler::increaseTimer(float increase) {
		_timer += increase;
	}
	bool Crawler::getShocked() {
		return _shocked;
	}
	void Crawler::setShocked(bool set) {
		_shocked = set;
	}
	void Crawler::setFrozen(bool set) {
		_frozen = set;
	}
	void Crawler::setActive(bool active) {
		_active = active;
	}
	bool Crawler::getActive() {
		return _active;
	}
	void Crawler::draw() {
		DrawTexture(TextureManager::getCrawlerSprite(), _pos.x - TextureManager::getCrawlerSprite().width / 2, _pos.y - TextureManager::getCrawlerSprite().height / 2, WHITE);
	}
}
