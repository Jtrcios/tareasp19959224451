#ifndef BITACORA_H
#define BITACORA_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;



// Clase para representar la bitácora de seguridad
class Bitacora {
private:
    struct Registro {
        string usuario;
        string aplicacion;
        string horaFecha;
        string accion;
    };

    vector<Registro> registros;

public:
    void agregarRegistro(const string& usuario, const string& aplicacion, const string& horaFecha, const string& accion);
    vector<Registro> obtenerRegistros() const;
    void generarArchivo(const string& nombreArchivo) const;
};

#endif  // BITACORA_H
