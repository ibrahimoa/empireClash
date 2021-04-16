#include "Soldado.h"


//Tropa(std::string direccion, Vector2D tam, float vel, Vector2D pos, float l, float alcan, int cad);
Soldado::Soldado(Vector2D pos, int niv) :Tropa("imagenes/Soldado.png", Vector2D(22.0f, 16.0f), 2.0f, pos, 9.0f, 30.0f, 4) 
{
	aux = 1;
	switch (niv)
	{
	case 1: vida = 2500;
		vida_incial = vida;
		daño = 300.0f;
		break;
	case 2: vida = 3500;
		vida_incial = vida;
		daño = 350.0f;
		break;
	case 3: vida = 4500;
		vida_incial = vida;
		daño = 400.0f;
		break;
	case 4: vida = 5500;
		vida_incial = vida;
		daño = 450.0f;
		break;
	default:
		break;
	}
}

Soldado::~Soldado(){
}

void Soldado::mueve(float t) {
	if (vel.x < 0.01 && vel.x > -0.01 && vel.y < 0.01 && vel.y > -0.01) {
		aux = 1.0f;
	}
	else if (aux > 0) aux -= 0.03f;
	posicion += vel * t*(1.0f - 2 * aux);
}

