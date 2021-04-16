#include "DisparoDefensas.h"
#include "glut.h"


DisparoDefensas::~DisparoDefensas()
{
}


void DisparoDefensas::dibuja() {

	if (rage == true) {
		glColor3f(0.9f, 0.1f, 0.1f);
	}
	else {
		glColor3f(0.8f, 0.5f, 0.5f);
	}

	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.0f);

	glutSolidSphere(radio, 5, 5);
	glPopMatrix();
}