#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

#include "Menus.h"

using namespace std;

class Usuario
{

	public:
		void inicioSesion();
		void menuU(string nombreUsuario);
		void registroU();
		void imprimirUsuario(string nombreUsuario);
		void borrarUsuario(string nombreUsuario);
		void modificarUsuario(string nombreUsuario);
		void buscarUsuario(string nombreUsuario);
		void dibujarPort(string nombreArchivo);

		private:
		string nombre, contrasena;
};

#endif // USUARIO_H
