#pragma once
#include "Defensa.h"
//#include "Vector2D.h" Incluida en "Defensa.h"

class Cannon :public Defensa
{

public:

	Cannon(Vector2D pos, int niv = 1);
	~Cannon();
	void setPos(float x, float y, int niv = 1);
	virtual void rageMode(float f) {
		daño = getDaño() * f;
		vida += getVida_inic() * f;
	}
};

