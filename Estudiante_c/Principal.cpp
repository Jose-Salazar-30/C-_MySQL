#include "Estudiante.h"
#include <iostream>

using namespace std;

int main()
{
	string nombres, apellidos, direccion, fecha_nacimiento;
	int codigo = 0, telefono = 0, id_tipo_sangre = 0, id = 0;

	Estudiante e = Estudiante(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre, id);
	
	e.leer();
	
	cout << "Ingrese Codigo:";
	cin >> codigo;
	cin.ignore();
	cout << "Ingrese Nombres:";
	getline(cin, nombres);
	cout << "Ingres Apellidos:";
	getline(cin, apellidos);
	cout << "Ingrese Direccion:";
	getline(cin, direccion);
	cout << "Ingrese Telefono:";
	cin >> telefono;
	cin.ignore();
	cout << "Fecha Nacimiento:";
	cin >> fecha_nacimiento;
	cout << "Ingres Id Tipo Sangre:";
	cin >> id_tipo_sangre;
	cin.ignore();


	//e.crear();
	e.actualizar();
	e.leer();
	cout << "Ingrese ID: ";
	cin >> id;
	e.setId(id);
	e.borrar();
	e.leer();

	system("pase");
	return 0;

}

