#include "Defensa.h"



Defensa::~Defensa()
{
}

void Defensa::dibuja() {
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(direccion.c_str()).id);
	glEnable(GL_BLEND); // Si tiene canal alfa el png, no lo muestra
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Si tiene canal alfa el png, no lo muestra
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f(posicion.x - tamaño.x / 2, posicion.y - tamaño.y / 2, 0.0f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f(posicion.x + tamaño.x / 2, posicion.y - tamaño.y / 2, 0.0f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f(posicion.x + tamaño.x / 2, posicion.y + tamaño.y / 2, 0.0f);
	glTexCoord2d(0.0f, 0.0f); glVertex3f(posicion.x - tamaño.x / 2, posicion.y + tamaño.y / 2, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	/// Dibujo de la barra de vida
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	if (vida <= vida_incial) {
		glColor3f(1.0f, 0.0f, 0.0f);
		glTexCoord2d(0.0f, 1.0f); glVertex3f(posicion.x - 6.0f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 1.0f); glVertex3f(posicion.x - 6.0f + (vida / vida_incial)*12.f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 0.0f); glVertex3f(posicion.x - 6.0f + (vida / vida_incial)*12.f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);
		glTexCoord2d(0.0f, 0.0f); glVertex3f(posicion.x - 6.0f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);
	}
	else if(vida<=(vida_incial*2)){
		glColor3f(0.0f, 0.0f, 0.0f);
		glTexCoord2d(0.0f, 1.0f); glVertex3f(posicion.x - 6.0f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 1.0f); glVertex3f(posicion.x - 6.0f + ((vida-vida_incial) / vida_incial)*12.f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 0.0f); glVertex3f(posicion.x - 6.0f + ((vida-vida_incial) / vida_incial)*12.f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);
		glTexCoord2d(0.0f, 0.0f); glVertex3f(posicion.x - 6.0f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glTexCoord2d(0.0f, 1.0f); glVertex3f(posicion.x - 6.0f + ((vida - vida_incial) / vida_incial)*12.f+0.1f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 1.0f); glVertex3f(posicion.x + 6.0f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 0.0f); glVertex3f(posicion.x +6.0f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);
		glTexCoord2d(0.0f, 0.0f); glVertex3f(posicion.x - 6.0f + ((vida - vida_incial) / vida_incial)*12.f+0.1f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);

	}
	else if (vida <= (vida_incial * 3)) {
		glColor3f(0.4f, 0.1f, 0.5f);
		glTexCoord2d(0.0f, 1.0f); glVertex3f(posicion.x - 6.0f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 1.0f); glVertex3f(posicion.x - 6.0f + ((vida - vida_incial*2) / vida_incial)*12.f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 0.0f); glVertex3f(posicion.x - 6.0f + ((vida - vida_incial*2) / vida_incial)*12.f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);
		glTexCoord2d(0.0f, 0.0f); glVertex3f(posicion.x - 6.0f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);

		glColor3f(0.0f, 0.0f, 0.0f);
		glTexCoord2d(0.0f, 1.0f); glVertex3f(posicion.x - 6.0f + ((vida - vida_incial*2) / vida_incial)*12.f+0.1f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 1.0f); glVertex3f(posicion.x + 6.0f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 0.0f); glVertex3f(posicion.x + 6.0f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);
		glTexCoord2d(0.0f, 0.0f); glVertex3f(posicion.x - 6.0f + ((vida - vida_incial*2) / vida_incial)*12.f+0.1f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);
	}
	else {
		vida = vida_incial * 3;
		glColor3f(0.4f, 0.1f, 0.5f);
		glTexCoord2d(0.0f, 1.0f); glVertex3f(posicion.x - 6.0f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 1.0f); glVertex3f(posicion.x - 6.0f + ((vida - vida_incial * 2) / vida_incial) * 12.f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 0.0f); glVertex3f(posicion.x - 6.0f + ((vida - vida_incial * 2) / vida_incial) * 12.f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);
		glTexCoord2d(0.0f, 0.0f); glVertex3f(posicion.x - 6.0f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);

		glColor3f(0.0f, 0.0f, 0.0f);
		glTexCoord2d(0.0f, 1.0f); glVertex3f(posicion.x - 6.0f + ((vida - vida_incial * 2) / vida_incial) * 12.f + 0.1f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 1.0f); glVertex3f(posicion.x + 6.0f, posicion.y - tamaño.y / 2 - 2.0f, 0.05f);
		glTexCoord2d(1.0f, 0.0f); glVertex3f(posicion.x + 6.0f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);
		glTexCoord2d(0.0f, 0.0f); glVertex3f(posicion.x - 6.0f + ((vida - vida_incial * 2) / vida_incial) * 12.f + 0.1f, posicion.y - tamaño.y / 2 - 1.0f, 0.05f);
	}
	glEnd();
	glEnable(GL_LIGHTING);
}
