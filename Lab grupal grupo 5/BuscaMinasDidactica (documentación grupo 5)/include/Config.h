#ifndef CONFIG_H
#define CONFIG_H


class Config //Esta parte se encarga de la configuración general del uego
{
    public:
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);
        int getfilasTablero();
        int setfilasTablero(int filasTablero);
        int getcolumnasTablero();
        int setcolumnasTablero(int columnasTablero);
        int getminasTablero();
        int setminasTablero(int minasTablero);
        bool getmodoDesarrolladorTablero();
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);
        int getvidasTablero();
        int setvidasTablero(int vidasTablero);
        void menuConfiguracion();
    protected:

    private:
        int filasTablero;
        int columnasTablero;
        int minasTablero;
        bool modoDesarrolladorTablero;
        int vidasTablero;
};

#endif // CONFIG_H
