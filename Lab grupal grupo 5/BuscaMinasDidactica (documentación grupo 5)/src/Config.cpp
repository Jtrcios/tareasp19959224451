#include <iostream>
#include <unistd.h>
#include "Config.h"
using namespace std;

Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero)
{
    this->filasTablero = filasTablero;
    this->columnasTablero = columnasTablero;
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    this->vidasTablero = vidasTablero;
}
void Config::menuConfiguracion()
{
    int opciones;
    int valorIngresado;
    bool repetir = true;
    do
    { //Esta parte se encarga de generar la estructura del menu de configuración
        system("cls"); //Permite al jugador seleccionar una opción a configurar
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl;
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl;
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero() << endl;
        cout << "\t\t4. Modo del Juego -------> " << this->getmodoDesarrolladorTablero() << endl;
        cout << "\t\t5. Vidas del Jugador ----> " << this->getvidasTablero() << endl;
        cout << "\t\t6. Regresar al menu general" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        if (opciones!=6)
        { 
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
        }
        switch (opciones)
        {
        case 1: //Permite cambiar el numero de filas del tablero
            {
                this->setfilasTablero(valorIngresado);
                cout << "Filas del Tablero actualizadas" << endl;
                break;
            }
        case 2: //Permite cambiar el numero de columnas del tablero
            {
                this->setcolumnasTablero(valorIngresado);
                cout << "Columnas del Tablero actualizadas" << endl;
                break;
            }
        case 3: //Permite cambiar las minas generadas en el tablero
            {
                this->setminasTablero(valorIngresado);
                cout << "Minas del Tablero actualizadas" << endl;
                break;
            }
        case 4: //Esta parte permite cambiar el modo de juego actual
            {
                this->setmodoDesarrolladorTablero(valorIngresado);
                cout << "Modo del Juego actualizado" << endl;
                break;
            }
        case 5: //Esta parte permite actualizar la cantidad de vidas en el juego
            {
                this->setvidasTablero(valorIngresado);
                cout << "Vidas del Juego actualizadas" << endl;
                break;
            }
        case 6: repetir = false; // Este caso hace que se regrese al menu principal del juego
                break;
        }
        system("pause");
    } while (repetir);
}
int Config::getfilasTablero() //Este apartado almacena elvalor de las filas del tablero
{
    return this->filasTablero;
}
int Config::setfilasTablero(int filasTablero) //Este apartado regresa el valor de las filas del tablero
{
    this->filasTablero=filasTablero;
}
int Config::getcolumnasTablero() //Este apartado almacena el valor de las columnas del tablero
{
    return this->columnasTablero;
}
int Config::setcolumnasTablero(int columnasTablero) //Este apartado regresa el valor de las columnas del tablero
{
    this->columnasTablero=columnasTablero;
}
int Config::getminasTablero() //Este apartado almacena el valor de las minas generadas en el tablero
{
    return this->minasTablero;
}
int Config::setminasTablero(int minasTablero) //Este apartado devuelve el valor de las minas generadas en el tablero
{
    this->minasTablero=minasTablero;
}
bool Config::getmodoDesarrolladorTablero() // Esta clase almacena el valor de opción del modo desarrollador
{
    return this->modoDesarrolladorTablero;
}
bool Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero) // Esta clase devuelve el valor de opción del modo desarrollador si este esta activo o no
{
    this->modoDesarrolladorTablero=modoDesarrolladorTablero;
}
int Config::getvidasTablero() // Esta clase almacena el valor de opción de las vidas del jugador
{
    return this->vidasTablero;
}
int Config::setvidasTablero(int vidasTablero) // Esta clase devuelve el valor de opción de las vidas del jugador
{
    this->vidasTablero=vidasTablero;
}


