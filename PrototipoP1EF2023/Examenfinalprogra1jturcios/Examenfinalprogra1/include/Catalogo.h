#ifndef CATALOGO_H
#define CATALOGO_H

#include <string>
#include <vector>

// Clase para representar un catálogo
class Catalogo {
private:
    std::vector<std::string> registros;

public:
    void agregarRegistro(const std::string& registro);
    void eliminarRegistro(const std::string& registro);
    void modificarRegistro(const std::string& registroAnterior, const std::string& registroNuevo);
    std::vector<std::string> obtenerRegistros() const;
};

#endif  // CATALOGO_H
