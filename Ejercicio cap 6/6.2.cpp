// Ejercicio 6.2: ej06_02.cpp
#include <iostream>
using namespace std;

int cubo( int y ); // prototipo de función

int main()
{
int x = 0;
 
for ( x = 1; x <= 10; x++ ) // itera 10 veces
cout << cubo( x ) << endl; // calcula el cubo de x e imprime los resultados
} // fin de main

// definición de la función cubo
int cubo( int y )
{
return y * y * y;
} // fin de la función cubo