#include "Mainframe.h"
#include "raylib.h"

namespace sSlinger {
	class Player {
	public:
		Rectangle _rec;
		Player();
		~Player();
	private:
		Color _color;
		int lives;
		float posx;
		float posy;
	};

}
