#include "Vector2D.h"


Vector2D::Vector2D()
{
	x = y = 0.0f;
}

Vector2D::Vector2D(float a, float b)
{
	x = a;
	y = b;
}


Vector2D::~Vector2D()
{
}


Vector2D Vector2D::operator - (Vector2D &a)
{
	Vector2D res;
	res.x = x - a.x;
	res.y = y - a.y;
	return res;
}

Vector2D Vector2D::operator+(Vector2D &a) {
	Vector2D res;
	res.x = x + a.x;
	res.y = y + a.y;
	return res;
}

float Vector2D::operator*(Vector2D &a) {
	return x * a.x + y * a.y;
}

Vector2D Vector2D::operator*(float a) {
	Vector2D res;
	res.x = x * a;
	res.y = y * a;
	return res;
}

Vector2D Vector2D::unitario() {
	Vector2D retorno(x, y);
	float mod = getModulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

bool Vector2D::operator==(Vector2D &a) {
	if (x == a.x && y == a.y) return true;
	else return false;
}

void Vector2D::operator+=(Vector2D &a) {
	x = x + a.x;
	y = y + a.y;
}