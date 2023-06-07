#include "Catalogo.h"

void Catalogo::agregarRegistro(const string& registro) {
    registros.push_back(registro);
}

void Catalogo::eliminarRegistro(const string& registro) {
    for (auto it = registros.begin(); it != registros.end(); ++it) {
        if (*it == registro) {
            registros.erase(it);
            break;
        }
    }
}

void Catalogo::modificarRegistro(const string& registroAnterior, const string& registroNuevo) {
    for (string& reg : registros) {
        if (reg == registroAnterior) {
            reg = registroNuevo;
            break;
        }
    }
}

vector<string> Catalogo::obtenerRegistros() const {
    return registros;
}
