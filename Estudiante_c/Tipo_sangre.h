#pragma once
#include <iostream>
using namespace std;
class Tipo_sangre
{
	// atributos
protected:
	string tipo_sangre;
	
	//constructor
protected:
	Tipo_sangre() {
	}

	Tipo_sangre(string tipsa) {
		tipo_sangre = tipsa;
	}
};

