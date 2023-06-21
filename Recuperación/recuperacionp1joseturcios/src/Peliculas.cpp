#include "Peliculas.h"

Bitacora enviarDatosP;
Menus traerMenuCat;
void Peliculas::menuPeli(string nombreUsuario)
{
    string userName = nombreUsuario;
    system("cls");
    int optEscoger;
    bool repetir = true;
    do
    {
            system("cls");
    cout << "\n\t\t\t---------------------------------\n";
    cout << "\t\t\t|          Menu de Peliculas      |";
    cout << "\n\t\t\t---------------------------------"<<endl;

    cout<<"\t\t\t 1. Registrar Peliculas"<<endl;
	cout<<"\t\t\t 2. Imprimir Peliculas"<<endl;
	cout<<"\t\t\t 3. Modificar Peliculas"<<endl;
	cout<<"\t\t\t 4. Buscar Peliculas"<<endl;
	cout<<"\t\t\t 5. Borrar Peliculas"<<endl;
	cout<<"\t\t\t 6. Regresar"<<endl;
    cout << "\n\n\t\t\t---------------------------------------";
    cout << "\n\t\t\t| Opciones a escoger: [1] - [2] - [3] - [4] - [5] - [6]";
    cout << "\n\t\t\t---------------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion que desea escoger: ";
    cin >> optEscoger;

    switch(optEscoger)
    {
    case 1:{
    registroPeli(userName);
    system("cls");

                break;
    }

    case 2:{
        system("cls");
        imprimirPeli(userName);
    break;
    }
    case 3:{
        system("cls");
        modificarPeli(userName);
        break;
        }
    case 4:
        system("cls");
       buscarPeli(userName);
        break;
    case 5:
        system("cls");
       borrarPeli(userName);
        break;
    case 6:
        system("cls");
       traerMenuCat.menuCatalogos(userName);
        break;
    default:
        cout << "Opcion invalida... Intente otra vez...";

    }
    }while(optEscoger!=6);
}
void Peliculas::registroPeli(string nombreUsuario)
{
    string userName = nombreUsuario;
    enviarDatosP.ingresoDatosBit(userName,"7200","INS");
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------- Ingresar Nuevo Peliculas -----------------------------------------------"<<endl;
	cout<<"\n\t\t\tID de la Pelicula: ";
	cin>>idPeli;
	cout<<"\n\t\t\tNombre de la Pelicula: ";
	cin>>nombrePeli;
	cout<<"\t\t\tClasificacion de la Peliculaa: ";
	cin>>clasPeli;
	cout<<"\t\t\tGenero de la Pelicula: ";
	cin>>genPeli;
	cout<<"\t\t\tSub-titulos de la Pelicula: ";
	cin>>subPeli;
	cout<<"\t\t\tIdioma de la Pelicula: ";
	cin>>idiomaPeli;
	cout<<"\t\t\tPrecio Entrada: ";
	cin>>precPeli;
	cout<<"\t\t\tIngresa la hora de entrada de la Peliculaa: ";
	cin>>horaPeli;
	file.open("Peliculas.txt", ios::app | ios::out | ios::binary);
	file<<std::left<<std::setw(15)<< idPeli <<std::left<<std::setw(15)<< nombrePeli <<std::left<<std::setw(15)<< clasPeli <<std::left<<std::setw(15)<< genPeli <<std::left<<std::setw(15)<< subPeli <<std::left<<std::setw(15)<< idiomaPeli<<std::left<<std::setw(15)<< precPeli <<std::left<<std::setw(15)<< horaPeli << "\n";
	file.close();
}

void Peliculas::modificarPeli(string nombreUsuario)
{
string userName = nombreUsuario;
enviarDatosP.ingresoDatosBit(userName,"7210","MOD");
    fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Peliculas-------------------------"<<endl;
	file.open("Peliculas.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tSin informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la pelicula a modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> idPeli >> nombrePeli >> clasPeli >> genPeli >> subPeli >> idiomaPeli >> precPeli >> horaPeli;
		while(!file.eof())
		{
			if(participant_id!=idPeli)
			{
			 file1<<std::left<<std::setw(15)<< idPeli <<std::left<<std::setw(15)<< nombrePeli <<std::left<<std::setw(15)<< clasPeli <<std::left<<std::setw(15)<< genPeli <<std::left<<std::setw(15)<< subPeli <<std::left<<std::setw(15)<< idiomaPeli<<std::left<<std::setw(15)<< precPeli <<std::left<<std::setw(15)<< horaPeli << "\n";
			}
			else
			{
					cout<<"\n\t\t\tIngresa el ID de la Pelicula: ";
                    cin>>idPeli;
                    cout<<"\n\t\t\tIngresa el Nombre de la Pelicula: ";
                    cin>>nombrePeli;
                    cout<<"\t\t\tIngresa la clasificacion de la Peliculaa: ";
                    cin>>clasPeli;
                    cout<<"\t\t\tIngresa el genero de la Pelicula: ";
                    cin>>genPeli;
                    cout<<"\t\t\tIngresa los Sub-titulos de la Pelicula: ";
                    cin>>subPeli;
                    cout<<"\t\t\tIngresa el idioma de la Pelicula: ";
                    cin>>idiomaPeli;
                    cout<<"\t\t\tIngresa el Precio de la entrada: ";
                    cin>>precPeli;
                    cout<<"\t\t\tIngresa la hora de entrada de la Peliculaa: ";
                    cin>>horaPeli;

				file1<<std::left<<std::setw(15)<< idPeli <<std::left<<std::setw(15)<< nombrePeli <<std::left<<std::setw(15)<< clasPeli <<std::left<<std::setw(15)<< genPeli <<std::left<<std::setw(15)<< subPeli <<std::left<<std::setw(15)<< idiomaPeli<<std::left<<std::setw(15)<< precPeli <<std::left<<std::setw(15)<< horaPeli << "\n";
				found++;
			}
			file >> idPeli >> nombrePeli >> clasPeli >> genPeli >> subPeli >> idiomaPeli >> precPeli >> horaPeli;
		}
		file1.close();
		file.close();
		remove("Peliculas.txt");
		rename("Record.txt","Peliculas.txt");
	}
}

