#include <iostream>
#include <stdio.h>

using namespace std;

int totalHT, totalGT, acts;
int parcial1, parcial2, parcs;
int exfinal, proyfinal, labfinal, evfinal;
int zona, evalfinal, NotaC;

main()
{
	cout<<"\n\nINGRESO DE INFORMACION ACADEMICA";
		
	cout<<"\nHojas de trabajo: ";
	cin>>totalHT;
	
	cout<<"\nGuias de Trabajo (Labs Parciales): ";
	cin>>totalGT;
	
	acts=totalHT+totalGT;
	
	cout<<"\nParcial #1: ";
	cin>>parcial1;
	cout<<"\nParcial #2: ";
	cin>>parcial2;	
	parcs=parcial1+parcial2;
	zona=acts+parcs;
	if (zona>=26)
	{
		cout<<"\nExamen Final: ";
		cin>>exfinal;	
		cout<<"\nPoyecto final: ";
		cin>>proyfinal;
		cout<<"\nLaboratorio final: ";
		cin>>labfinal;	
		evalfinal=exfinal+proyfinal+labfinal;
		NotaC=zona+evalfinal;
		if (NotaC>=61)
		{
			cout<<"\n Curso Aprobado";
		}
		else
		{
			cout<<"\n Curso No Aprobado";
		}
	}
	else
	{
		cout<<"\nSDEF";
	}
	cout<<"\n\nRESULTADOS";
	cout<<"\nZONA: "<<zona;
	cout<<"\nPARCIALES: "<<parcs;
	cout<<"\nACTIVIDADES: "<<acts;
	cout<<"\nNOTA CURSO: "<<NotaC;
	return 0;
}