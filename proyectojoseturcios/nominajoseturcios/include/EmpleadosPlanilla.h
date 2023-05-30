#ifndef EMPLEADOSPLANILLA_H
#define EMPLEADOSPLANILLA_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Menus.h"
#include "Bitacora.h"
using namespace std;

class EmpleadosPlanilla
{
    public:
        void menuEmpleadosPlanilla();
        void insertarEmpleado();
		void modificarEmpleado();
		void buscarEmpleado();
		void borrarEmpleado();
		void imprimirEmpleados();


    protected:

    private:
        string idEmpleado, nombreEmpleado, apellidoEmpleado, dpiEmpleado, direccionEmpleado, telefonoEmpleado;
};

#endif // EMPLEADOSPLANILLA_H
