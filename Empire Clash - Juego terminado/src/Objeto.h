#pragma once
#include "Vector2D.h"
#include "Loseta.h"

//Clase abstracta que engloba al resto de objetos

class Objeto
{
	
protected:
	Vector2D posicion;
    float vida_incial;
	float vida;
	float lado;
	float daño;
	float alcance;
	std::string direccion;
	Vector2D tamaño;
	Vector2D mas_cercano;

public:
	Objeto(Vector2D pos, float l, float alcan, Vector2D tam):posicion(pos), lado(l), alcance(alcan), tamaño(tam) {}
	~Objeto();

	Vector2D getPos() {
		Vector2D pos(0, 0);
		pos.x = posicion.x;
		pos.y = posicion.y;
		return pos;
	}

	void setPos(Vector2D  pos) {
		posicion = pos;
	}

	float getDaño() { return daño; }

	float getAlcance() { return alcance; }

	float getLado() { return lado; }

	float getVida() { return vida; }

	float getVida_inic() { return vida_incial; }

	void reducirVida(float d) { vida -= d; }

	void setMasCercano(Vector2D objeto) { mas_cercano = objeto; }

	Vector2D getMasCercano() { return mas_cercano; }
};