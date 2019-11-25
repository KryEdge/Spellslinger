#ifndef MAINFRAME_H
#define MAINFRAME_H
#define E1MAX 50
#include "raylib.h"
#include "objects/player/Player.h"
#include "objects/enemies/Enemy1.h"
#include "objects/enemies/Crawler.h"
#include "objects/spells/bullet/Bullet.h"
#include "logic/Spellmanager.h"
#include "objects/spells/FFreeze/FFreeze.h"
#include "objects/spells/Vacuum.h"
#include "objects/spells/Shockgate.h"
#include "logic/Scenes.h"
#include "logic/TextureManager.h"
#include "logic/SoundManager.h"


namespace sSlinger {
	class Mainframe {
	private:
		int _winWidth;
		int _winHeight;
		bool _gameBool;
		Rectangle _floor;
	public:
		Mainframe();
		~Mainframe();
		void initProgram();
		void runProgram();
		void setGameBool(bool result);
		void enemyManager();
	};

	extern Player* player;
	extern Bullet* fireball;
	extern FFreeze* fFreeze;
	extern Vacuum* vacuum;
	extern Enemy1* flyer[E1MAX];
	extern Crawler* crawler[E1MAX];
}
	
#endif
