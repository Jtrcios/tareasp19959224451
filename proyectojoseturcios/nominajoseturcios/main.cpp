#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Menus.h"
#include "Usuario.h"
Usuario traerNombre;
using namespace std;

int main()
{
    string nombre = traerNombre.getnombreU();
    system("cls");
    int optEscoger;
    bool repetir = true;
    do
    {
    cout << "\t\t\t--------------------------\n";
    cout << "\t\t\t| Bienvenido al Sistema |";


    cout << "\n\n\n\t\t\t1. Inicio de Sesion" << endl;
    cout << "\t\t\t2. Registrar Usuario" << endl;
    cout << "\t\t\t3. Salir del Sistema" << endl;
    cout << "\n\n\t\t\t---------------------------------------";
    cout << "\n\t\t\t| Opciones a escoger: [1] - [2] - [3] ";
    cout << "\n\t\t\t---------------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion deseada: ";
    cin >> optEscoger;

    switch(optEscoger)
    {
    case 1:{
    bool accesoUsuario;

    Usuario usuarioRegistrado;
    accesoUsuario = usuarioRegistrado.usuarioLog();
    if (accesoUsuario)
        {
    int opciones;
    bool repetir = true;
    do
    {
	Menus systemMenu;
    systemMenu.menu(nombre);
    }while (repetir);}
        break;
    }
    case 2:{
        system("cls");
        Usuario newUser;
        newUser.usuarioRegister();
        break;
    }
    case 3:{
             exit(0);
        break;
    }
    default:
        cout << "Opcion invalida... Intente de nuevo..";

    }

    }while(optEscoger!=3);


    return 0;
}

