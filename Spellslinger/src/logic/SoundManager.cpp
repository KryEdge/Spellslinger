#include "logic/SoundManager.h"
#include "raylib.h"

namespace sSlinger {

	Music SoundManager::_mainTheme = Music();

	void SoundManager::loadSounds() {
		_mainTheme = LoadMusicStream("../res/Assets/Berserk.ogg");
	}

	void SoundManager::unloadSounds() {
		UnloadMusicStream(_mainTheme);
	}

	Music SoundManager::getMainTheme() {
		return _mainTheme;
	}

}