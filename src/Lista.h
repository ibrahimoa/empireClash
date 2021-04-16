#pragma once
#include "ListaDisparos.h"
#include "DisparoDefensas.h"
#include "DisparoTropas.h"
#define MAXIMO 12

// Plantilla que se instancia en el archivo Aldea.h para crear las listas de tropas y de defensas. 
template<class T> class Lista
{
private:
	T * lista[MAXIMO];
	int numero;

public:
	Lista();
	~Lista();
	bool agregar(T* t);
	void dibuja();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(T* t);
	int getNumero() { return numero; }
	T* operator[](int a);
	void colision();
	void marcha(float t, ListaDisparos &disparos);
	void dispara(ListaDisparos &disparos);
	void rageMode(float p);
};


template<class T> Lista<T>::Lista()
{
}


template<class T> Lista<T>::~Lista()
{
}


template<class T> bool Lista<T>::agregar(T *t) {
	if (numero < MAXIMO)
		lista[numero++] = t;
	else
		return false;
	return true;
}


template<class T> void Lista<T>::dibuja() {

	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();

}


template<class T> void Lista<T>::destruirContenido() {
	for (int i = 0; i < numero; i++) {
		delete lista[i];
	}
	numero = 0;

}


template<class T> void Lista<T>::eliminar(int index) {
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}


template<class T> void Lista<T>::eliminar(T *t) {
	for (int i = 0; i < numero; i++)
		if (lista[i] == t) {
			eliminar(i);
			return;
		}
}


template<class T> T *Lista<T>::operator[](int a) {
	if (a >= numero) //Si me paso devuelvo el último
		a = numero - 1;
	if (a < 0) //Si el índice es negativo devuelvo la primera
		a = 0;
	return lista[a];
}


template<class T> void Lista<T>::colision() {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < numero; j++) {
			if (i != j) {
				Interaccion::colision((lista[i]), (lista[j]));
			}
		}
	}
}


template<class T> void Lista<T>::marcha(float t, ListaDisparos &disparos) {

	for (int i = 0; i < numero; i++) {
		if ((lista[i]->getMasCercano()).getModulo() > lista[i]->getAlcance())
		{
			lista[i]->setVel((lista[i]->getMasCercano()).unitario() * lista[i]->getVel());
			lista[i]->mueve(t);
		}
		else {
			DisparoTropas* d = new DisparoTropas(lista[i]->getPos(), lista[i]->getMasCercano(), lista[i]->getDaño(),lista[i]->getAlcance() , true, lista[i]->getRage());
			disparos.agregar(d, lista[i]->getCadencia());
		}
	}
}


template<class T> void Lista<T>::dispara(ListaDisparos &disparos) {
	for (int i = 0; i < numero; i++) {
		if ((lista[i]->getMasCercano()).getModulo() <= lista[i]->getAlcance()) {

			DisparoDefensas* d = new DisparoDefensas(lista[i]->getPos(), lista[i]->getMasCercano(), lista[i]->getDaño(),lista[i]->getAlcance(), false, lista[i]->getRage());
			disparos.agregar(d, lista[i]->getCadencia());
		}
	}
}


template <class T> void Lista<T>::rageMode(float p) {
	for (int i = 0; i < numero; i++) {
		lista[i]->rageMode(p);
	}
}