#ifndef USUARIO_H
#define USUARIO_H

#include <string>

// Clase para representar un usuario
class Usuario {
private:
    std::string nombre;
    std::string contrasena;
public:
    Usuario(const std::string& nombre, const std::string& contrasena);

    std::string getNombre() const;
    std::string getContrasena() const;
};

#endif  // USUARIO_H
