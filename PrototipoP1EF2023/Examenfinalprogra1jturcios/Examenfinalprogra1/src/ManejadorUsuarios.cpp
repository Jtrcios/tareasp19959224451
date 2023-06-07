#include "ManejadorUsuarios.h"

bool ManejadorUsuarios::autenticarUsuario(const string& nombre, const string& contrasena) {
    for (const Usuario& usuario : usuarios) {
        if (usuario.getNombre() == nombre && usuario.getContrasena() == contrasena) {
            return true;
        }
    }
    return false;
}

void ManejadorUsuarios::agregarUsuario(const Usuario& usuario) {
    usuarios.push_back(usuario);
}

void ManejadorUsuarios::eliminarUsuario(const string& nombre) {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        if (it->getNombre() == nombre) {
            usuarios.erase(it);
            break;
        }
    }
}
