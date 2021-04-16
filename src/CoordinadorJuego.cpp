#include "CoordinadorJuego.h"
#include "ETSIDI.h"

CoordinadorJuego::CoordinadorJuego()
{
	ETSIDI::stopMusica();
	estado = INICIO;
	ETSIDI::playMusica("sonidos/Intro.wav");
}

CoordinadorJuego::~CoordinadorJuego()
{
}



void CoordinadorJuego::tecla(unsigned char key) {
	if (estado == INICIO)
	{
		// Al empezar, reseteamos el flag, para que al volver de
		// GAMEOVER no conserve su estado.
		resetFlag();

		if (key == 's' || key == 'S') estado=CARGA;
		
		else if (key == 'e' || key == 'E') exit(0);
	}
/*
	else if (estado == INSTRUCCIONES) {
		if (key == ' ') estado = CARGA;
	}*/

	else if (estado == CARGA) {
		if (key == 'c' || key == 'C') {
			aldea.inicializa();
			estado = JUEGO;
			//	musica();
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/Play.wav", true);

		}

	}

	else if (estado == JUEGO)
	{
		aldea.tecla(key);
		if (key == 'p' || key == 'P')
			estado = PAUSA;

		//Listado de HACKS para desarrolladores

		if (key == '1') aldea.cargarNivel(); //Atajo para avanzar de nivel de 1 en 1
		if (key == '2') flag = 1; // Atajo para llegar a GAMEOVER
		if (key == '3') aldea.cargarNivel(1); // Atajo para llegar a nivel 4
		// if (key == '4') defensas.destruirContenido(); Implementado en Aldea.cpp
	}

	else if (estado == INTERMEDIO) {
		if (key == 'n' || key == 'N') {
			estado = JUEGO;
			if (!aldea.cargarNivel())
				estado = FIN;
		}

	}

	else if (estado == GAMEOVER)
	{
		if (key == 'c' || key == 'C'){
			aldea.resetNiv();

			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/Intro.wav");

		    estado = INICIO;
	    }
		else if (key == 'e' || key == 'E') {
			exit(0);
		}
			
	}

	else if (estado == FIN)
	{
		if (key == 'c' || key == 'C') {

			aldea.resetNiv();

			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/Intro.wav");

			estado = INICIO;

		}
		else if (key == 'e' || key == 'E')
			exit(0);
	}

	else if (estado == PAUSA) {
		if (key == 'c' || key == 'C')
			estado = JUEGO;
		else if (key == 'e' || key == 'E') {
			aldea.resetNiv();

			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/Intro.wav");

			estado = INICIO;
		
	
		}
	}
}

void CoordinadorJuego::teclaEspecial(unsigned char key) {
	if (estado == JUEGO)
		aldea.teclaEspecial(key);
}

void CoordinadorJuego::raton(int button, int state, int x, int y) {

	if (estado == JUEGO) 
		aldea.raton(button, state, x, y);
	
}

void CoordinadorJuego::mueve() {

	if (estado == JUEGO) {
		if ((aldea.getNumDef() <= 1) && (!aldea.getRageDefensas())) {
			aldea.setRageDefensas();
		}

		aldea.mueve();

		if (!aldea.getNumDef()){
			if (aldea.getNivel() < 4)
				// Si no quedan defensas  y estamos en un nivel inferior al 4, pasamos a INTERMEDIO
				estado = INTERMEDIO;
			else {
				// Si no quedan defensas y estamos en el nivel 4, pasamos a FIN
				estado = FIN;
				ETSIDI::stopMusica();
				ETSIDI::playMusica("sonidos/victory.wav");
			}
		
		}
		
		// Si no quedan tropas, pero si defensas, o si atajo por teclado, pasamos a GAMEOVER
		if (!aldea.getNumTroDisp() && aldea.getNumDef() && !aldea.getNumTro() || flag == 1) {
			
			estado = GAMEOVER;
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/game-over.wav");
		}

	}
}

void CoordinadorJuego::dibuja() {

	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		//Ponemos fondo a la pantalla de incicio
		pantalla.setPos("imagenes/fondo.png", -14.5, -3.5, 14.5, 18.5, 0.0);
		pantalla.dibuja();

		ETSIDI::setTextColor(1.0f, 1.0f, 1.0f); //r g b
		ETSIDI::setFont("fuentes/War.ttf", 70);
		ETSIDI::printxy("EMPIRE CLASH", -9, 12);
		ETSIDI::setTextColor(1.0f, 1.0f, 1.0f);
		ETSIDI::setFont("fuentes/War.ttf", 20);
		ETSIDI::printxy("PRESS S TO START", -3, 4);
		ETSIDI::printxy("PRESS E TO EXIT", -3, 3); 
		ETSIDI::setTextColor(1.0f, 1.0f, 1.0f);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("Victor Zamora Mayoral", 6, 0);
		ETSIDI::printxy("Ibrahim Oulad Amar", 6, -1);
		ETSIDI::printxy("Alejandro Ramirez Lopez", 6, -2);
	}
/*	else if (estado==INSTRUCCIONES){
		pantalla.~Loseta();

		//Ponemos fondo a la pantalla de incicio
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		
		//Poner imagen con las instrucciones
		pantalla.setPos("imagenes/instruccion.png", -14.5, -3.5, 14.5, 18.5, 0.0);
		pantalla.dibuja();
	
	}*/
	else if (estado == CARGA) {
		pantalla.~Loseta();

		//Ponemos fondo a la pantalla de incicio
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		
		//Poner imagen con las instrucciones
		pantalla.setPos("imagenes/Loading.png", -14.5, -3.5, 14.5, 18.5, 0.0);
		pantalla.dibuja();

	}
	else if (estado == JUEGO){
		
		pantalla.~Loseta();
		aldea.dibuja();

		}

	else if (estado == INTERMEDIO) {

		aldea.dibuja();

		//Código de dibujo de la pantalla INTERMEDIO
		ETSIDI::setTextColor(1.0f, 1.0f, 1.0f); //r g b
		ETSIDI::setFont("fuentes/War.ttf", 70);
		ETSIDI::printxy("LEVEL COMPLETED", -50, 12);
		ETSIDI::setFont("fuentes/War.ttf", 30);
		ETSIDI::printxy("PRESS  N  T0 PLAY NEXT LEVEL", -40, -10);

	}

	else if (estado == GAMEOVER) {
	
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		
		// Ponemos imagen a GAMEOVER
		pantalla.setPos("imagenes/gameover.png", -14.5, -3.5, 14.5, 18.5, 0.0);
		pantalla.dibuja();
		
	}

	else if (estado == FIN) {
	
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		
		// Ponemos imagen a FIN
		pantalla.setPos("imagenes/victory.png", -14.5, -3.5, 14.5, 18.5, 0.0);
		pantalla.dibuja();

	}

	else if (estado == PAUSA) { 
		aldea.dibuja();

		//Código de dibujo de la pantalla PAUSA
		ETSIDI::setTextColor(1.0f, 1.0f, 1.0f); //r g b
		ETSIDI::setFont("fuentes/War.ttf", 70);
		ETSIDI::printxy("PAUSE", -19, 12);
		ETSIDI::setFont("fuentes/War.ttf", 30);
		ETSIDI::printxy("PRESS  C  T0 C0NTINUE", -28, -10);
		ETSIDI::printxy("PRESS  E  T0 EXIT", -23, -20);
	}
}