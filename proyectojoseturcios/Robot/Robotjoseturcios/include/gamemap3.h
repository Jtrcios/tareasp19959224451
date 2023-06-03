#ifndef GAMEMAP3_H
#define GAMEMAP3_H
#include "mapcell.h"
// Encabezado que define toda la funcionabilidad del mapa del juego

class gamemap3
{
    public:
        gamemap3();
        mapcell* playerCell3;
        mapcell cell [15][10];
        void draw();
        // m�todo que obtiene las coordenadas del jugador y actualiza el mapa
        bool setPlayerCell3(int playerX, int playerY);
        void drawPortada();
        void drawVictoria();
        virtual ~gamemap3();
        bool isGameOver = false;


    protected:

    private:
        void loadMapFromFile3();
        void createMapToFile3();
};

#endif // GAMEMAP_H
