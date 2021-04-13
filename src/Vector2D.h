#pragma once
#include "math.h"
#include <iostream>



class Vector2D
{
public:
	float x;
	float y;


	Vector2D();
	Vector2D(float a, float b);
	~Vector2D();

	float getModulo() { return (float)sqrt(x * x + y * y); }
	float getDireccion() { return atan2(y, x); }
	Vector2D operator-(Vector2D &a); //Resta de vectores
	Vector2D operator+(Vector2D &a); //Suma de vectores
	float operator* (Vector2D &a); //Producto escalar
	Vector2D operator*(float); //Producto por un escalar
	Vector2D unitario(); //Devuelve un vector unitario
	bool operator==(Vector2D &a);
	void operator +=(Vector2D &a);
	std::ostream& operator<<(std::ostream& o) { std::cout << x << " , " << y << std::endl; return o; }
	void print() {std::cout << "X: " << x << ", Y: " << y;}
};

