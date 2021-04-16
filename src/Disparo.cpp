#include "Disparo.h"
#include "ETSIDI.h"
#include "glut.h"


Disparo::Disparo(Vector2D start,Vector2D veloc, float d,float a, bool tr, bool rg)
{	
	fin = false;
	pos_incial = start;
	posicion = start;
	daño = d;
	alcance = a;
	//Modulo de la velocidad es 60 por defecto
	vel = (veloc.unitario()) * 60.0f;
	radio = 1.0f;
	tropa = tr;
	rage = rg;
}


Disparo::~Disparo()
{
}

void Disparo::mueve(float t) {
	if ((pos_incial - posicion).getModulo() >= (alcance+2.0f)) {
		fin = true;
		return;
	}
	posicion = posicion + vel * t;
}