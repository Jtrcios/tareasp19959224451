#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

class Juego
{
private:
	Tablero tablero;
	int cantidadMinas; //Esta variable de tipo int se encarga de la cantidad de minas a generar

	int aleatorio_en_rango(int minimo, int maximo); //Esta variable int es asignada al rango de numeros aleatorios
	int filaAleatoria(); //Esta variable de tipo int se encarga de la cantidad de minas a generar en las filas
	int columnaAleatoria(); //Esta variable de tipo int se encarga de la cantidad de minas a generar en las columnas
public: // Esta se encarga de las variables y minas sobre el tablero, iniciar el juego y de registrar la selección del cuadro seleccionado por el jugador.
	Juego(Tablero tablero, int cantidadMinas); 
	void colocarMinasAleatoriamente(); // Esta variable no devuelve ningún valor, pero se asigna a la generación aleatoria de minas
	int solicitarFilaUsuario(); //Esta variable es asignada al valor de la fila
	int solicitarColumnaUsuario(); //Esta variable es asignada al valor de la columna
	bool jugadorGana(); // Esta variable se encarga de describir si el jugador gana o pierde
	void iniciar(); // Esta variable no devuelve ningún valor, pero se encarga de detectar si el juego se esta ejecutando
};

#endif // JUEGO_H