void Peliculas::imprimirPeli(string nombreUsuario)
{
    string userName = nombreUsuario;
    enviarDatosP.ingresoDatosBit(userName,"7220","IMP");
    system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Detalles de la Peliculas -------------------------"<<endl;
	file.open("Peliculas.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tSin informacion...";
		file.close();
	}
	else
	{
		file >> idPeli >> nombrePeli >> clasPeli >> genPeli >> subPeli >> idiomaPeli >> precPeli >> horaPeli;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id: "<<idPeli<<endl;
			cout<<"\t\t\t Nombre: "<<nombrePeli<<endl;
			cout<<"\t\t\t Clasificacion: "<<clasPeli<<endl;
			cout<<"\n\n\t\t\t Genero: "<<genPeli<<endl;
			cout<<"\n\n\t\t\t Sub-titulos: "<<subPeli<<endl;
			cout<<"\n\n\t\t\t Idioma: "<<idiomaPeli<<endl;
			cout<<"\n\n\t\t\t Precio: "<<precPeli<<endl;
			cout<<"\n\n\t\t\t hora: "<<horaPeli<<endl;
			file >> idPeli >> nombrePeli >> clasPeli >> genPeli >> subPeli >> idiomaPeli >> precPeli >> horaPeli;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	system("pause");
	file.close();
}
void Peliculas::buscarPeli(string nombreUsuario)
{
    string userName = nombreUsuario;
    enviarDatosP.ingresoDatosBit(userName,"7230","SRC");
	system("cls");
	fstream file;
	int found=0;
	file.open("Peliculas.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de Peliculas buscadas------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos Peliculas buscadas------------------------"<<endl;
		cout<<"\nIngrese el ID de la Pelicula a buscar: ";
		cin>>participant_id;
		file >> idPeli >> nombrePeli >> clasPeli >> genPeli >> subPeli >> idiomaPeli >> precPeli >> horaPeli;
		while(!file.eof())
		{
			if(participant_id==idPeli)
			{
			    cout<<"\n\n\t\t\t Id: "<<idPeli<<endl;
			cout<<"\t\t\t Nombre: "<<nombrePeli<<endl;
			cout<<"\t\t\t Clasificacion: "<<clasPeli<<endl;
			cout<<"\n\n\t\t\t Genero: "<<genPeli<<endl;
			cout<<"\n\n\t\t\t Sub-titulos: "<<subPeli<<endl;
			cout<<"\n\n\t\t\t Idioma: "<<idiomaPeli<<endl;
			cout<<"\n\n\t\t\t Precio: "<<precPeli<<endl;
			cout<<"\n\n\t\t\t hora: "<<horaPeli<<endl;
				found++;
			}
            file >> idPeli >> nombrePeli >> clasPeli >> genPeli >> subPeli >> idiomaPeli >> precPeli >> horaPeli;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Pelicula no encontrada...";
		}
		file.close();
	}
}
void Peliculas::borrarPeli(string nombreUsuario)
{
    string userName = nombreUsuario;
                enviarDatosP.ingresoDatosBit(userName,"7240","DEL");
	system("cls");
	fstream file,file1;
	string id;
	int found=0;
	cout<<"\n------------------------- Borrar Peliculas -------------------------"<<endl;
	file.open("Peliculas.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
	    cout<<"\n Ingrese el Id para borrar: ";
		cin>>id;
		file1.open("Record.txt",ios::app | ios::out);
       file >> idPeli >> nombrePeli >> clasPeli >> genPeli >> subPeli >> idiomaPeli >> precPeli >> horaPeli;
		while(!file.eof())
		{
			if(id!= idPeli)
			{
				file1<<std::left<<std::setw(15)<< idPeli <<std::left<<std::setw(15)<< nombrePeli <<std::left<<std::setw(15)<< clasPeli <<std::left<<std::setw(15)<< genPeli <<std::left<<std::setw(15)<< subPeli <<std::left<<std::setw(15)<< idiomaPeli<<std::left<<std::setw(15)<< precPeli <<std::left<<std::setw(15)<< horaPeli << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de Usuario exitoso";
			}
			file >> idPeli >> nombrePeli >> clasPeli >> genPeli >> subPeli >> idiomaPeli >> precPeli >> horaPeli;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Usuario no encontrado...";
		}
		file1.close();
		file.close();
		remove("Peliculas.txt");
		rename("Record.txt","Peliculas.txt");
		exit(0);
	}
}
