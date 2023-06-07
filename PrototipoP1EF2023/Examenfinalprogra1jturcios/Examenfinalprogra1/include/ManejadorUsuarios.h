#ifndef MANEJADOR_USUARIOS_H
#define MANEJADOR_USUARIOS_H

#include "Usuario.h"
#include <vector>
using namespace std;

// Clase para manejar la autenticaci�n y CRUD de usuarios
class ManejadorUsuarios {
private:
    vector<Usuario> usuarios;

public:
    bool autenticarUsuario(const string& nombre, const string& contrasena);
    void agregarUsuario(const Usuario& usuario);
    void eliminarUsuario(const string& nombre);

    // Implementar m�todos para listar y actualizar usuarios
    // ...
};

#endif  // MANEJADOR_USUARIOS_H

