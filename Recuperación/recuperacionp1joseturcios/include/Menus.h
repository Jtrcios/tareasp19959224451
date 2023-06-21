#ifndef MENUS_H
#define MENUS_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

#include "Usuario.h"
#include "Bitacora.h"

using namespace std;

class Menus
{
    public:
        void menuInicial(string nombreUsuario);
        void menuCatalogos(string nombreUsuario);
        void subMenuEmpleados(string nombreUsuario);
        void subMenuInformes(string nombreUsuario);
        void menuProcesos(string nombreUsuario);

    protected:

    private:
};

#endif // MENUS_H
