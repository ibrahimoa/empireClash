#pragma once
#include "Tropa.h"

class Carro : public Tropa
{
public:
	Carro(Vector2D pos, int niv = 1);
	~Carro();
	//virtual void mueve(float t);
	virtual void rageMode(float f) {
		setRage();
		daño = getDaño() * f;
	}
};

