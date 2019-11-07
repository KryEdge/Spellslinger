#ifndef MAINFRAME_H
#define MAINFRAME_H
#include "raylib.h"

	class Mainframe {
		int _winWidth;
		int _winHeight;
	public:
		Mainframe();
		~Mainframe();
		void initProgram();
	};

#endif
