#include "Menu.h"
#include "ETSIDI.h"


Menu::Menu()
{
	ataque.setPos("imagenes/MenuAtaque.png", -72.5f, -54.5f, -24.0f, -36.5f, 0.2f);
	defensa.setPos("imagenes/MenuDefensa.png", 72.5f, -54.5f, 24.0f, -36.0f, 0.2f);
	fondo.setPos("imagenes/MenuFondo.png", -24.0f, -54.5f, 24.0f, -36.5f, 0.19f);
}


Menu::~Menu()
{
}

void Menu::dibuja() {

	ETSIDI::setTextColor(1, 1, 1); //r g b
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);

	ETSIDI::printxy("Your troops:", -60, -36);
	ataque.dibuja();

	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("Defenses:", 44, -36);
	defensa.dibuja();

	fondo.dibuja();

}
