#include "raylib.h"

namespace sSlinger {
	class Player {
	private:
		Color _color;
		Rectangle _rec;
		int _lives;
	public:
		Player();
		~Player();
		Rectangle getRec();

	};


}
