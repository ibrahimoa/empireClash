#pragma once
#include "Loseta.h"
class Menu
{
public:
	Menu();
	~Menu();

	void dibuja();
	void setActivo(int n) {
		if (n == 0) activo = act_tanque;
		if (n == 1) activo = act_jeep;
		if (n == 2) activo = act_carro;
	}
	int getActivo() {
		return activo;
	}

private:
	Loseta ataque, defensa, fondo;
	enum Activo { act_tanque, act_jeep, act_carro };
	Activo activo;

};

