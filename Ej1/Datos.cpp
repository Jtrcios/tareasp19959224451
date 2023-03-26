#include <iostream>
#include "proceso.h"
using namespace std;
void Numero::Leer(void){
	cout<<"De un numero"<<endl;
	cin>>x;
	cout<<"De otro numero"<<endl;
	cin>>y;
}

void Numero::Operar(void){
	r=0;
	r=x+y;
}

void Numero::Imprimir(void){
	cout<<x<<"+"<<y<<"es ="<<r<<endl;
}