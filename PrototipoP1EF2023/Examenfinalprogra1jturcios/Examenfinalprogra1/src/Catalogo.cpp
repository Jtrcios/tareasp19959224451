#include "Catalogo.h"

void Catalogo::agregarRegistro(const std::string& registro) {
    registros.push_back(registro);
}

void Catalogo::eliminarRegistro(const std::string& registro) {
    for (auto it = registros.begin(); it != registros.end(); ++it) {
        if (*it == registro) {
            registros.erase(it);
            break;
        }
    }
}

void Catalogo::modificarRegistro(const std::string& registroAnterior, const std::string& registroNuevo) {
    for (std::string& reg : registros) {
        if (reg == registroAnterior) {
            reg = registroNuevo;
            break;
        }
    }
}

std::vector<std::string> Catalogo::obtenerRegistros() const {
    return registros;
}
