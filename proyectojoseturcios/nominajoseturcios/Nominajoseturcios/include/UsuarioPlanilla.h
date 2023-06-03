#ifndef USUARIOPLANILLA_H
#define USUARIOPLANILLA_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

#include "Menus.h"

using namespace std;

class UsuarioPlanilla
{

	public:
		void inicioSesion();
		string menuU(string nombreUsuario);
		void registroU();
		void imprUsuario();
		void borrarU();
		void modUsuario();
		void buscarU();
		void Portada(string nombreArchivo);

		private:
		string nombre, contrasena;
};

#endif // USUARIOPLANILLA_H
