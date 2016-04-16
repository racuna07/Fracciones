#pragma once

#include <iostream>;

using namespace std;

class Fraccion {

	friend ostream & operator<<(ostream &, Fraccion);

public:

	Fraccion(int, int);
	Fraccion(Fraccion &);
	virtual ~Fraccion();  //Joab
	void operator=(Fraccion &);
	Fraccion operator+(Fraccion);
	Fraccion operator-(Fraccion); //Joab
	Fraccion operator/(Fraccion); //Joab
	Fraccion operator*(Fraccion);

private:
	int numerador;
	int denominador;
	void simplificar(Fraccion &);	

};

ostream & operator<<(ostream &, Fraccion);