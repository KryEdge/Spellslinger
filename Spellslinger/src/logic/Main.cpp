#include "objects/mainframe/Mainframe.h"
void main() {
	Mainframe* spellslinger = new Mainframe;
	spellslinger->initProgram();
	delete spellslinger;
}