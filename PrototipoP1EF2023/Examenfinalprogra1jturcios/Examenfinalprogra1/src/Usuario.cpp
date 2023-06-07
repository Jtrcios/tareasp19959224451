#include "Usuario.h"

Usuario::Usuario(const string& nombre, const string& contrasena)
    : nombre(nombre), contrasena(contrasena) {}

string Usuario::getNombre() const {
    return nombre;
}

string Usuario::getContrasena() const {
    return contrasena;
}
