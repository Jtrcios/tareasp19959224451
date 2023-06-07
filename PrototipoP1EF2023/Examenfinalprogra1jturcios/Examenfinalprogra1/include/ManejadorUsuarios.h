#ifndef MANEJADOR_USUARIOS_H
#define MANEJADOR_USUARIOS_H

#include "Usuario.h"
#include <vector>

// Clase para manejar la autenticaci�n y CRUD de usuarios
class ManejadorUsuarios {
private:
    std::vector<Usuario> usuarios;

public:
    bool autenticarUsuario(const std::string& nombre, const std::string& contrasena);
    void agregarUsuario(const Usuario& usuario);
    void eliminarUsuario(const std::string& nombre);

    // Implementar m�todos para listar y actualizar usuarios
    // ...
};

#endif  // MANEJADOR_USUARIOS_H

