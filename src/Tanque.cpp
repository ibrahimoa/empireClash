#include "Tanque.h"


Tanque::Tanque(Vector2D pos, int niv):Defensa(pos, Vector2D(15.0f, 12.0f), 10.0f, 25.0f, 4) //Defensa(Vector2D posicion, Vector2D tama�o, float lado, float alcance)
{
	direccion = "imagenes/Tanque.png";
	switch (niv)
	{
	case 1: vida = 5000;
		vida_incial = vida;
		da�o = 150.0f;
		break;
	case 2: vida = 7500;
		vida_incial = vida;
		da�o = 220.0f;
		break;
	case 3: vida = 10000;
		vida_incial = vida;
		da�o = 275.0f;
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
		da�o = 150.0f;
		break;
	case 2: vida = 7500;
		da�o = 220.0f;
		break;
	case 3: vida = 10000;
		da�o = 275.0f;
		break;
	default:
		break;
	}
}