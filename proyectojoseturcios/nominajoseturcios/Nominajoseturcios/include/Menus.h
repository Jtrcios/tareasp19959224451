#ifndef MENUS_H
#define MENUS_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "UsuarioPlanilla.h"
#include "EmpleadosPlanilla.h"
#include "Puestos.h"
#include "Departamento.h"
#include "Bitacora.h"

using namespace std;

class Menus
{
    public:
        string menuI(string nombreUsuario);
        string menuCata(string nombreUsuario);
        string subMenuEmpleados(string nombreUsuario);
        string subMenuInf(string nombreUsuario);

    protected:

    private:
};

#endif // MENUS_H
