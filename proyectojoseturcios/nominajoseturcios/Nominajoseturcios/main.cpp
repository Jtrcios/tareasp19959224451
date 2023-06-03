#include <iostream>
#include <cstdlib>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "UsuarioPlanilla.h"

UsuarioPlanilla llamaPortada;
using namespace std;

int main()
{
    llamaPortada.Portada("Portada.txt");
    UsuarioPlanilla IngresoUsuario;
    int numero;
    do
    {
    system("cls");
    cout<<"\t\t\t----------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t|         Bienvenido al Sistema de Registro de usuarios de empresas patito S.A.        |"<<endl;
	cout<<"\t\t\t----------------------------------------------------------------------------------------"<<endl;
	cout<<"\n\t\t\t 1. Iniciar sesion "<<endl;
	cout<<"\t\t\t 2. Registrar a un nuevo usuario"<<endl;
	cout<<"\t\t\t 3. Salir del Sistema"<<endl;

    cout << "\n\t\t\t---------------------------------------";
    cout << "\n\t\t\t| Escoge una opción: [1] - [2] - [3]  |";
    cout << "\n\t\t\t---------------------------------------";

	cout<< " "<<endl;
	cout<<"\n\n\t\t\tingrsar opcion: ";
	cin>>numero;

        switch(numero)
        {
            case 1:
                IngresoUsuario.inicioSesion();
                break;

            case 2:
                IngresoUsuario.registroU();
                break;

            case 3:
                break;

            default:
                cout<<"\t\t\tError; Ingrese una opcion valida"<<endl;
                cin.get();
        }
    } while(numero!= 3);


    return 0;
}
