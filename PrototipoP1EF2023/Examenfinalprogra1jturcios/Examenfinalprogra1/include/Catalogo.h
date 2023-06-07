#ifndef CATALOGO_H
#define CATALOGO_H

#include <string>
#include <vector>
using namespace std;

// Clase para representar un catálogo
class Catalogo {
private:
    vector<string> registros;

public:
    void agregarRegistro(const string& registro);
    void eliminarRegistro(const string& registro);
    void modificarRegistro(const string& registroAnterior, const string& registroNuevo);
    vector<string> obtenerRegistros() const;
};

#endif  // CATALOGO_H
