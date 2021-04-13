#include "Carro.h"



Carro::Carro(Vector2D pos, int niv) :Tropa("imagenes/Carro.png", Vector2D(12.0f, 12.0f), 2.0f, pos, 6.0f, 20.0f) //Tropa(std::string direccion, Vector2D tamaño, float velocidad, Vector2D posicion, float lado, float alcance);
{
	switch (niv)
	{
	case 1: vida = 1800;
		vida_incial = vida;
		daño = 100.0f;
		break;
	case 2: vida = 2000;
		vida_incial = vida;
		daño = 150.0f;
		break;
	case 3: vida = 2200;
		vida_incial = vida;
		daño = 200.0f;
		break;
	case 4: vida = 2400;
		vida_incial = vida;
		daño = 250.0f;
		break;
	default:
		break;
	}
}

Carro::~Carro(){
}
