#ifndef PUESTOS_H
#define PUESTOS_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Menus.h"
#include "Bitacora.h"
using namespace std;

class Puestos
{
    public:
        void menuPuestos();
        void insertarPuestos();
		void modificarPuestos();
		void buscarPuestos();
		void borrarPuestos();
		void imprimirPuestos();


    protected:

    private:
        string idPuesto, nombrePuesto, encargadoPuesto, tituloPuesto, salarioPuesto;
};

#endif // PUESTOS_H
