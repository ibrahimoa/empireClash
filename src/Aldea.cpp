#include <iostream>
#include <string>
#include "Aldea.h"
#include "Cannon.h"
#include "Torreta.h"
#include "Tanque.h"
#include "Jeep.h"
#include "Carro.h"
#include "Soldado.h"
#include "Interaccion.h"
#include "InteraccionListas.h"
#include "glut.h"

using namespace std;

Aldea::Aldea() { 
	
}

Aldea::~Aldea() {
}

void Aldea::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		   	  0.0, 0.0, 0.0,        // hacia que punto mira  (0,0,0) 
			  0.0, 1.0, 0.0);       // definimos hacia arriba (eje Y)   

	suelo.dibuja();
	menu.dibuja();
	defensas.dibuja();
	tropas.dibuja();
	dibujaMenu();
	disparos.dibuja();
	
}


void Aldea::mueve()
{
	InteraccionListas::masCercana(tropas, defensas);
	InteraccionListas::impacto(disparos, defensas, tropas);
	InteraccionListas::colision(tropas, defensas);
	defensas.dispara(disparos);
	tropas.marcha(0.025f, disparos);
	tropas.colision();
	disparos.mueve(0.025f);
}


void Aldea::inicializa()
{
	x_ojo = 0;
	y_ojo = 0;
	z_ojo = 149.0;
	
	cargarNivel();
}


void Aldea::tecla(unsigned char key) { 
	if (key == 'q' || key == 'Q')
		menu.setActivo(0);
	if (key == 'w' || key == 'W')
		menu.setActivo(1);
	if (key == 'e' || key == 'E')
		menu.setActivo(2);
	if (key == 'r' || key == 'R') {
		setRageTropas();
	}
		
	 // YO NO LO PONDRIA . JANDRUS

	//// Más HACKS para desarrolladores
	if (key == '4')
		defensas.destruirContenido();
	//if (key == '.')
	//	tropas.destruirContenido();
}


void Aldea::teclaEspecial(unsigned char key) {
	
}


void Aldea::raton(int button, int state, int x, int y) {
	GLint viewport[4];
	GLdouble mvmatrix[16], projmatrix[16];
	GLint yr;  /*  OpenGL y coordinate position  */
	GLdouble wx, wy, wz;  /*  returned world x, y, z coords  */

	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			glGetIntegerv(GL_VIEWPORT, viewport);
			glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
			glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
			yr = viewport[3] - (GLint)y - 1;
			
			gluUnProject((GLdouble)x, (GLdouble)yr, 0.9999955065,
				mvmatrix, projmatrix, viewport, &wx, &wy, &wz);

			if ((wx >= -72) && (wx <= 72) && (wy >= -31) && (wy <= 53)) {
				if (menu.getActivo() == 0 && tropas_disponibles) {
					Soldado* s1 = new Soldado(Vector2D(wx, wy), nivel);
					tropas.agregar(s1);
					tropas_disponibles--;
				}

				if (menu.getActivo() == 1 && tropas_disponibles) {
					Jeep* j1 = new Jeep(Vector2D(wx, wy), nivel);
					tropas.agregar(j1);
					tropas_disponibles--;
				}

				if (menu.getActivo() == 2 && tropas_disponibles) {
					Carro* k1 = new Carro(Vector2D(wx, wy), nivel);
					tropas.agregar(k1);
					tropas_disponibles--;
				}

			}
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
		}
			
		break;
	default:
		break;
	}
}


