// Fracciones.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Fraccion.h"

Fraccion::Fraccion(int numerador, int denominador)
{
	this->numerador = numerador;
	this->denominador = denominador;
}

Fraccion::Fraccion(Fraccion & f)
{
	*this = f;
}

Fraccion::~Fraccion() //Joab
{
	this->numerador = 0;
	this->denominador = 0;
	delete this;
}

void Fraccion::operator=(Fraccion & otra)
{
	this->numerador = otra.numerador;
	this->denominador = otra.numerador;
}

Fraccion Fraccion::operator+(Fraccion otra) 
{
	Fraccion resultado = Fraccion(1, 1);
	if (this->denominador == otra.denominador)
	{
		resultado = Fraccion(this->numerador + otra.numerador, this->denominador);
	}
	else
	{
		resultado = Fraccion((this->numerador*otra.denominador) + (otra.numerador*this->denominador), this->denominador*otra.denominador);
	}
	simplificar(resultado);
	return resultado;
}

Fraccion Fraccion::operator-(Fraccion otra) //Joab
{	
	Fraccion resultado = Fraccion(1, 1);
	if (this->denominador == otra.denominador)
	{
		resultado = Fraccion(this->numerador - otra.numerador, this->denominador);
	}
	else
	{
		resultado = Fraccion((this->numerador*otra.denominador) - (otra.numerador*this->denominador), this->denominador*otra.denominador);
	}
	simplificar(resultado);
	return resultado;
}

Fraccion Fraccion::operator/(Fraccion otra) //Joab
{
	int aux = otra.denominador;
	otra.denominador = otra.numerador;
	otra.numerador = aux;
	Fraccion resultado = operator*(otra);
	return resultado;
}

Fraccion Fraccion::operator*(Fraccion otra)
{
	Fraccion nueva = Fraccion(this->numerador*otra.numerador, this->denominador*otra.denominador);
	return nueva;
}

Fraccion Fraccion::simplificar(Fraccion & f) //Basado en el codigo disponible en https://isseu.wordpress.com/2009/08/27/funcion-reducir-fraccion-c/ por Isseu
{
	int mcf = 2;

	while ((mcf <= f.numerador) && (mcf <= f.denominador) && (f.numerador != 1) && (f.denominador != 1))
	{
		if ((f.numerador % mcf == 0) && (f.denominador % mcf == 0))
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
	out << f.numerador << "/" << f.denominador;
	return out;
}
