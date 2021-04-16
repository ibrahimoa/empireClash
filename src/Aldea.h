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
	bool rageTropas;
	bool rageDefensas;
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
	void dibujaMenu();
	void resetNiv() { nivel = 0;}

	void setRageTropas() {
		if (!rageTropas) {
			tropas.rageMode(2.0f);
			rageTropas = true;
		}
	}
	void resetRageTropas() { rageTropas = false; }

	void setRageDefensas() { 
		if (!rageDefensas) {
			defensas.rageMode(2.0f);
			rageDefensas = true;
		}
	}
	void resetRageDefensas() {
		if (rageDefensas) {
			rageDefensas = false;
		}
	}

	bool getRageTropas() { return rageTropas; }
	bool getRageDefensas() { return rageDefensas; }
};

