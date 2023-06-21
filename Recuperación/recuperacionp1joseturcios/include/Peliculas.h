#ifndef PELICULAS_H
#define PELICULAS_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

#include "Bitacora.h"
#include "Menus.h"

using namespace std;

class Peliculas
{
    public:
        void menuPeli(string nombreUsuario);
        void registroPeli(string nombreUsuario);
        void modificarPeli(string nombreUsuario);
        void imprimirPeli(string nombreUsuario);
        void buscarPeli(string nombreUsuario);
        void borrarPeli(string nombreUsuario);

    protected:

    private:
        string idPeli, nombrePeli, clasPeli, genPeli, subPeli, idiomaPeli, precPeli, horaPeli;
};

#endif // PELICULAS_H
