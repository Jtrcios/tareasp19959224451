#ifndef GAMEMAP2_H
#define GAMEMAP2_H
#include "mapcell.h"
// Encabezado que define toda la funcionabilidad del mapa del juego

class gamemap2
{
    public:
        gamemap2();
        mapcell* playerCell2;
        mapcell cell [15][10];
        void draw();
        // m�todo que obtiene las coordenadas del jugador y actualiza el mapa
        bool setPlayerCell2(int playerX, int playerY);
        void drawPortada();
        void drawVictoria();
        virtual ~gamemap2();
        bool isGameOver = false;


    protected:

    private:
        void loadMapFromFile2();
        void createMapToFile2();
};

#endif // GAMEMAP_H
