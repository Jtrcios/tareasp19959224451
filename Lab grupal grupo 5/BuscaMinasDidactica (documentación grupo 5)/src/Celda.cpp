#include "Celda.h"
#include <iostream>
using namespace std;
Celda::Celda() //Esto comando genera la clase celda
{
}
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina) // Este apartado se encarga de describir los miembros de la clase celda
{
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;
    this->mina = estadoMina;
    this->minaDescubierta = false;
}
int Celda::setCoordenadaX(int coordenadaX) // Este apartado se encarga de almacenar las coordenadas x de la celda
{
    this->coordenadaX = coordenadaX;
}
int Celda::getCoordenadaX() //Regresa el valor de las coordenas x
{
    return this->coordenadaX;
}
int Celda::setCoordenadaY(int coordenadaY) // Este apartado se encarga de almacenar las coordenadas y de la celda
{
    this->coordenadaY = coordenadaY; y
}
int Celda::getCoordenadaY() //Regresa el valor de las coordenas y
{
    return this->coordenadaY;
}
bool Celda::setMina(bool estadoMina) // Este apartado se encarga de almacenar el estado de las minas si el jugador descubre una mina o no
{
    if (this->getMina())
    {
        return false;
    }
    else{
        this->mina = estadoMina;
        return true;
    }
}
bool Celda::getMina() // Este apartado se encarga de devolver el valor de las minas
{
    return this->mina;
}
bool Celda::setMinaDescubierta(bool minaDescubierta) // Este apartado se encarga de almacenar el estado de las minas descubiertas
{
    this->minaDescubierta = minaDescubierta;
}
bool Celda::getMinaDescubierta() // Este apartado se encarga de devolver el estado de las minas descubiertas
{
    return this->minaDescubierta;
}
void Celda::imprimirCelda() // Esta parte imprime un texto en el programa
{
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << " con mina? " << this->mina << "\n";
}


