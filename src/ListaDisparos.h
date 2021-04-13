#pragma once
#include "Interaccion.h"//incluye "Disparo.h"
#include <vector>


//Vector dinámico que contiene un número variable de objetos tipo "Disparo" implementado mediante la Standard Template Library (STL)
class ListaDisparos
{
	std::vector<Disparo*> lista;
public:
	ListaDisparos();
	~ListaDisparos();
	bool agregar(Disparo* d);
	void dibuja();
	void destruirContenido();
	void eliminar(int index);
	int getNumero() { return lista.size(); }
	Disparo* operator [](int);
	void mueve(float t);
};