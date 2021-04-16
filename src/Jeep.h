#pragma once
#include "Tropa.h"

class Jeep : public Tropa
{
private:
	float aux;
public:
	Jeep(Vector2D pos, int niv = 1);
	~Jeep();
	virtual void mueve(float t);
	virtual void rageMode(float f) { // Jeep no tiene rage mode
		resetRage();
		// Do nothing
	}
};

