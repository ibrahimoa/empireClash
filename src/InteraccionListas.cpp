#include "InteraccionListas.h"


InteraccionListas::InteraccionListas()
{
}


InteraccionListas::~InteraccionListas()
{
}


void InteraccionListas::masCercana(Lista<Tropa> tropas, Lista<Defensa> defensas) {
	// Asigna el vector de la defensa más cercana a las tropas.
	for (int i = 0; i < tropas.getNumero(); i++) {
		Vector2D me = tropas[i]->getPos();
		int def = defensas.getNumero();
		float dist_min = 1000000;
		Vector2D posRelativa;
		int defensa_cercana = 0;
		for (int i = 0; i < def; i++) {
			float dist = (defensas[i]->getPos() - me).getModulo();
			if (dist < dist_min) {
				dist_min = dist;
				posRelativa = defensas[i]->getPos() - me;
			}
		}
		tropas[i]->setMasCercano(posRelativa);
	}

	//Asigna el vector de la tropa más cercana a las defensas.
	
	for (int i = 0; i < defensas.getNumero(); i++) {
		if (tropas.getNumero()) {
			Vector2D me = defensas[i]->getPos();
			int def = tropas.getNumero();
			float dist_min = 1000000;
			Vector2D posRelativa;
			int defensa_cercana = 0;
			for (int i = 0; i < def; i++) {
				float dist = (tropas[i]->getPos() - me).getModulo();
				if (dist < dist_min) {
					dist_min = dist;
					posRelativa = tropas[i]->getPos() - me;
				}
			}
			defensas[i]->setMasCercano(posRelativa);
		}
		else defensas[i]->setMasCercano(Vector2D(1000,1000));
	}
}


void InteraccionListas::impacto(ListaDisparos &disparos, Lista<Defensa> &defensas, Lista<Tropa> &tropas) {

	for (int i = 0; i < defensas.getNumero(); i++) {
		for (int j = 0; j < disparos.getNumero(); j++) {
			if (((disparos[j]->getPos() - defensas[i]->getPos()).getModulo() <= (disparos[j]->getRadio() + defensas[i]->getLado()) / 2.5f)&& disparos[j]->getTropa()) {
				defensas[i]->reducirVida(disparos[j]->getDaño());
				disparos.eliminar(j);
				if (defensas[i]->getVida() <= 0) {
					defensas.eliminar(i);
					ETSIDI::play("sonidos/explosion-defense.wav");
				}
			}
		}
	}

	for (int i = 0; i < tropas.getNumero(); i++) {
		for (int j = 0; j < disparos.getNumero(); j++) {
			if (((disparos[j]->getPos() - tropas[i]->getPos()).getModulo() <= (disparos[j]->getRadio() + tropas[i]->getLado()) / 2.5f) && !(disparos[j]->getTropa())) {
				tropas[i]->reducirVida(disparos[j]->getDaño());
				disparos.eliminar(j);
				if (tropas[i]->getVida() <= 0) {
					tropas.eliminar(i);
					ETSIDI::play("sonidos/explosion-troop.wav");
				}
			}
		}
	}
}
 
void InteraccionListas::colision(Lista<Tropa> tropas, Lista<Defensa> defensas) {
	 for (int i = 0; i < tropas.getNumero(); i++) {
		 for (int j = 0; j < defensas.getNumero(); j++) {
			 Interaccion::colisionAsimetrica(tropas[i],defensas[j]);
		 }
	 }
}
