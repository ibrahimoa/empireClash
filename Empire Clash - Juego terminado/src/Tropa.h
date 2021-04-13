#pragma once
#include "Vector2D.h"
#include "Objeto.h"
#include <iostream>
#include "ETSIDI.h"


using ETSIDI::SpriteSequence;


class Tropa : public Objeto
{
protected:
	float velocidad; // Módulo de la velocidad de cada tropa;
	Vector2D vel;	 // Vector (unitario) que nos indica la dirección y el sentido de movimiento de cada tropa
	SpriteSequence sprite;
	
public:
	Tropa(std::string direccion, Vector2D tam, float vel, Vector2D pos, float l, float alcan);
	~Tropa();

	void dibuja();

	virtual void mueve(float t); // Función polimórfica. Se superpone en las clases "Jeep" y "Soldado".

	void setVel(Vector2D velo) { vel = velo; }
	float getVel() { return velocidad; };
	Vector2D getVvel() { return vel; }
	void rageMode(float porcentaje){} //Código a implementar más tarde.Debe estar pues en la plantilla de listas se le llama
};