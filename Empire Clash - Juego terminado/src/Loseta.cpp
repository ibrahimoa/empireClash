#include "Loseta.h"
#include "glut.h"
#include <string>



Loseta::Loseta() {
	r = 1;
	g = 1;
	b = 1;
}

Loseta::~Loseta()
{
}

void Loseta::dibuja() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(direccion.c_str()).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(r, g, b);
	glTexCoord2d(0, 1); glVertex3f(limite1.x, limite1.y, posZ);
	glTexCoord2d(1, 1); glVertex3f(limite2.x, limite1.y, posZ);
	glTexCoord2d(1, 0); glVertex3f(limite2.x, limite2.y, posZ);
	glTexCoord2d(0, 0); glVertex3f(limite1.x, limite2.y, posZ);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}


void Loseta::setPos(std::string d, float x1, float y1, float x2, float y2, float Z)
{
	direccion = d;
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
	posZ = Z;
}

void Loseta::setColor(int red, int green, int blue) {
	r = red;
	g = green;
	b = blue;
}