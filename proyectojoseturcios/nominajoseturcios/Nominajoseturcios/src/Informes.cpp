#include "Informes.h"
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Puestos.h"

using namespace std;

void Informes::menuInformes()
{
system("cls");
    fstream file;
	int found=0;
	file.open("Puestos.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Puesto Buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		double participant_id;
		cout<<"\n-------------------------Datos del Puesto Buscado------------------------"<<endl;
		cout<<"\nIngrese Id del Puesto que quiere buscar: "<<endl;
		cin>>participant_id;
		cout<<"\n"<<endl;
		file >> idPuesto >> nombrePuesto >> encargadoPuesto >> tituloPuesto >> salarioPuesto;
		while(!file.eof())
		{
			if(participant_id==idPuesto)
			{
				cout<<"\t\t\t Id Puesto        : "<<idPuesto<<endl;
                cout<<"\t\t\t Nombre Puesto        : "<<nombrePuesto<<endl;
                cout<<"\t\t\t Encargado Puesto         : "<<encargadoPuesto<<endl;
                cout<<"\t\t\t Profesion del Encargado  : "<<tituloPuesto<<endl;
                cout<<"\t\t\t Salario del Puesto       : "<<salarioPuesto<<endl;
				found++;
			}
			file >> idPuesto >> nombrePuesto >> encargadoPuesto >> tituloPuesto >> salarioPuesto;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Puesto no encontrada...";
		}
		file.close();
	}
	file.open("valores.txt",ios::in);
    file >> porcentajeigss >>porcentajeIsr >> porcentajeSeguro;
    {
    totalIgss = (salarioPuesto * porcentajeigss);
    cout <<"\t\t\t\tTotal IGSS: "<< totalIgss<<endl;
    totalIsr = (salarioPuesto * porcentajeIsr);
    cout <<"\t\t\t\tTotal ISR: " << totalIsr << endl;
    totalSeguro = (salarioPuesto * porcentajeSeguro);
    cout <<"\t\t\t\tTotal seguro: " << totalSeguro<<endl;
    totalDescuentos = totalIgss + totalIsr + totalSeguro;
    cout <<"\t\t\t\tTotal descuentos: "<<totalDescuentos<<endl;
    cout<<"\n"<<endl;
    file.close();
	}
	file.open("HorasExtra.txt",ios::in);
    file >> salarioDiario >> valorHoraNormal >> valorHoraExtra>> horasTrabajadas;
    {
    cout <<"\t\t\t\tPago por Horas Extra: "<<horasTrabajadas<<endl;
    file.close();
	}
	file.open("HorasExtra.txt",ios::in);
    file >> bonificacion;
    {
        totalSueldo = (salarioPuesto - totalDescuentos) + totalHoras + bonificacion;
        cout <<"\n\t\t\t Total a pagarle es: " << totalSueldo <<endl;
    file.close();
	}
	system("cls");
	system("pause");
}
