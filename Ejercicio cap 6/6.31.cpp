#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int num1, num2, a, b, res;
	cout << "Ingrese el primer numero: "<< "\n";
	cin >> num1;
	cout << "Ingrese el segundo numero: "<< "\n";
	cin >> num2;
	a = std::max(num1,num2);
	b = std::min(num1,num2);
	do
	{
		res=b;
		b=a%b;
		a=res;
	} while (b!=0);
	cout << "El mcd entre: " << num1 << " y " << num2 << " es: " << res;
	return 0;
}