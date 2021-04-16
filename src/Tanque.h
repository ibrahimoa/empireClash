#pragma once
#include "Defensa.h" //Incluye "Vector2D.h"

class Tanque :public Defensa
{

public:
	Tanque(Vector2D pos, int niv = 1);
	~Tanque();
	void setPos(float x, float y, int niv = 1);
	virtual void rageMode(float f) {
		setRage();
		daño = getDaño() * f;
		vida += getVida_inic() * f;
	}
};