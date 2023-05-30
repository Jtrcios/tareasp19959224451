#include "Usuario.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;
Bitacora registroBitacora;
Menus menuNombreusuario;

void Usuario::usuarioRegister()
{
    system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------- Registro de Usuarios ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngrese el Nombre del usuario a registrar: ";
	cin>> nombreU;
	cout<<"\n\t\t\tIngrese la Contrasena del usuario a registrar: ";
	cin>> Password;
	file.open("Usuario.txt", ios::app | ios::out);
	file <<std::left<<std::setw(15)<< nombreU <<std::left<<std::setw(15)<< Password << "\n";
	file.close();
}

bool Usuario::usuarioLog()
{
    string usuario, contra;
    int contador=0;
    bool ingresa=false;
    do{
        system("cls");
        cout<<"--------------------------"<<endl;
        cout<<"AUTENTICACION DE USUARIOS "<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"Nombre de usuario: ";
        getline(cin,usuario);
        cout<<"\nContrasena de usuario: ";
        char caracter;
        caracter= getch();
        contra="";
        while (caracter !=13)
        {
            if(caracter !=8)
            {
                contra.push_back(caracter);
                cout<<"*";
            } else
            {
                if (contra.length() > 0)
                {
                    cout<<"\b \b";
                    contra = contra.substr(0, contra.length()-1);
                }
            }
            caracter = getch();
        }

        if (buscarLogUsuario(usuario, contra)){
            ingresa=true;
        } else {
            registroBitacora.ingresoDatosBit(usuario,"7000","NLOG");
            cout<<"\nEl usuario y/o contrasena son incorrectos"<<endl;
            cin.get();
            contador++;
        }
    } while (ingresa==false && contador<3);
    if (ingresa==false){
        cout<<"\nLo siento, no puede ingresar al sistema, su contrasena es invalida o se agotaron los intentos"<<endl;
        cin.get();
    } else {
        cout<<"\n=== Bienvenidos al Sistema ==="<<endl;
        cout << "n=== " << usuario << " ===" << endl;
        cin.get();
    }
    return ingresa;
}

bool Usuario::buscarLogUsuario(string user, string passw)
{
    system ("cls");
    fstream file;
    int found=0;
    file.open("Usuario.txt", ios::in);
    if (!file)
    {
        cout<<"\n---------------------------Datos del Usuario buscado----------------------"<<endl;
        cout<<"\n\t\t\tNo hay informacion del usuario...";
    }
    else
    {
        file >> nombreU >> Password;
        while(!file.eof())
        {
            if(user==nombreU)
            {
                if (passw == Password)
                {
                    found++;
                }
            }
            file >> nombreU >> Password;
        }
        if(found==0)
        {
            return false;
        }
        else
            return true;

        file.close();}
}

string Usuario::getnombreU()
{
    return nombreU;
}
