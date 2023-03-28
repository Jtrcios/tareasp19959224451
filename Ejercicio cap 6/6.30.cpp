#include <iostream>
using namespace std;

int invertir(int);

int main()
{
	int a,b;
	cout << "Ingrese un numero:" << "\n";
	cin >> a;
	b = invertir (a);
	cout << "El numero invertido es: " << b;
	return 0;
}

int invertir (int numero){
	int resultado = 0;
	while (numero > 0)
	{
		resultado = resultado * 10;
		resultado = resultado + numero % 10;
		numero = numero / 10;
	}
	return resultado;
}