#include "Bitacora.h"


string Bitacora::ingresoDatosBit(string nombreUsuario, string numeAccion, string accionRealizada)
{
    system("cls");
	fstream file;
	file.open("Bitacora.txt", ios::app | ios::out);
    time_t now = time(0);
    fechaHoraAccion = ctime(&now);
	file <<std::left<<std::setw(15)<< nombreUsuario <<std::left<<std::setw(15)<< numeAccion <<std::left<<std::setw(15)<< accionRealizada <<std::left<<std::setw(15)<< fechaHoraAccion << "\n";
	file.close();
}


void Bitacora::imprimirDatosBit(){
    system("cls");
    fstream file;
	int total=0;
	cout<<"\n-------------------------Imprimir Informe de Bitacora -------------------------"<<endl;
	file.open("Bitacora.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion de la bitacora...";
		file.close();
	}
	else
	{
		file >> nombreUsuario >> numeAccion >> accionRealizada >> fechaHoraAccion;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Nombre del Usuario: "<<nombreUsuario<<endl;
			cout<<"\t\t\t Numero de la Accion: "<<numeAccion<<endl;
			cout<<"\t\t\t Accion Realizada: "<<accionRealizada<<endl;
			cout<<"\t\t\t Fecha y Hora de la acción: "<<fechaHoraAccion<<endl;
        file >> nombreUsuario >> numeAccion >> accionRealizada >> fechaHoraAccion ;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
	getch();
}
