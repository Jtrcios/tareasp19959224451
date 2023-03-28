#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "Ingrese el primer numero:" << "\n";
	cin >> num1;
	cout << "Ingrese el segundo numero:" << "\n";
	cin >> num2;
	if (num1 % num2 ==0)
	{
		cout << num1 << "Es multiplo de " << num2 << "\n";
	}
	else 
	{
	 cout << num1 << " No es multiplo de " << num2 << "\n";	
	}
}