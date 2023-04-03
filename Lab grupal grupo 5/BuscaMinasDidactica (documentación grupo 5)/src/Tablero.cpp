#include "Tablero.h"
#include <sstream>
#include <iostream>

using namespace std;

Tablero::Tablero() //Genera la clase tablero
{
}
Tablero::Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador) //Declara los elementos de la clase tablero
{
    this->alturaTablero = alturaTablero;
    this->anchoTablero = anchoTablero;
    this->modoDesarrollador = modoDesarrollador;
    int x, y;
    for (y=0; y < this->alturaTablero; y++)
    {
        vector<Celda> fila;
        for (x=0; x < this->anchoTablero; x++)
        {
            fila.push_back((Celda(x, y, false)));
        }
        this->contenidoTablero.push_back(fila);
    }
}
int Tablero::getAlturaTablero() // Esta clase registra el valor de la altura del tablero
{
    return this->alturaTablero;
}
int Tablero::setAlturaTablero(int alturaTablero) // Esta clase devuelve el valor de la altura del tablero
{
    this->alturaTablero = alturaTablero;
}
int Tablero::getAnchoTablero() // Esta clase registra el valor del ancho del tablero
{
    return this->anchoTablero;
}
int Tablero::setAnchoTablero(int anchoTablero) // Esta clase devuelve el valor del ancho del tablero
{
    this->anchoTablero = anchoTablero;
}
bool Tablero::getModoDesarrollador() // Esta clase registra el valor del modo desarrollador
{
    return this->modoDesarrollador;
}
bool Tablero::setModoDesarrollador(bool modoDesarrollador) // Esta clase devuelve el valor del modo desarrollador
{
    this->modoDesarrollador = modoDesarrollador;
}
string Tablero::getRepresentacionMina(int coordenadaX, int coordenadaY)
{
    Celda celdaTemporal = this->contenidoTablero.at(coordenadaY).at(coordenadaX);
    if (celdaTemporal.getMinaDescubierta() || this->modoDesarrollador)
    {
        if (celdaTemporal.getMina())
        {
            return "*";
        }
        else
        {
            int cantidadCelda=this->minasCercanas(coordenadaY,coordenadaX);
            string cantidadCeldaString = " ";
            stringstream ss;
            ss << cantidadCelda;
            ss >> cantidadCeldaString;
            return cantidadCeldaString;
        }
    }
    else
    {
        return "?";
        //return ".";
    }
}
int Tablero::minasCercanas(int filaTablero, int columnaTablero) //Se encarga de imprimir los numeros de minas cercanas al jugador
{
        int contadorTablero = 0;
        int filaInicioTablero, filaFinTablero, columnaInicioTablero, columnaFinTablero;
        if (filaTablero <= 0)
		{
			filaInicioTablero = 0;
		}
		else
		{
			filaInicioTablero = filaTablero - 1;
		}

		if (filaTablero + 1 >= this->alturaTablero)
		{
			filaFinTablero = this->alturaTablero - 1;
		}
		else
		{
			filaFinTablero = filaTablero + 1;
		}

		if (columnaTablero <= 0)
		{
			columnaInicioTablero = 0;
		}
		else
		{
			columnaInicioTablero = columnaTablero - 1;
		}
		if (columnaTablero + 1 >= this->anchoTablero)
		{
			columnaFinTablero = this->anchoTablero - 1;
		}
		else
		{
			columnaFinTablero = columnaTablero + 1;
		}
		int m;
		for (m = filaInicioTablero; m <= filaFinTablero; m++)
		{
			int l;
			for (l = columnaInicioTablero; l <= columnaFinTablero; l++)
			{
				if (this->contenidoTablero.at(m).at(l).getMina())
				{
					contadorTablero++;
				}
			}
		}
		return contadorTablero;
}
void Tablero::imprimirSeparadorEncabezado() //Se encarga de imprimir el separador del encabezado
	{
		int m;
		for (m = 0; m <= this->anchoTablero; m++)
		{
			cout << "----";
			if (m + 2 == this->anchoTablero)
			{
				cout << "-";
			}
		}
		cout << "\n";
	}

	void Tablero::imprimirSeparadorFilas() //Se encarga de separar las filas del tablero
	{
		int m;
		for (m = 0; m <= this->anchoTablero; m++)
		{
			if (m <= 1)
			{
				cout << "|---";
			}
			else
			{
				cout << "+---";
			}
			if (m == this->anchoTablero)
			{
				cout << "+";
			}
		}
		cout << "\n";
	}

	void Tablero::imprimirEncabezado() //Se encarga de la construcción del encabezado del tablero
	{
		this->imprimirSeparadorEncabezado();
		cout << "|   ";
		int l;
		for (l = 0; l < this->anchoTablero; l++)
		{
			cout << "| " << l + 1 << " ";
			if (l + 1 == this->anchoTablero)
			{
				cout << "|";
			}
		}
		cout << "\n";
	}

	void Tablero::imprimir() //Se encarga de la construcción de la estructura del tablero
	{
		this->imprimirEncabezado();
		this->imprimirSeparadorEncabezado();
		int x, y;
		for (y = 0; y < this->alturaTablero; y++)
		{
			cout << "| " << y + 1 << " ";
			for (x = 0; x < this->anchoTablero; x++)
			{
				cout << "| " << this->getRepresentacionMina(x, y) << " ";
				if (x + 1 == this->anchoTablero)
				{
					cout << "|";
				}
			}
			cout << "\n";
			this->imprimirSeparadorFilas();
		}
	}
    bool Tablero::colocarMina(int x, int y) // Se encarga de la mina o minas colocadas en el tablero
	{
		return this->contenidoTablero.at(y).at(x).setMina(true);
	}
    bool Tablero::descubrirMina(int x, int y) // Se encarga de la mina descubierta en el tablero
	{
		this->contenidoTablero.at(y).at(x).setMinaDescubierta(true);
		Celda celda = this->contenidoTablero.at(y).at(x);
		if (celda.getMina())
		{
			return false;
		}
		return true;
	}
	int Tablero::contarCeldasSinMinasYSinDescubrir() //Se encarga de contar las celdas sin minas / con minas sin descubrir
	{
		int x, y, contador = 0;
		for (y = 0; y < this->alturaTablero; y++)
		{
			for (x = 0; x < this->anchoTablero; x++)
			{
				Celda celdaTemporal = this->contenidoTablero.at(y).at(x);
				if (!celdaTemporal.getMinaDescubierta() && !celdaTemporal.getMina())
				{
					contador++;
				}
			}
		}
		return contador;
	}
