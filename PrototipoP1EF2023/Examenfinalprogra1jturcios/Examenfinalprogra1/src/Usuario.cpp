#include "Usuario.h"

Usuario::Usuario(const std::string& nombre, const std::string& contrasena)
    : nombre(nombre), contrasena(contrasena) {}

std::string Usuario::getNombre() const {
    return nombre;
}

std::string Usuario::getContrasena() const {
    return contrasena;
}
