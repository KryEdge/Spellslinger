#pragma once
#include "raylib.h"

namespace sSlinger {
	class SoundManager {
	private:
		static Music _mainTheme;

	public:
		static void loadSounds();
		static void unloadSounds();
		static Music getMainTheme();

	};
}

