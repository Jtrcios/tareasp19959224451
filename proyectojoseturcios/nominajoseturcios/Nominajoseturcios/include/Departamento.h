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
      string DepartamentosPlanilla(string nombreUsuario);
      void NuevosDepa();
      void BuscarDepa();
      void ModificarDepa();
      void eliminarDepa();
      void imprimirDepa();


    protected:

    private:
        string idDepartamento, nombreDepartamento, nombreEncargado, telefonoDepartamento;
};

#endif // DEPARTAMENTO_H
