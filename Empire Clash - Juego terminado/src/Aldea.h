#pragma once
#include"Loseta.h"
#include "Menu.h"
#include "Lista.h"
#include "ListaDisparos.h"


class Aldea
{
private:
	Lista<Defensa> defensas;
	Lista<Tropa> tropas;
	ListaDisparos disparos;

	Loseta suelo,carga;
	Menu menu;

	int nivel;
	int tropas_disponibles;
	float x_ojo;
	float y_ojo;
	float z_ojo;
	char tipoTropa;
	bool rage;
public:
	Aldea();
	~Aldea();
	void inicializa();
	void mueve();
	void dibuja();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void raton(int button, int state, int x, int y);
	bool cargarNivel(bool avanza = 0);
	int getNumDef() { return defensas.getNumero(); }
	int getNumTro() { return tropas.getNumero(); }
	int getNumTroDisp() { return tropas_disponibles; }
	int getNivel() { return nivel; }
	void rageMode(float p);
	void dibujaMenu();
	void resetNiv() { nivel = 0;}
	void setRage() { rage = true; }
};

