#include <iostream>
#include <stdio.h>

using namespace std;

int sum(int a, int b)
{
    return a + b;
}
int rest(int a, int b)
{
	return a - b;
}
int mult(int a, int b)
{
	return a * b;
}
int divi(int a, int b)
{
	return a / b;
}

int main()
{
	int x, y, z, n=4;
	cout << "Bienvenido" << "\n";
	cout << "Ingrese una opcion "<< "\n";
	cout << "1. Suma" << "\n";
	cout << "2. Resta" << "\n";
	cout << "3. Multiplicacion" << "\n";
	cout << "4. Division" << "\n";
	cin >> n;
	switch (n){
	case 1:{
		cout << "Suma" << "\n";
			cout << "Ingrese dos numeros"<< "\n";
			cin >> x;
			cin >> y;
			int z = sum(x, y);
			cout << "El resultado es: " << z << endl;
	}break;
    case 2:
    {
    	cout << "Resta" << "\n";
			cout << "Ingrese dos numeros"<< "\n";
			cin >> x;
			cin >> y;
			int v = rest(x, y);
			cout << "El resultado es: " << v << endl;
    }break;
    case 3:
    {
    	cout << "Multiplicacion" << "\n";
			cout << "Ingrese dos numeros"<< "\n";
			cin >> x;
			cin >> y;
			int l = mult(x, y);
			cout << "El resultado es: " << l << endl;
    }break;
    case 4:
    {
    	cout << "Division" << "\n";
			cout << "Ingrese dos numeros"<< "\n";
			cin >> x;
			cin >> y;
			int r = divi(x, y);
			cout << "El resultado es: " << r << endl;
    }break;
    default:{
    	cout << "Opcion invalida" << "\n";
	}break;
	}
	return 0;
}