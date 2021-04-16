#include "DisparoTropas.h"
#include "glut.h"


DisparoTropas::~DisparoTropas()
{
}


void DisparoTropas::dibuja() {

	if (rage == true) {
		glColor3f(0.1f, 0.1f, 0.9f);
	}
	else {
		glColor3f(0.5f, 0.5f, 0.8f);
	}

	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.0f);

	glutSolidSphere(radio, 4, 4);
	glPopMatrix();
}