#pragma once
#include "Interaccion.h"//incluye "Disparo.h"
#include <vector>


//Vector din?mico que contiene un n?mero variable de objetos tipo "Disparo" implementado mediante la Standard Template Library (STL)
class ListaDisparos
{
	std::vector<Disparo*> lista;
public:
	ListaDisparos();
	~ListaDisparos();
	bool agregar(Disparo* d, int cadencia);
	void dibuja();
	void destruirContenido();
	void eliminar(unsigned int index);
	int getNumero() { return lista.size(); }
	Disparo* operator [](unsigned int);
	void mueve(float t);
};