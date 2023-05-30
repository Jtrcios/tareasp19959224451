#ifndef MENUS_H
#define MENUS_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "EmpleadosPlanilla.h"
#include "Departamento.h"
#include "Puestos.h"
#include "Bitacora.h"
#include "Usuario.h"

using namespace std;
class Menus
{
    public:
        string menu(string nombreUsuario);
        void menuCatalogos();
        void subMenu();
        void DepartamentosPlanilla();

    protected:

    private:
};

#endif // MENUS_H
