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
	float da?o;
	float alcance;
	unsigned int cadencia;
	bool rage;
	std::string direccion;
	Vector2D tama?o;
	Vector2D mas_cercano;

public:
	Objeto(Vector2D pos, float l, float alcan, unsigned int cad, Vector2D tam) :
		posicion(pos), lado(l), alcance(alcan), cadencia(cad), tama?o(tam), rage(false) {}
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

	float getDa?o() { return da?o; }

	float getAlcance() { return alcance; }

	float getLado() { return lado; }

	float getVida() { return vida; }

	float getVida_inic() { return vida_incial; }

	void reducirVida(float d) { vida -= d; }

	void setMasCercano(Vector2D objeto) { mas_cercano = objeto; }

	int getCadencia() { return cadencia; }

	void setCadencia(unsigned int c) { cadencia = c; }

	void setRage() { rage = true; }

	void resetRage() { rage = false; }

	bool getRage() { return rage; }

	Vector2D getMasCercano() { return mas_cercano; }
};