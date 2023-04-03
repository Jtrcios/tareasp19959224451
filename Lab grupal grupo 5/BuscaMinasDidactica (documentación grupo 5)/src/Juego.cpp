#include "Juego.h"

int Juego::aleatorio_en_rango(int minimo, int maximo) //Esta parte se encarga del intervalo aleatorio.
	{
		return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	}

	int Juego::filaAleatoria() //Genera una mina en una fila aleatoriamente
	{
		return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
	}

	int Juego::columnaAleatoria() //Genera una mina en una columna aleatoriamente
	{
		return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
	}
	Juego::Juego(Tablero tablero, int cantidadMinas) 
	{
		this->tablero = tablero;
		this->cantidadMinas = cantidadMinas;
		this->colocarMinasAleatoriamente();
	}

	void Juego::colocarMinasAleatoriamente() //Esta parte coloca minas de manera aleatoria en el tablero
	{
		int x, y, minasColocadas = 0;

		while (minasColocadas < this->cantidadMinas) //Fija las coordenadas x & y de las minas
		{
			x = this->columnaAleatoria();
			y = this->filaAleatoria();
			if (this->tablero.colocarMina(x, y))
			{
				minasColocadas++;
			}
		}
	}

	int Juego::solicitarFilaUsuario() //Esta parte se encarga de solicitar y de procesar la fila que el jugador seleccione
	{
		int fila = 0;
		cout << "Ingresa la FILA en la que desea jugar: ";
		cin >> fila;
		return fila - 1;
	}

	int Juego::solicitarColumnaUsuario() //Esta parte se encarga de solicitar y de procesar la columna que el jugador seleccione
	{
		int columna = 0;
		cout << "Ingresa la COLUMNA en la que desea jugar: ";
		cin >> columna;
		return columna - 1;
	}

	bool Juego::jugadorGana() //Registra si el jugador logro completar el juego
	{
		int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
		if (conteo == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Juego::iniciar() //Esta parte se encarga de ejecutar el juego
	{
		int fila, columna;
		while (true) //Esta parte se encarga de registrar la fila y columna seleccionada por el jugador.
		{
			//Esta parte imprime el tablero del juego y registra la fila/columna seleccionada por el jugador
			this->tablero.imprimir();
			fila = this->solicitarFilaUsuario();
			columna = this->solicitarColumnaUsuario();
			bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);
			if (!respuestaAUsuario) //Esta parte se encarga de generar un mensaje si el jugador se queda sin vidas y pierde el juego
			{
				cout << "Perdiste el Juego\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}

			if (this->jugadorGana()) //Esta parte genera un mensaje si el jugador logra ganar el juego
			{
				cout << "Ganaste el Juego\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}
		}
	}
