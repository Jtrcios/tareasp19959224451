#include <iostream>

using namespace std;

float potencia(float base, int exp);
int main()
{
float base, exp;
float res;
cout << "Introduce la base de la potencia\n";
cin >> base;
cout << "Expontente:\n";
cin >> exp;
 res=potencia(base,exp);

cout << "La potencia de " << base << " ^ " << exp << "es " << res;

 return 1;
}
float potencia(float base, int exp)
{
 float res;
if (exp == 0)
 res=1.0;
else if (exp > 0)
 {

res=base * potencia(base,exp - 1);
 }
else if (exp < 0)
 {

res= 1.0 / base *potencia(base,exp + 1);

 }
 return res;
} 