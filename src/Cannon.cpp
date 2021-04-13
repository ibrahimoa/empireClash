#include "Cannon.h"



Cannon::Cannon(Vector2D pos, int niv):Defensa(pos, Vector2D(8.0f, 5.0f), 10.0f, 30.0f) //Defensa(Vector2D posicion, Vector2D tama�o, float lado, float alcance)
{
	direccion = "imagenes/Cannon.png";
	switch (niv)
	{
	case 1: 
		vida = 2000;
		vida_incial= vida;
		da�o = 130.0f;
		break;
	case 2: 
		vida = 3000;
		vida_incial = vida;
		da�o = 180.0f;
		break;
	case 3: 
		vida = 4000;
		vida_incial = vida;
		da�o = 230.0f;
		break;
	default:
		break;
	}
}

Cannon::~Cannon()
{
}

void Cannon::setPos(float x, float y, int niv) {
	posicion.x = x;
	posicion.y = y;
	switch (niv)
	{
	case 1: vida = 2000;
		da�o = 130.0f;
		break;
	case 2: vida = 3000;
		da�o = 180.0f;
		break;
	case 3: vida = 4000;
		da�o = 230.0f;
		break;
	default:
		break;
	}
}