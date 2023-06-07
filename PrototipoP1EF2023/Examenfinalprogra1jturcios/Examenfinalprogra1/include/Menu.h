#ifndef MENU_H
#define MENU_H

#include "ManejadorUsuarios.h"
#include "Catalogo.h"
#include "Bitacora.h"
using namespace std;

// Clase para representar el menú y sus submenús
class Menu {
private:
    ManejadorUsuarios manejadorUsuarios;
    Catalogo catalogo;
    Bitacora bitacora;

    void mostrarMenuCatalogos();
    void mostrarMenuProcesos();
    void mostrarMenuReportes();
    void mostrarMenuGeneral();
    void iniciarSesion();

    void facturacion();


public:
    void ejecutar();
    void consultaBitacora();
};

#endif  // MENU_H
