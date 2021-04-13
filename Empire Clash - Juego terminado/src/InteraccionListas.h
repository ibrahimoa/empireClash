#pragma once
#include "Lista.h"
#include "ListaDisparos.h"

class InteraccionListas
{
public:
	InteraccionListas();
	~InteraccionListas();

	static void masCercana(Lista<Tropa> tropas, Lista<Defensa> defensas);
	static void impacto(ListaDisparos &disparos, Lista<Defensa> &defensas, Lista<Tropa> &tropas);
	static void colision(Lista<Tropa> tropas, Lista<Defensa> defensas);
};