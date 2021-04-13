#include "Cannon.h"



Cannon::Cannon(Vector2D pos, int niv):Defensa(pos, Vector2D(8.0f, 5.0f), 10.0f, 30.0f) //Defensa(Vector2D posicion, Vector2D tamaño, float lado, float alcance)
{
	direccion = "imagenes/Cannon.png";
	switch (niv)
	{
	case 1: 
		vida = 2000;
		vida_incial= vida;
		daño = 130.0f;
		break;
	case 2: 
		vida = 3000;
		vida_incial = vida;
		daño = 180.0f;
		break;
	case 3: 
		vida = 4000;
		vida_incial = vida;
		daño = 230.0f;
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
		daño = 130.0f;
		break;
	case 2: vida = 3000;
		daño = 180.0f;
		break;
	case 3: vida = 4000;
		daño = 230.0f;
		break;
	default:
		break;
	}
}