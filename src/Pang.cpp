#include <stdio.h>
#include "CoordinadorJuego.h"
#include "glut.h"


/* El juego ha sido diseñado en base al conocido juego CLASH OF CLANS.

La idea principal es la creación de un juego bélico de estrategia.

El juego consiste en la selección de 'tropas' por medio de teclado, y en su despliegue por medio del uso del click izquierdo del ratón a lo largo del
mapa disponible, dentro de unos límites.

Estas tropas se moverán y dispararán al enemigo más cercano (de aquí en adelante, 'defensa'), creando disparos aleatorios según un número creado al azar,
contenido en unos límites.
Las defensas, por su parte, son fijas e invariantes, pero también buscan objetos a disparar, creando el disparo aleatorio en dirección a su 'enemigo'.

Gana el nivel quien destruya antes todos los objetos del enemigo, y gana el juego quien pase los 4 niveles.

Existen diferentes tropas, como se verá más adelante, caracterizadas por su velocidad, daño y alcance. Estos valores variarán conforme se aumente el
nivel. También aumentará el número de defensas y el número disponible de tropas.

A modo de explicación, se deja un fichero en el que puede verse la jerarquía de clases y herencias, mediante un atajo en teclado, pulsando
la tecla ' * ' durante la pantalla de inicio.

*/



CoordinadorJuego juego;


//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x_t, int y_t); //cuando se pulse una tecla
void onSpecialKeyboardDown(int key, int x, int y); //cuando se pulse una tecla especial
void MouseClick(int button, int state, int x, int y); //cuando se pulsa el ratón


int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(MouseClick); //Ratón

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	juego.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	juego.tecla(key);

	glutPostRedisplay();
}

void onSpecialKeyboardDown(int key, int x, int y)
{
	juego.teclaEspecial(key);
}

void MouseClick(int button, int state, int x, int y)
{
	juego.raton(button, state, x, y);
}

void OnTimer(int value)
{
//poner aqui el código de animacion
	juego.mueve();

	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}
