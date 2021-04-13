#pragma once
#include "Defensa.h"
using namespace std;
//#include "Vector2D.h" Incluida en "Defensa.h"

class Torreta :public Defensa
{
	
public:
	Torreta(Vector2D pos, int niv = 1);
	~Torreta();
	void setPos(float x, float y, int niv = 1);
	virtual void rageMode(float f) {
		daño += getDaño()*(f-1);
		vida += getVida_inic()*(f-1);	
	}
};

