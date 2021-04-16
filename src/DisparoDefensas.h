#pragma once
#include "Disparo.h"


class DisparoDefensas: public Disparo
{
public:
	DisparoDefensas(Vector2D start, Vector2D vel, float d,float a, bool tr, bool rg) : Disparo(start, vel, d, a, tr, rg) {}
	~DisparoDefensas();
	virtual void dibuja();
};