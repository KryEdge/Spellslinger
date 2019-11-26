#pragma once
#include "raylib.h"

namespace sSlinger {
	class SoundManager {
	private:
		static Music _mainTheme;

		static Sound _ghostSfx;
		static Sound _fireballSfx;
		static Sound _freezeSfx;
		static Sound _vacuumSfx;
		static Sound _shockgateSfx;
		static Sound _deathSfx;

	public:
		static void loadSounds();
		static void unloadSounds();
		static Music getMainTheme();
		static Sound getGhostSfx();
		static Sound getFireballSfx();
		static Sound getFreezeSfx();
		static Sound getVacuumSfx();
		static Sound getDeathSfx();
		static Sound getShockgateSfx();
	};
}

