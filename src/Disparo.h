#pragma once
#include "Vector2D.h"


class Disparo //Clase abstracta
{
protected:
	Vector2D pos_incial;
	Vector2D posicion;
	Vector2D vel;
	float radio;
	float daño;
	float alcance;
	bool tropa; //Si tropa==true entonces el disparo es de una tropa (no hay fuego amigo).
	bool rage; // Si rage == true entonces cambia el color del disparo
	bool fin;
public:
	Disparo(Vector2D start,Vector2D vel, float d,float a, bool tr, bool rg);
	virtual ~Disparo();
	virtual void dibuja() = 0;
	void mueve(float t);
	Vector2D getPos() { return posicion; }
	float getRadio() { return radio; }
	float getDaño() { return daño; }
	bool getTropa() { return tropa; }
	bool getFin() { return fin; }
	bool setRage() { rage = true; }
	bool resetRage() { rage = false; }
};
