#include <iostream>
#include <stdio.h>

using namespace std;

main()
{
	int a, b, c, n=4;
	cout << "Bienvenido" << "\n";
	cout << "Ingrese una opcion "<< "\n";
	cout << "1. Suma" << "\n";
	cout << "2. Resta" << "\n";
	cout << "3. Multiplicacion" << "\n";
	cout << "4. Division" << "\n";
	cin >> n;
	switch (n){
		case 1:
			cout << "Suma" << "\n";
			cout << "Ingrese dos numeros"<< "\n";
			cin >> a;
			cin >> b;
			c = a+b;
		break;
		case 2:
			cout << "Resta" << "\n";
			cout << "Ingrese dos numeros"<< "\n";
			cin >> a;
			cin >> b;
			c = a-b;
		break;
		case 3:
			cout << "Multiplicacion" << "\n";
			cout << "Ingrese dos numeros"<< "\n";
			cin >> a;
			cin >> b;
			c = a*b;
		break;
		case 4:
			cout << "Division" << "\n";
			cout << "Ingrese dos numeros"<< "\n";
			cin >> a;
			cin >> b;
			c = a/b;
		break;
		default:
			cout << "Opcion invalida" << "\n";
		break;
	}
	cout << "El resultado es: "<< c << "\n";
	return 0;
}