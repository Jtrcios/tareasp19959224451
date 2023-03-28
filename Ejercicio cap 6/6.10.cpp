#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159;

inline double volesfera( const double radio ) 
{ 
return 4 / 3 * PI * pow( radio, 3 ); 
}
 int main()
{
double radio = 0;

cout << "Escriba el radio de su esfera: ";
cin >> radio;

cout << "El volumen de la esfera con radio " << radio 
<< " es " << volesfera( radio ) << endl;
}