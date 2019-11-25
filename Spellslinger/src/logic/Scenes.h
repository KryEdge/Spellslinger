#pragma once
#include "raylib.h"
#include "MagicNumbers.h"
#include "logic/SoundManager.h"
#include <iostream>
using namespace std;

enum Scenes {
	menu,
	gameplay,
	credits,
	pause,
};
extern Scenes scenes;

void menuScene();
void creditScene();
int pauseScene();
