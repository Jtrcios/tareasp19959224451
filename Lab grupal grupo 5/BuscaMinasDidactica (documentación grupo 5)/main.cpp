#include <iostream>
#include <unistd.h>
#include "Juego.h"
#include "Config.h"

using namespace std;

int main()
{ // Esta parte son los detalles principales del juego como la estructura y las vidas
    const int FILASTABLERO = 5; //Este valor dicta la cantidad de filas que tendra el tablero
    const int COLUMNASTABLERO = 5; //Este valor dicta la cantidad de columnas que tendra el tablero
    const int MINASENTABLERO = 3; //Este valor dicta las minas a generar en un lugar aleatorio en el tablero
    const bool MODODESARROLLADOR = true; //Esta función habilita o deshabilita el modo desarrollador
    const int VIDASTABLERO = 3; //este valor dicta las vidas disponibles para el jugador
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);

    srand(getpid());
    int opciones;
    bool repetir = true;
    do // Esta parte es la estructura del menu principal del juego
    {
        system("cls");
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Configuaracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
            {
                configuracionJuego.menuConfiguracion(); // Este caso manda al menu de configuración del juego
                break;
            }
        case 2:
            {
              	Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
                juego.iniciar();
                system("pause"); //Este caso se encarga de iniciar el juego
                break;
            }
        case 3: repetir = false; //Este caso se encarga de cerrar el juego
                break;
        }
    } while (repetir);
    return 0;
}
