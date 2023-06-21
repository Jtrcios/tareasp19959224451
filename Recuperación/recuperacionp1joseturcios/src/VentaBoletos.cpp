#include "VentaBoletos.h"

Bitacora llamarBitacora;

void VentaBoletos::VentaBoletosOp(string nombreUsuario)
{
    string userName = nombreUsuario;
    llamarBitacora.ingresoDatosBit(userName,"7500","VENTA");
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------- Ingresar Nuevo Cliente -----------------------------------------------"<<endl;
	cout<<"\n\t\t\tIngresa el nombre del cliente: ";
	cin>>nombreCliente;
	cout<<"\n\t\t\tIngresa el Nombre de la pelicula: ";
	cin>>nombrePeli;
	cout<<"\t\t\tIngresa el Precio de la Pelicula: ";
	cin>>precPeli;
	cout<<"\t\t\tIngresa la hora de la Pelicula: ";
	cin>>horaPeli;
	cout<<"\t\t\tIngresa el Numero de boletos a comprar: ";
	cin>>numBoletos;
	cout<<"\t\t\tIngresa el Numero de Total a pagar: ";
	cin>>totalBoletos;
	file.open("VentaBoletos.txt", ios::app | ios::out | ios::binary);
	file<<std::left<<std::setw(15)<< nombreCliente <<std::left<<std::setw(15)<< nombrePeli <<std::left<<std::setw(15)<< precPeli <<std::left<<std::setw(15)<< horaPeli <<std::left<<std::setw(15)<< numBoletos <<std::left<<std::setw(15)<< totalBoletos    << "\n";
	file.close();
}

void VentaBoletos::VentaBoletosTotal(string nombreUsuario){
    system("cls");
    fstream file;
    string texto;
	int total=0;
	cout<<"\n------------------------- Imprimir Informe de Totales -------------------------"<<endl;
	file.open("VentaBoletos.txt",ios::in);
    while(!file.eof())
    {
        total++;
        getline(file,texto);
        cout<<texto<<endl;
    }
    if(total==0)
    {
        cout<<"\n\t\t\tNo hay informacion...";
    }
    file.close();
	getch();
	system("pause");
}
