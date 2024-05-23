#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Estudiante {
private:
	int id = 0;
	int codigo = 0;
	string nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0, id_tipo_sangre = 0;

	//constructor
public:
	Estudiante() {}

	Estudiante(int cod, string nom, string ape, string dir, int tel, string fn, int id_tisa, int i) {
		id = i;
		codigo = cod;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;
		id_tipo_sangre = id_tisa;
	};

	//METODOS
	//set (modificar)
	void setId(int i) { id = i; }
	void setCodigo(int cod) { codigo = cod; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_Nacimiento(string fn) { fecha_nacimiento = fn; }
	void setId_Tipo_Sangre(int id_tisa) { id_tipo_sangre = id_tisa; }
	//get (mostrar)
	int getId() { return id; }
	int getCodigo() { return codigo; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	int getId_Tipo_Sangre() { return id_tipo_sangre; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string c = to_string(codigo);
		string t = to_string(telefono);
		string ts = to_string(id_tipo_sangre);

		if (cn.getConectar()) {
			string insertar =
				"INSERT INTO estudiantes(codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento, id_tipo_sangre) VALUES('" + c + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + ",'" + ts +  "')';";
			const char* i = insertar.c_str();
			//ejecutar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitosos..." << endl;
			}
			else {
				cout << "Error al ingresar " << endl;
			}
		}
		else {
			cout << "xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------------------Estudiantes --------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ":" << fila[1] << ":" << fila[2] << ":" << fila[3] << ":" << fila[4] << ":" << fila[5] << ":" << fila[6] << ":" << fila[7] << endl;
				}
			}
			else {
				cout << "Error al consultar" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string c = to_string(id);
		string t = to_string(id);
		string ts = to_string(id);
		string ii = to_string(id);
		if (cn.getConectar()) {
			string actualizar = "update estudiantes set codigo = '" + c
				+ "', nombres='" + nombres + "', apellidos = '" + apellidos + "', direccion= '" +
				direccion + "', telefono= '" + t + "', fecha_nacimiento = '" + fecha_nacimiento + "', id_tipo_sangre= '" + ts + "' where id_estudiante = " + ii + "";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa" << endl;
			}
			else {
				cout << "Error al actualizar..." << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	void borrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string ii = to_string(id);
		if (cn.getConectar()) {
			string borrar = "delete from estudiantes where id_estudiante = " + ii + "";
			const char* i = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion exitosa..." << endl;
			}
			else {
				cout << "Error al ingresar" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

};

