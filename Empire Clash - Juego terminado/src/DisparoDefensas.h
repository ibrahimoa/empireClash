#pragma once
#include "Disparo.h"


class DisparoDefensas: public Disparo
{
public:
	DisparoDefensas(Vector2D start, Vector2D vel, float d,float a, bool tr) : Disparo(start, vel, d,a,tr) {}
	~DisparoDefensas();
	virtual void dibuja();
};