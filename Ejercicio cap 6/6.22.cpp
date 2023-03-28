#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n;
	char c[30];
	cout << "Ingrese algun caracter: "<< "\n";
	cin >> c;
	cout << "Ingrese el tamano del cuadrado:" << "\n";
	cin >> n;
	
	for (int reg=1; reg<=n; reg++)
	{
		for(int col=1; col<=n; col++)
		{
			if (reg == 1 || reg == n || col == 1 || col == n)
			{
				cout << c;
			}
			else
			{
				cout << c;
			}
		}
		cout << "\n";
	}
	return 0;
}