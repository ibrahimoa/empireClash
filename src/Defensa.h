#pragma once
#include "Objeto.h"
#include "Vector2D.h"
#include <iostream>
#include "ETSIDI.h"


class Defensa : public Objeto
{

public:
	Defensa(Vector2D pos, Vector2D tam, float l, float alcan) : Objeto(pos, l, alcan, tam) {}
	~Defensa();

	void dibuja();
	virtual void rageMode(float f){}  // do nothing by default
};