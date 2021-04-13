#include "ListaDisparos.h"
#include "ETSIDI.h"


using namespace ETSIDI;

ListaDisparos::ListaDisparos()
{
}


ListaDisparos::~ListaDisparos()
{
}


bool ListaDisparos::agregar(Disparo* d)
{ 
	int a = ETSIDI::lanzaDado(80);
	if (a==1){
		lista.push_back(d);
		if (d->getTropa()) ETSIDI::play("sonidos/shot-troop.wav");
		else ETSIDI::play("sonidos/shot-defense.wav");
		return true;
		}
	else
		return false;
}

void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < lista.size(); i++) {
		delete lista[i];
		lista.erase(lista.begin() + i);
	}
}

void ListaDisparos::dibuja()
{
	for (int i = 0; i < lista.size(); i++)
		lista[i]->dibuja();
}

Disparo *ListaDisparos::operator [](int i)
{
	if (i >= lista.size())//si me paso, devuelvo la ultima
		i = lista.size() - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaDisparos::eliminar(int index)
{
	if ((index < 0) || (index >= lista.size()))
		return;
	delete lista[index];

	lista.erase(lista.begin()+index);
}

void ListaDisparos::mueve(float t) {
	for (int i = 0; i < lista.size(); i++){

		// Los disparos desaparecerán cuando salgan de los límites de la pantalla.
		if (((lista[i]->getPos()).x < -77) || ((lista[i]->getPos()).x > 77) || ((lista[i]->getPos()).y < -40) || ((lista[i]->getPos()).y > 62)) {
			eliminar(i); 
		}
		if (lista[i]->getFin()) eliminar(i); //Si han sobrepasado el alcance

		// Si los disparos no sobrepasan ese límite, se mueven con normalidad.
		else lista[i]->mueve(t);
	}
}