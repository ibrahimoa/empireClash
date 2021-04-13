#pragma once
#include "Disparo.h"


class DisparoTropas: public Disparo
{
public:
	DisparoTropas(Vector2D start, Vector2D vel, float d,float a, bool tr) : Disparo(start, vel, d,a, tr) {}
	~DisparoTropas();
	virtual void dibuja();
};