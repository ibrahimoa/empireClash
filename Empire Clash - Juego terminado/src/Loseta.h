#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include <iostream>
#define MAX 100

 
class Loseta
{
	std::string direccion;
	int r, g, b;
	Vector2D limite1;
	Vector2D limite2;
	float posZ;

public:
	Loseta();
	~Loseta();

	void dibuja();
	void setPos(std::string d, float x1, float y1, float x2, float y2, float Z);
	void setIma(std::string d) { direccion = d; };
	void setColor(int red, int green, int blue);
};

