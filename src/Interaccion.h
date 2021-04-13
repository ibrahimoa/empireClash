#pragma once
#include "Vector2D.h"
#include "Defensa.h"
#include "Disparo.h"
#include "Tropa.h"


class Interaccion
{
public:
	Interaccion();
	~Interaccion();

	static bool colision(Tropa* t, Tropa* p);
	static bool colisionAsimetrica(Objeto *o, Objeto *q);
};

