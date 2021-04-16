#include "Carro.h"


//Tropa(std::string direccion, Vector2D tamaño, float velocidad, Vector2D posicion, float lado, float alcance, int cadencia);
Carro::Carro(Vector2D pos, int niv) :Tropa("imagenes/Carro.png", Vector2D(12.0f, 12.0f), 3.2f, pos, 6.0f, 25.0f, 8)
{
	switch (niv)
	{
	case 1: vida = 1800;
		vida_incial = vida;
		daño = 120.0f;
		break;
	case 2: vida = 2100;
		vida_incial = vida;
		daño = 170.0f;
		break;
	case 3: vida = 2400;
		vida_incial = vida;
		daño = 220.0f;
		break;
	case 4: vida = 2700;
		vida_incial = vida;
		daño = 270.0f;
		break;
	default:
		break;
	}
}

Carro::~Carro(){
}
