#include<iostream>
using namespace std;
int main() {
    int horas, minutos, segundos;
    cout << "04. MUESTRA LAS HORAS Y MINUTOS EN UN TOTAL DE SEGUNDOS.\n\n";	        	
    cout << "Ingrese Cantidad en Segundos : ";
    cin >> segundos;
    horas = (segundos/3600);
    minutos = (segundos/60);
    cout << "Horas : " << horas << endl;
    cout << "Minutos : " << minutos << endl;
    return 0;
}