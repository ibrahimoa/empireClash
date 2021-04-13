#include "Interaccion.h"
#include <iostream>


Interaccion::Interaccion()
{
}


Interaccion::~Interaccion()
{
}


bool Interaccion::colision(Tropa* t, Tropa* p) {
	Vector2D met = t->getPos();
	Vector2D mep = p->getPos();

	float dist = (met - mep).getModulo();
	float dentro = dist - (t->getLado() + p->getLado());

	if (dentro < 0.0f) //Si hay colision
	{
		t->setPos(t->getPos() + (mep - met).unitario()* (dentro / 2));
		p->setPos(p->getPos() + (met - mep).unitario()* (dentro / 2));
		return true;
	}
	return false;
}

bool Interaccion::colisionAsimetrica(Objeto *o, Objeto *q) {
	Vector2D met = o->getPos();
	Vector2D med = q->getPos();

	float dist = (met - med).getModulo() * 2;
	float dentro = dist - (o->getLado() + q->getLado());


	if (dentro < 0.0f) //Si hay colision
	{
		o->setPos(o->getPos() + (med - met).unitario()* (dentro));
		return true;
	}
	return false;
}