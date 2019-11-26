#include "objects/mainframe/Mainframe.h"
#include "logic/Scenes.h"
using namespace sSlinger;

void main() {
	Mainframe* spellslinger = new Mainframe;
	scenes = menu;
	spellslinger->initProgram();

	while (!WindowShouldClose()) {
		switch (scenes) {
		case menu:
			menuScene();
			break;
		case gameplay:
			spellslinger->runProgram();
			break;
		case credits:
			creditScene();
			break;
		}
	}
	CloseAudioDevice();
	CloseWindow();

}