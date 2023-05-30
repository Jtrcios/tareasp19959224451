#include "Menus.h"
Usuario registrarNombre;

string Menus::menu(string nombreUsuario)
{
    system("cls");
    int optEscoger;
  bool repetir = true;
    do
    {
    cout << "Usuario: " << registrarNombre.getnombreU() << endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t| Bienvenido al Sistema de Nominas de Empleados |";
    cout << "\n\t\t\t-----------------------------------------------"<<endl;

    cout << "\t\t\t1. Menu Catalogos"<<endl;
    cout << "\t\t\t2. Menu Procesos"<<endl;
    cout << "\t\t\t3. Menu Informes"<<endl;
    cout << "\t\t\t4. Salir del Sistema" << endl;
    cout << "\n\n\t\t\t---------------------------------------";
    cout << "\n\t\t\t| Opciones a escoger: [1] - [2] - [3] - [4]";
    cout << "\n\t\t\t---------------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion que desea escoger: ";
    cin >> optEscoger;

    switch(optEscoger)
    {
    case 1:{
       system("cls");
       Menus submenu;
       submenu.menuCatalogos();
        break;
    }

    case 2:{
        system("cls");
    break;
    }
    case 3:{
        system("cls");
        break;
        }
    case 4:{
             exit(0);
        break;
    }
    default:
        cout << "Opcion invalida... Intente otra vez...";

    }
    }while(optEscoger!=4);
}

void Menus::menuCatalogos()
{
    system("cls");
    int optEscoger;
  bool repetir = true;
    do
    {
    cout << "\t\t\t-----------------------------------\n";
    cout << "\t\t\t| Bienvenido al Menu de Catalogos |";
    cout << "\n\t\t\t---------------------------------"<<endl;

    cout << "\t\t\t1. Empleados"<<endl;
    cout << "\t\t\t2. Puestos"<<endl;
    cout << "\t\t\t3. Departamentos"<<endl;
    cout << "\t\t\t4. Salir del Sistema" << endl;
    cout << "\n\n\t\t\t---------------------------------------";
    cout << "\n\t\t\t| Opciones a escoger: [1] - [2] - [3] - [4]";
    cout << "\n\t\t\t---------------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion que desea escoger: ";
    cin >> optEscoger;

    switch(optEscoger)
    {
    case 1:{
       system("cls");
       EmpleadosPlanilla menu;
       menu.menuEmpleadosPlanilla();
                break;
    }

    case 2:{
        system("cls");
        Puestos menu;
        menu.menuPuestos();
    break;
    }
    case 3:{
        system("cls");
        Departamento menu;
        menu.Departamentos();
        break;
        }
    case 4:{
        system("cls");
        exit (0);
        break;
    }
    default:
        cout << "Opcion invalida... Intente otra vez...";

    }
    }while(repetir);
}
