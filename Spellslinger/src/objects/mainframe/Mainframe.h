#ifndef MAINFRAME_H
#define MAINFRAME_H
#define E1MAX 50
#include "raylib.h"
#include "objects/player/Player.h"
#include "objects/enemy1/Enemy1.h"
#include "objects/spells/bullet/Bullet.h"
#include "logic/Spellmanager.h"
#include "objects/spells/FFreeze/FFreeze.h"
#include "objects/spells/Vacuum.h"


namespace sSlinger {


	class Mainframe {
	private:
		int _winWidth;
		int _winHeight;
	public:
		Mainframe();
		~Mainframe();
		void initProgram();
		void runProgram();
	};

	extern Player* player;
	extern Bullet* fireball;
	extern FFreeze* fFreeze;
	extern Vacuum* vacuum;
	extern Enemy1* flyer[E1MAX];
}
	
#endif
