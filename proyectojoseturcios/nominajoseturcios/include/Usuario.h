#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Bitacora.h"
#include "Menus.h"


using namespace std;

class Usuario
{
    public:
        void usuarioRegister();
        bool usuarioLog();
        bool buscarLogUsuario(string user, string passw);
        string getnombreU();

    protected:

    private:
        string nombreU, Password;
};

#endif // USUARIO_H
