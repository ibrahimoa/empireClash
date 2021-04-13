#include "Jeep.h"


Jeep::Jeep(Vector2D pos, int niv) :Tropa("imagenes/Jeep.png", Vector2D(10.0f, 10.0f), 3.2f, pos, 5.0f, 27.0f) //Tropa(std::string direccion, Vector2D tam, float vel, Vector2D pos, float l, float alcan);
{
	aux = 1.0f;
	switch (niv)
	{
	case 1: vida = 2000;
		vida_incial = vida;
		daño = 200;
		break;
	case 2: vida = 3000;
		vida_incial = vida;
		daño = 300.0f;
		break;
	case 3: vida = 4000;
		vida_incial = vida;
		daño = 350.0f;
		break;
	case 4: vida = 4500;
		vida_incial = vida;
		daño = 400.0f;
		break;
	default:
		break;
	}
}

Jeep::~Jeep(){
}

void Jeep::mueve(float t) {
	if (aux <= 3) aux += 0.2f;
	else aux = 1.0f;
	posicion += vel * t* aux;
}