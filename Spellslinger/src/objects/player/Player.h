#include "objects/mainframe/Mainframe.h"
#include "raylib.h"

namespace sSlinger {
	class Player {
	public:
		Rectangle _rec;
		Player();
		~Player();

	private:
		Color _color;
		int _lives;
		float _posx;
		float _posy;
	};

}
