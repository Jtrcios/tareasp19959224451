// Ejercicio 6.43: ej06_43.cpp
// ¿Qué error tiene este programa?
#include <iostream>
using namespace std;

int main()
{
int c = 0;
 
if ( ( c = cin.get() ) != EOF ) 
{
main();
cout << c;
} // fin de if
} // fin

// El programa no previene la recursividad infinita