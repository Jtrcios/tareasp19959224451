#ifndef BITACORA_H
#define BITACORA_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include <ctime>
using namespace std;

class Bitacora
{
    public:
        string ingresoDatosBit(string nombreUsuario, string numeAccion, string accionRealizada);
        void imprimirDatosBit();


    protected:

    private:
        string nombreUsuario, numeAccion, accionRealizada;
        char* fechaHoraAccion;
};

#endif // BITACORA_H