bool Aldea::cargarNivel(bool avanza) {
	nivel++;
	tropas.destruirContenido();
	defensas.destruirContenido();
	disparos.destruirContenido();
	resetRageDefensas();
	resetRageTropas();

	// Usamos un bool por defecto como 'HACK' para avanzar al último nivel
	if (avanza == 1) nivel = 4;

	//Los niveles se dibujan correctamente

	if (nivel == 1)//Nivel 1
	{
		tropas_disponibles = 5;
		suelo.setPos("imagenes/fondo-niv1.png", -75.0f, 60.0f, 75.0f, -37.0f, -0.1f);

		Cannon *c1 = new Cannon(Vector2D(-20, 10), nivel);
		defensas.agregar(c1); //Cañon

		Torreta *to1 = new Torreta(Vector2D(10, 30), nivel);
		defensas.agregar(to1); //Torreta

		Tanque *ta1 = new Tanque(Vector2D(15, -25), nivel);
		defensas.agregar(ta1); //Tanque

	}
	if (nivel == 2) //Nivel 2
	{ 
		tropas_disponibles = 7;
		suelo.setIma("imagenes/fondo-niv2.png");

		Cannon *c1 = new Cannon(Vector2D(-25, 0), nivel);
		defensas.agregar(c1); //Cañon 1
		Cannon *c2 = new Cannon(Vector2D(25, 0), nivel);
		defensas.agregar(c2);//Cañon 2

		Torreta *to1 = new Torreta(Vector2D(0, 0), nivel);
		defensas.agregar(to1); //Torreta 1
		Torreta *to2 = new Torreta(Vector2D(0, 25), nivel);
		defensas.agregar(to2); //Torreta 2

		Tanque *ta1 = new Tanque(Vector2D(15, -25), nivel);
		defensas.agregar(ta1); //Tanque
		
	}
	if (nivel == 3) //Nivel 3
	{  
		tropas_disponibles = 9;
		suelo.setIma("imagenes/fondo-niv3.png");

		Cannon *c1 = new Cannon(Vector2D(-25, 0), nivel);
		defensas.agregar(c1); //Cañon 1
		Cannon *c2 = new Cannon(Vector2D(25, 0), nivel);
		defensas.agregar(c2);//Vector2D( 2

		Torreta *to1 = new Torreta(Vector2D(0, 0), nivel);
		defensas.agregar(to1); //Torreta 1
		Torreta *to2 = new Torreta(Vector2D(0, 25), nivel);
		defensas.agregar(to2); //Torreta 2
		Torreta *to3 = new Torreta(Vector2D(0, -25), nivel);
		defensas.agregar(to3); //Torreta 3

		Tanque *ta1 = new Tanque(Vector2D(-30, 30), nivel);
		defensas.agregar(ta1); //Tanque 1
		Tanque *ta2 = new Tanque(Vector2D(30, 30), nivel);
		defensas.agregar(ta2); //Tanque 2
		Tanque *ta3 = new Tanque(Vector2D(-30, -25), nivel);
		defensas.agregar(ta3); //Tanque 3
		Tanque *ta4 = new Tanque(Vector2D(30, -25), nivel);
		defensas.agregar(ta4); //Tanque 4
	}
	if (nivel == 4) //Nivel 4 -> ¡OJO! Nuevo nivel de tropas también, sino no funciona 
	{
		tropas_disponibles = 10;
		suelo.setIma("imagenes/fondo-niv4.png");

		Cannon *c1 = new Cannon(Vector2D(15, 0), 3);
		defensas.agregar(c1); //Cañon 1
		Cannon *c2 = new Cannon(Vector2D(-15, 0), 3);
		defensas.agregar(c2);//Cañon 2
		Cannon *c3 = new Cannon(Vector2D(0, 0), 3);
		defensas.agregar(c3); //Cañon 3

		Torreta *to1 = new Torreta(Vector2D(0, -25), 3);
		defensas.agregar(to1); //Torreta 1
		Torreta *to2 = new Torreta(Vector2D(0, 25), 3);
		defensas.agregar(to2); //Torreta 2
		Torreta *to3 = new Torreta(Vector2D(30, 0), 3);
		defensas.agregar(to3); //Torreta 3
		Torreta *to4 = new Torreta(Vector2D(-30, 0), 3);
		defensas.agregar(to4); //Torreta 4

		Tanque *ta1 = new Tanque(Vector2D(-30, 30), 3);
		defensas.agregar(ta1); //Tanque 1
		Tanque *ta2 = new Tanque(Vector2D(30, 30), 3);
		defensas.agregar(ta2); //Tanque 2
		Tanque *ta3 = new Tanque(Vector2D(-30, -25), 3);
		defensas.agregar(ta3); //Tanque 3
		Tanque *ta4 = new Tanque(Vector2D(30, -25), 3);
		defensas.agregar(ta4); //Tanque 4
	}
	if (nivel <= 4)
		return true;
	return false;
}


void Aldea::dibujaMenu() {
	string str = to_string(tropas_disponibles);

	if (tropas_disponibles) {
		ETSIDI::printxy("Remaining troops:", -20, -47);
		ETSIDI::printxy(str.c_str(), 16, -47);
	}
	else ETSIDI::printxy("No troops available", -20, -47);
}

