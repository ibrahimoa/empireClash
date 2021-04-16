#pragma once
#include "Disparo.h"


class DisparoTropas: public Disparo
{
public:
	DisparoTropas(Vector2D start, Vector2D vel, float d,float a, bool tr, bool rg) : Disparo(start, vel, d,a, tr, rg) {}
	~DisparoTropas();
	virtual void dibuja();
};