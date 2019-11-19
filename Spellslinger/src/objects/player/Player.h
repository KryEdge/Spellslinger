#include "raylib.h"

namespace sSlinger {
	class Player {
	private:
		Color _color;
		Rectangle _rec;
		int _lives;
		Texture2D _sprite;
	public:
		Player();
		~Player();
		Rectangle getRec();
		void draw();
	};


}
