#pragma once

#include "Aldea.h"
#include "loseta.h"
#include "glut.h"


class CoordinadorJuego
{
public:
	CoordinadorJuego();
	~CoordinadorJuego();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void raton(int button, int state, int x, int y);
	void mueve();
	void dibuja();
	

protected:
	Vector2D Raton;
	Loseta pantalla;
	Aldea aldea;
	enum Estado { INICIO, INSTRUCCIONES, CARGA, JUEGO, INTERMEDIO, GAMEOVER, FIN, PAUSA };
	Estado estado;
	bool flag;
	void resetFlag() { flag = 0; }
};
