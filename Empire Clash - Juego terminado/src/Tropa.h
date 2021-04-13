#pragma once
#include "Vector2D.h"
#include "Objeto.h"
#include <iostream>
#include "ETSIDI.h"


using ETSIDI::SpriteSequence;


class Tropa : public Objeto
{
protected:
	float velocidad; // M�dulo de la velocidad de cada tropa;
	Vector2D vel;	 // Vector (unitario) que nos indica la direcci�n y el sentido de movimiento de cada tropa
	SpriteSequence sprite;
	
public:
	Tropa(std::string direccion, Vector2D tam, float vel, Vector2D pos, float l, float alcan);
	~Tropa();

	void dibuja();

	virtual void mueve(float t); // Funci�n polim�rfica. Se superpone en las clases "Jeep" y "Soldado".

	void setVel(Vector2D velo) { vel = velo; }
	float getVel() { return velocidad; };
	Vector2D getVvel() { return vel; }
	void rageMode(float porcentaje){} //C�digo a implementar m�s tarde.Debe estar pues en la plantilla de listas se le llama
};