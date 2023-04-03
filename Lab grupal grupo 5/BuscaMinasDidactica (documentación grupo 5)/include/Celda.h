#ifndef CELDA_H
#define CELDA_H
//Libreria que guarda los atributos y los prototipos de los metodos utilizados para crear y administrar las celdas de juego
//Fecha: 17 marzo 2023

class Celda
{
    public: //Esta parte coloca las minas generadas en puntos aleatorios
        Celda();
        Celda(int coordenadaX, int coordenadaY, bool estadoMina);
        int setCoordenadaX(int coordenadaX);
        int getCoordenadaX();
        int setCoordenadaY(int coordenadaY);
        int getCoordenadaY();
        bool setMina(bool estadoMina);
        bool getMina();
        bool setMinaDescubierta(bool minaDescubierta);
        bool getMinaDescubierta();
        void imprimirCelda();
    protected:

    private: //Esta parte se encarga de las minas que han sido descubiertas
        int coordenadaX, coordenadaY;
        bool mina, minaDescubierta;
};

#endif // CELDA_H
