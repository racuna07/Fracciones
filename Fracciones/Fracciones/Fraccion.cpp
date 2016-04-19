// Fracciones.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Fraccion.h"
using namespace std;

Fraccion::Fraccion(int numerador, int denominador)
{
}

Fraccion::Fraccion(Fraccion & f)
{
	*this = f;
}

Fraccion::~Fraccion()
{
}

void Fraccion::operator=(Fraccion &otra)
{
	this->numerador = otra.numerador;
	this->denominador = otra.numerador;
}

Fraccion Fraccion::operator+(Fraccion otra)
{
	return ;
}

Fraccion Fraccion::operator-(Fraccion otra)
{
	return ;
}

Fraccion Fraccion::operator/(Fraccion otra)
{
	return ;
}

Fraccion Fraccion::operator*(Fraccion otra)
{
	return ;
}

Fraccion Fraccion::simplificar(Fraccion & f)
{
	int mcf=2;

	while ((mcf <= f.numerador) && (mcf <= f.denominador) && (f.numerador != 1) && (f.denominador != 1))
	{
		if ( (f.numerador % mcf == 0) && (f.denominador % mcf == 0))
		{
			f.numerador = (f.numerador / mcf);
			f.denominador = (f.denominador / mcf);
		}
		mcf++;
	}

	return f;
}

ostream & operator<<(ostream & out, Fraccion f)
{
	return out;
}
