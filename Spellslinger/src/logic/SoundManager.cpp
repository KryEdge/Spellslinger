#include "logic/SoundManager.h"
#include "raylib.h"

namespace sSlinger {

	Music SoundManager::_mainTheme = Music();

	Sound SoundManager::_ghostSfx = Sound();
	Sound SoundManager::_fireballSfx = Sound();
	Sound SoundManager::_freezeSfx = Sound();
	Sound SoundManager::_shockgateSfx = Sound();
	Sound SoundManager::_deathSfx = Sound();
	Sound SoundManager::_vacuumSfx = Sound();

	void SoundManager::loadSounds() {
		_mainTheme = LoadMusicStream("../res/Assets/Berserk.ogg");
		_fireballSfx = LoadSound("../res/Assets/sfx/fireball.wav");
		_vacuumSfx = LoadSound("../res/Assets/sfx/vacuum.wav");
		_ghostSfx = LoadSound("../res/Assets/sfx/ghost1.wav");
		SetSoundVolume(_ghostSfx, 0.2);
		_deathSfx = LoadSound("../res/Assets/sfx/death.ogg");
		_shockgateSfx = LoadSound("../res/Assets/sfx/shockgate.ogg");
		_freezeSfx = LoadSound("../res/Assets/sfx/freeze.ogg");
	}

	void SoundManager::unloadSounds() {
		UnloadMusicStream(_mainTheme);
		UnloadSound(_fireballSfx);
		UnloadSound(_shockgateSfx);
		UnloadSound(_freezeSfx);
		UnloadSound(_ghostSfx);
		UnloadSound(_deathSfx);
		UnloadSound(_vacuumSfx);
	}

	Music SoundManager::getMainTheme() {
		return _mainTheme;
	}

	Sound SoundManager::getGhostSfx() {
		return _ghostSfx;
	}
	Sound SoundManager::getFireballSfx() {
		return _fireballSfx;
	}
	Sound SoundManager::getFreezeSfx() {
		return _freezeSfx;
	}
	Sound SoundManager::getVacuumSfx() {
		return _vacuumSfx;
	}
	Sound SoundManager::getDeathSfx() {
		return _deathSfx;
	}
	Sound SoundManager::getShockgateSfx() {
		return _shockgateSfx;
	}
}