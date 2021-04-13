#include "DisparoDefensas.h"
#include "glut.h"


DisparoDefensas::~DisparoDefensas()
{
}

void DisparoDefensas::dibuja() {

	glColor3f(0.2f, 0.1f, 0.0f);

	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.0f);

	glutSolidSphere(radio, 5, 5);
	glPopMatrix();
}