#include "Tropa.h"
#include "ETSIDI.h"
#define PI 3.1416

Tropa::Tropa(std::string direccion, Vector2D tam, float velo, Vector2D pos, float l, float alcan, unsigned int cad) :sprite(direccion.c_str(), 4, 4), velocidad(velo), Objeto(pos, l, alcan, cad, tam) {
	sprite.setCenter(tam.x / 2, tam.y / 2);
	sprite.setSize(tam.x, tam.y);
	vel = Vector2D(0, 0);
}

Tropa::~Tropa() {
}

void Tropa::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.05f);
	glColor3f(1.0f, 1.0f, 1.0f);

	if (vel.getDireccion() >= (PI / 8)*0.5 && vel.getDireccion() < (PI / 8)*1.5) sprite.setState(4);
	if (vel.getDireccion() >= (PI / 8)*1.5 && vel.getDireccion() < (PI / 8)*2.5) sprite.setState(5);
	if (vel.getDireccion() >= (PI / 8)*2.5 && vel.getDireccion() < (PI / 8)*3.5) sprite.setState(6);
	if (vel.getDireccion() >= (PI / 8)*3.5 && vel.getDireccion() < (PI / 8)*4.5) sprite.setState(7);
	if (vel.getDireccion() >= (PI / 8)*4.5 && vel.getDireccion() < (PI / 8)*5.5) sprite.setState(8);
	if (vel.getDireccion() >= (PI / 8)*5.5 && vel.getDireccion() < (PI / 8)*6.5) sprite.setState(9);
	if (vel.getDireccion() >= (PI / 8)*6.5 && vel.getDireccion() < (PI / 8)*7.5) sprite.setState(10);
	if (vel.getDireccion() >= (PI / 8)*7.5 || vel.getDireccion() < (PI / 8)*-7.5) sprite.setState(11);

	if (vel.getDireccion() >= (PI / 8)*-0.5 && vel.getDireccion() < (PI / 8)*0.5) sprite.setState(3);
	if (vel.getDireccion() >= (PI / 8)*-1.5 && vel.getDireccion() < (PI / 8)*-0.5) sprite.setState(2);
	if (vel.getDireccion() >= (PI / 8)*-2.5 && vel.getDireccion() < (PI / 8)*-1.5) sprite.setState(1);
	if (vel.getDireccion() >= (PI / 8)*-3.5 && vel.getDireccion() < (PI / 8)*-2.5) sprite.setState(0);
	if (vel.getDireccion() >= (PI / 8)*-4.5 && vel.getDireccion() < (PI / 8)*-3.5) sprite.setState(15);
	if (vel.getDireccion() >= (PI / 8)*-5.5 && vel.getDireccion() < (PI / 8)*-4.5) sprite.setState(14);
	if (vel.getDireccion() >= (PI / 8)*-6.5 && vel.getDireccion() < (PI / 8)*-5.5) sprite.setState(13);
	if (vel.getDireccion() >= (PI / 8)*-7.5 && vel.getDireccion() < (PI / 8)*-6.5) sprite.setState(12);

	sprite.draw();
	glPopMatrix();

	/// Dibujo de la barra de vida
	glDisable(GL_LIGHTING); 
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f(posicion.x - 6.0f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f(posicion.x -6.0f + (vida/vida_incial)*12.f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f(posicion.x - 6.0f + (vida / vida_incial)*12.f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);
	glTexCoord2d(0.0f, 0.0f); glVertex3f(posicion.x - 6.0f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Tropa::mueve(float t) {
	posicion += vel * t;
}