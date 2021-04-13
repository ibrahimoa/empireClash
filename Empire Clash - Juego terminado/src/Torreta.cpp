#include "Torreta.h"



Torreta::Torreta(Vector2D pos, int niv):Defensa(pos, Vector2D(12.0f, 16.0f), 10.0f, 45.0f) //Defensa(Vector2D posicion, Vector2D tamaño, float lado, float alcance)
{
	direccion = "imagenes/Torreta.png";
	switch (niv)
	{
	case 1: vida = 2500;
		vida_incial = vida;
		daño = 150.0f;
		break;
	case 2: vida = 3500;
		vida_incial = vida;
		daño = 200.0f;
		break;
	case 3: vida = 4500;
		vida_incial = vida;
		daño = 250.0f;
		break;
	default:
		break;
	}
}

Torreta::~Torreta()
{
}

void Torreta::setPos(float x, float y, int niv) {
	posicion.x = x;
	posicion.y = y;
	switch (niv)
	{
	case 1: vida = 2500;
		daño = 150.0f;
		break;
	case 2: vida = 3500;
		daño = 200.0f;
		break;
	case 3: vida = 4500;
		daño = 2500.0f;
		break;
	default:
		break;
	}
}