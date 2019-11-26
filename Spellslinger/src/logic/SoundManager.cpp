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
		_mainTheme = LoadMusicStream("Assets/Berserk.ogg");
		_ghostSfx = LoadSound("Assets/sfx/ghost1.wav");
		SetSoundVolume(_ghostSfx, 0.2);
		_fireballSfx = LoadSound("Assets/sfx/fireball.wav");
		_freezeSfx = LoadSound("Assets/sfx/freeze.ogg");
		_shockgateSfx = LoadSound("Assets/sfx/shockgate.ogg");
		_deathSfx = LoadSound("Assets/sfx/death.ogg");
		_vacuumSfx = LoadSound("Assets/sfx/vacuum.wav");
	}

	void SoundManager::unloadSounds() {
		UnloadMusicStream(_mainTheme);
		UnloadSound(_ghostSfx);
		UnloadSound(_fireballSfx);
		UnloadSound(_freezeSfx);
		UnloadSound(_shockgateSfx);
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