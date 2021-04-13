#include <stdio.h>
#include "CoordinadorJuego.h"
#include "glut.h"


/* El juego ha sido dise�ado en base al conocido juego CLASH OF CLANS.

La idea principal es la creaci�n de un juego b�lico de estrategia.

El juego consiste en la selecci�n de 'tropas' por medio de teclado, y en su despliegue por medio del uso del click izquierdo del rat�n a lo largo del
mapa disponible, dentro de unos l�mites.

Estas tropas se mover�n y disparar�n al enemigo m�s cercano (de aqu� en adelante, 'defensa'), creando disparos aleatorios seg�n un n�mero creado al azar,
contenido en unos l�mites.
Las defensas, por su parte, son fijas e invariantes, pero tambi�n buscan objetos a disparar, creando el disparo aleatorio en direcci�n a su 'enemigo'.

Gana el nivel quien destruya antes todos los objetos del enemigo, y gana el juego quien pase los 4 niveles.

Existen diferentes tropas, como se ver� m�s adelante, caracterizadas por su velocidad, da�o y alcance. Estos valores variar�n conforme se aumente el
nivel. Tambi�n aumentar� el n�mero de defensas y el n�mero disponible de tropas.

A modo de explicaci�n, se deja un fichero en el que puede verse la jerarqu�a de clases y herencias, mediante un atajo en teclado, pulsando
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
void MouseClick(int button, int state, int x, int y); //cuando se pulsa el rat�n


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
	glutMouseFunc(MouseClick); //Rat�n

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
	//poner aqui el c�digo de teclado
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
//poner aqui el c�digo de animacion
	juego.mueve();

	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}
