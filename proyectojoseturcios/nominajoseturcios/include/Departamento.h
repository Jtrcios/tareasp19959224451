#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Menus.h"
using namespace std;


class Departamento
{
    public:
      void Departamentos();
      void NuevosDepartamentos();
      void BuscarDepartamentos();
      void ModificarDepartamentos();
      void eliminarDepartamento();
      void imprimirDepartamento();


    protected:

    private:
        string idDepartamento, nombreDepartamento, nombreEncargado, telefonoDepartamento;
};

#endif // DEPARTAMENTO_H
