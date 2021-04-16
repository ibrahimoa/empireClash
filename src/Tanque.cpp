#include "Tanque.h"


Tanque::Tanque(Vector2D pos, int niv):Defensa(pos, Vector2D(15.0f, 12.0f), 10.0f, 25.0f, 4) //Defensa(Vector2D posicion, Vector2D tamaño, float lado, float alcance)
{
	direccion = "imagenes/Tanque.png";
	switch (niv)
	{
	case 1: vida = 5000;
		vida_incial = vida;
		daño = 150.0f;
		break;
	case 2: vida = 7500;
		vida_incial = vida;
		daño = 220.0f;
		break;
	case 3: vida = 10000;
		vida_incial = vida;
		daño = 275.0f;
		break;
	default:
		break;
	}
}

Tanque::~Tanque()
{
}

void Tanque::setPos(float x, float y, int niv) {
	posicion.x = x;
	posicion.y = y;
	switch (niv)
	{
	case 1: vida = 5000;
		daño = 150.0f;
		break;
	case 2: vida = 7500;
		daño = 220.0f;
		break;
	case 3: vida = 10000;
		daño = 275.0f;
		break;
	default:
		break;
	}
}