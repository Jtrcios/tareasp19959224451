#include "Usuario.h"
using namespace std;

const string ADMINUSER = "Trcs";
const string ADMINCONTRA = "23092002";
string nombreUsuario, contra;
Menus llamarMenu;
Bitacora enviarDatosU;

void Usuario::inicioSesion()
{
    system("cls");
	fstream file, file1;
	int found=0;
	file.open("Usuario.txt",ios::in);
    cout<<"\t\t--------------------------"<<endl;
    cout<<"\t\tAutenticación de usuarios "<<endl;
    cout<<"\t\t--------------------------\n"<<endl;
    cout<<"\t\tUsuario: ";
    cin>>nombreUsuario;
    cout << "\t\tContrasena: ";
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
    file >> nombre >> contrasena;
    while(!file.eof())
    {
        if(nombreUsuario == nombre && contra == contrasena)
        {
            enviarDatosU.ingresoDatosBit(nombreUsuario,"7000","LOGIN");
            llamarMenu.menuInicial(nombreUsuario);
            return;
            found++;

        }
                else
        {
            if (nombreUsuario ==ADMINUSER && contra ==ADMINCONTRA)
            {
                enviarDatosU.ingresoDatosBit(nombreUsuario,"7000","LOGIN");
                llamarMenu.menuInicial(nombreUsuario);
                return;
                found++;
            }
        }
        file >> nombre >> contrasena;

    }
    if(found==0)
    {
       enviarDatosU.ingresoDatosBit(nombreUsuario,"7010", "NLOG");
        cout<<"\n\t\t\t El usuario o contrase�a sin incorrectos..." << endl;
        system("pause");
    }
    file.close();
}
void Usuario::menuU(string nombreUsuario)
{
    string userName = nombreUsuario;
    char x;
    int opcion;
	do
    {
	system("cls");
    cout << "\n\t\t\t---------------------------------------------\n";
	cout<<"\t\t\t |              Catalogo de Usuarios              |"<<endl;
	cout<<"\t\t\t---------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Imprimir Usuarios"<<endl;
	cout<<"\t\t\t 2. Modificar Usuario"<<endl;
	cout<<"\t\t\t 3. Buscar Usuario"<<endl;
	cout<<"\t\t\t 4. Borrar Usuarios"<<endl;
	cout<<"\t\t\t 5. Regresar"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngrese no. Opcion: ";
    cin>>opcion;
        switch(opcion)
        {
        case 1:
                imprimirUsuario(userName);

            break;
        case 2:
            modificarUsuario(userName);

            break;
        case 3:
            buscarUsuario(userName);

            break;
        case 4:
            borrarUsuario(userName);

            break;
        case 5:
            llamarMenu.subMenuInformes(userName);
            break;
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            system ("pause");
            break;
        }
    }while(opcion!=5);
}
void Usuario::registroU()
{

	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------- Ingresar Nuevo Usuario -----------------------------------------------"<<endl;
	cout<<"\n\t\t\tIngresa el nombre de Usuario: ";
	cin>>nombre;
	cout<<"\t\t\tIngresa la contrasena: ";
	cin>>contrasena;
	file.open("Usuario.txt", ios::app | ios::out | ios::binary);
	file<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
	file.close();
}
void Usuario::modificarUsuario(string nombreUsuario)
{
    string userName = nombreUsuario;
                enviarDatosU.ingresoDatosBit(userName,"7410","MOD");
	system("cls");
	fstream file,file1;
	string name, c2;
	int found=0, opcion;
	cout<<"\n-------------------------Modificacion Detalles Usuario-------------------------"<<endl;
	file.open("Usuario.txt",ios::in);
	cout<<"\n Ingrese su nombre de usuario: ";
    cin>>name;
    cout<<" Ingrese la contrase�a: ";
    cin>>c2;
    file1.open("Record.txt",ios::app | ios::out);
    file >> nombre >> contrasena;
    while(!file.eof())
    {
        if(name!=nombre && c2!=contrasena){
         file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
        }
        else{
            cout << "\n\tQue desea modificar?" << endl;
            cout << "\t1. Usuario" << endl;
            cout << "\t2. Contrase�a" << endl;
            cout << "\tIngrese una opcion" << endl;
            cin >> opcion;
            if (opcion == 1){
                cout<<"\n Ingrese su nombre de usuario: ";
                cin>>nombre;
                file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
                nombreUsuario = nombre;
                found++;
            }
            else{
                if (opcion == 2){
                    cout<<" Ingrese la contrasena: ";
                    cin>>contrasena;
                    contra = contrasena;
                }
            file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
            found++;
            }
        }
        file >> nombre >> contrasena;
    }
    if(found==0)
    {
        cout<<"\n\t\t\t Usuario no encontrado...";
    }
    file1.close();
    file.close();
    remove("Usuario.txt");
    rename("Record.txt","Usuario.txt");
}
void Usuario::imprimirUsuario(string nombreUsuario)
{
    string userName = nombreUsuario;
    enviarDatosU.ingresoDatosBit(userName,"7400","IMP");
    system("cls");
	fstream file;
	int total=0;
	cout<<"\n------------------------- Detalles de Usuarios -------------------------"<<endl;
	file.open("Usuario.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tSin informacion...";
		file.close();
	}
	else
	{
		file >> nombre >> contrasena;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Nombre: "<<nombre<<endl;
			cout<<"\t\t\t Contrasena: "<<contrasena<<endl;
			file >> nombre >> contrasena;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	system("pause");
	file.close();
}
void Usuario::buscarUsuario(string nombreUsuario)
{
    string userName = nombreUsuario;
                enviarDatosU.ingresoDatosBit(userName,"7420","SRC");
	system("cls");
	fstream file;
	int found=0;
	file.open("Usuario.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del usuario buscado------------------------"<<endl;
		cout<<"\n\t\t\tSin informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del usuario buscado------------------------"<<endl;
		cout<<"\nIngrese el nombre del usuario que quiere buscar: ";
		cin>>participant_id;
		file >> nombre >> contrasena;
		while(!file.eof())
		{
			if(participant_id==nombre)
			{
				cout<<"\n\n\t\t\t Nombre: "<<nombre<<endl;
				cout<<"\t\t\t Contrasena: "<<contrasena<<endl;
				found++;
			}
			file >> nombre >> contrasena;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Usuario no encontrado...";
		}
		file.close();
	}
}
void Usuario::borrarUsuario(string nombreUsuario)
{
    string userName = nombreUsuario;
                enviarDatosU.ingresoDatosBit(userName,"7430","DEL");
	system("cls");
	fstream file,file1;
	string name, c2;
	int found=0;
	cout<<"\n------------------------- Borrar Usuario -------------------------"<<endl;
	file.open("Usuario.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tSin informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el usuario a borrar: ";
		cin>>name;
		cout<<" Ingrese la contrasena: ";
		cin>>c2;
		file1.open("Record.txt",ios::app | ios::out);
		file >> nombre >> contrasena;
		while(!file.eof())
		{
			if(name!= nombre && c2 != contrasena)
			{
				file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tUsuario borrado exitosamente";
			}
			file >> nombre >> contrasena;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Usuario no encontrado...";
		}
		file1.close();
		file.close();
		remove("Usuario.txt");
		rename("Record.txt","Usuario.txt");
		exit(0);
	}
}

void Usuario::dibujarPort(string nombreArchivo)
	{
        string line;
        ifstream myFile(nombreArchivo);
        if(myFile.is_open())
        {

            while( getline(myFile, line))
            {
                cout << line << endl;
            }
            myFile.close();
            system("pause");
        }
        else
        {
            cout << "ERROR : la portada no pudo ser cargada" << endl;
            system("pause");
        }
}
