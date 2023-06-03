#include "UsuarioPlanilla.h"
using namespace std;

string nombreUsuario, contra;
Menus llamarMenu;
Bitacora enviarDatosU;

void UsuarioPlanilla::inicioSesion()
{
    system("cls");
	fstream file, file1;
	int found=0;
	file.open("Usuario.txt",ios::in);
    cout<<"\t\t--------------------------"<<endl;
    cout<<"\t\tAutenticacion de usuarios "<<endl;
    cout<<"\t\t--------------------------\n"<<endl;
    cout<<"\t\tNombre del usuario: ";
    cin>>nombreUsuario;
    cout << "\t\tContrasena del usuario: ";
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
            llamarMenu.menuI(nombreUsuario);
            return;
            found++;
            enviarDatosU.ingresoDatosBi(nombreUsuario,"7000", "LOG");
        }
        file >> nombre >> contrasena;
    }
    if(found==0)
    {
       enviarDatosU.ingresoDatosBi(nombreUsuario,"7010", "NLOG");
        cout<<"\n\t\t\t El usuario o la contrasena sin incorrectos, intente de nuevo o comuniquese con administracion..." << endl;
        system("pause");
    }
    file.close();
}
string UsuarioPlanilla::menuU(string nombreUsuario)
{
    string userName = nombreUsuario;
    char x;
    int opcion;
	do
    {
	system("cls");
	cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|                  !Bienvenido " << userName << "!                  |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t---------------------------------------------\n";
	cout<<"\t\t\t |              Catalogo de Usuarios              |"<<endl;
	cout<<"\t\t\t---------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Imprimir Usuarios"<<endl;
	cout<<"\t\t\t 2. Modificar Usuario"<<endl;
	cout<<"\t\t\t 3. Buscar Usuario"<<endl;
	cout<<"\t\t\t 4. Borrar Usuarios"<<endl;
	cout<<"\t\t\t 5. Regresar"<<endl;
	cout<<"\t\t\t------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1]-[2]-[3]-[4]-[5]"<<endl;
	cout<<"\t\t\t------------------------------------"<<endl;
	cout<<"\t\t\tIngresa la Opcion: ";
    cin>>opcion;
        switch(opcion)
        {
        case 1:
                imprUsuario();
            enviarDatosU.ingresoDatosBi(userName,"7400","IMP");
            break;
        case 2:
            modUsuario();
            enviarDatosU.ingresoDatosBi(userName,"7410","MOD");
            break;
        case 3:
            buscarU();
            enviarDatosU.ingresoDatosBi(userName,"7420","SRC");
            break;
        case 4:
            borrarU();
            enviarDatosU.ingresoDatosBi(userName,"7430","DEL");
            break;
        case 5:
            llamarMenu.subMenuInf(userName);
            break;
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor intente de nuevo..";
            system ("pause");
            break;
        }
    }while(opcion!=5);
}
void UsuarioPlanilla::registroU()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------- Ingresar Nuevo Usuario -----------------------------------------------"<<endl;
	cout<<"\n\t\t\tIngresa el nombre de Usuario: ";
	cin>>nombre;
	cout<<"\t\t\tIngresa la contrasena del usuario: ";
	cin>>contrasena;
	file.open("Usuario.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
	file.close();
}
void UsuarioPlanilla::modUsuario()
{
	system("cls");
	fstream file,file1;
	string name, c2;
	int found=0, opcion;
	cout<<"\n-------------------------Modificacion Detalles Usuario-------------------------"<<endl;
	file.open("Usuario.txt",ios::in);
	cout<<"\n Ingrese su nombre de usuario: ";
    cin>>name;
    cout<<" Ingrese su contrasena: ";
    cin>>c2;
    file1.open("Record.txt",ios::app | ios::out);
    file >> nombre >> contrasena;
    while(!file.eof())
    {
        if(name!=nombre && c2!=contrasena){
         file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
        }
        else{
            cout << "\n\tIngrese el caracter a modificar" << endl;
            cout << "\t1. Usuario" << endl;
            cout << "\t2. Contrasena" << endl;
            cout << "\tIngrese una opcion" << endl;
            cin >> opcion;
            if (opcion == 1){
                cout<<"\n Ingrese el nombre de usuario: ";
                cin>>nombre;
                file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
                nombreUsuario = nombre;
                found++;
            }
            else{
                if (opcion == 2){
                    cout<<" Ingrese la contrasena de usuario: ";
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
        cout<<"\n\t\t\t el usuario no ha sido encontrado...";
    }
    file1.close();
    file.close();
    remove("Usuario.txt");
    rename("Record.txt","Usuario.txt");
}
void UsuarioPlanilla::imprUsuario()
{
    system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Usuarios -------------------------"<<endl;
	file.open("Usuario.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
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
void UsuarioPlanilla::buscarU()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("Usuario.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del usuario buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del usuario buscado------------------------"<<endl;
		cout<<"\nIngrese el nombre del usuario que desea buscar: ";
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
void UsuarioPlanilla::borrarU()
{
	system("cls");
	fstream file,file1;
	string name, c2;
	int found=0;
	cout<<"\n------------------------- Borrar Usuario -------------------------"<<endl;
	file.open("Usuario.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el nombre del usuario a borrar: ";
		cin>>name;
		cout<<" Ingrese la contrasena del usuario a borrar: ";
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
				cout << "\n\t\t\tEl usuario se ha borrado con exito";
			}
			file >> nombre >> contrasena;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t el usuario no ha sido encontrado...";
		}
		file1.close();
		file.close();
		remove("Usuario.txt");
		rename("Record.txt","Usuario.txt");
		exit(0);
	}
}

void UsuarioPlanilla::Portada(string nombreArchivo)
	{
        string line;
        //char userInput = ' ';
        ifstream myFile(nombreArchivo);
        if(myFile.is_open())
        {
            //Se obtiene la portada del juego
            while( getline(myFile, line))
            {
                cout << line << endl;
            }
            myFile.close();
            system("pause");
        }
        else
        {
            cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
            system("pause");
        }
}
