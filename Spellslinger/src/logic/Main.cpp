#include "objects/mainframe/Mainframe.h"

using namespace sSlinger;

void main() {
	Mainframe* spellslinger = new Mainframe;
	spellslinger->initProgram();
	delete spellslinger;
}