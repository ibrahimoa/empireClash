#pragma once
#include "Tropa.h"

//Clase soldado, se representa en el juego con la imagen de un tanque
class Soldado : public Tropa
{
private:
	float aux;
public:
	Soldado(Vector2D pos, int niv = 1);
	~Soldado();

	virtual void mueve(float t);
	virtual void rageMode(float f) { // Soldado no tiene rage mode
		resetRage();
		// Do nothing
	}
};

