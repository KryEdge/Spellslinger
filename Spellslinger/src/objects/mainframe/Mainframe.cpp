#include "objects/mainframe/Mainframe.h"
#include "raylib.h"
#include "objects/player/Player.h"
#include "objects/shooting/Shooting.h"

namespace sSlinger {
	Mainframe::Mainframe() {
		_winWidth = 800;
		_winHeight = 450;

	}
	Mainframe::~Mainframe() {

	}
	int temp1 = 20;
	int temp2 = 430;
	bool shot = false;	
	Vector2 bullet{ 20,430 };
	Player jojo;

	void Mainframe::initProgram() {
		InitWindow(_winWidth, _winHeight, "Spellslinger");
		SetTargetFPS(60);
		Color ballColor = DARKBLUE;
		SetTargetFPS(60);

		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(BLACK);
			DrawRectangleRec(jojo._rec, ballColor); 
			DrawCircleLines(GetMouseX(), GetMouseY(), 15, ballColor);

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				shot = true;
			}
			//NO SE COMO TE SENTIS SOBRE LOS COMENTARIOS EN EL CODIGO PERO ACA VA.
			//ESTUVE CODEANDO Y CREO QUE ESTOY MUY QUEMADO YA PARA SEGUIR AHORA, LA FUNCION DE DISPARO ANDA PERO NO LOGRO PEGAR HACER QUE VIAJE BIEN
			//POR EL LADO POSITIVO SI DISPARAS Y ACERCAS AL MOUSE A LA BALA HACE COSAS RARAS Y ESO PUEDE USARSE EN EL FUTURO
			if (shot) {
				moveBullet(bullet);
				DrawCircleV(bullet, 5, RED);
			}
			if (bullet.x > _winWidth || bullet.x < 0 || bullet.y > _winHeight || bullet.y < 0) {
				shot = false;
				returnBullet(bullet);
			}

			EndDrawing();
		}
		CloseWindow();
	}


}
	