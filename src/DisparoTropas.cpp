#include "DisparoTropas.h"
#include "glut.h"


DisparoTropas::~DisparoTropas()
{
}


void DisparoTropas::dibuja() {

	glColor3f(0.9f, 0.9f, 1.0f);

	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.0f);

	glutSolidSphere(radio, 4, 4);
	glPopMatrix();
}