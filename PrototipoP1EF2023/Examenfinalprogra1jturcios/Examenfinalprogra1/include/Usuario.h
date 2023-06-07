#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

// Clase para representar un usuario
class Usuario {
private:
string nombre;
string contrasena;
public:
    Usuario(const string& nombre, const string& contrasena);

string getNombre() const;
string getContrasena() const;
};

#endif  // USUARIO_H
