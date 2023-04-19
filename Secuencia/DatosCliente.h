// Fig. 14.9: DatosCliente.h
// Definición de la clase DatosCliente, utilizada en las figuras 14.11 a 14.14.
#ifndef DATOSCLIENTE_H
#define DATOSCLIENTE_H
#include <string>
class DatosCliente 
{
public:
// constructor predeterminado de DatosCliente
DatosCliente( int = 0, const std::string & = "", 
const std::string & = "", double = 0.0 );
// funciones de acceso para numeroCuenta
void establecerNumeroCuenta( int );
int gobtenerNumeroCuenta() const;
// funciones de acceso para apellidoPaterno
void establecerApellidoPaterno( const std::string & );
std::string obtenerApellidoPaterno() const;
// funciones de acceso para primerNombre
void establecerPrimerNombre( const std::string & );
std::obtenerPrimerNombre() const;
// funciones de acceso para el saldo
void establecerSaldo( double );
double obtenerSaldo() const;
private:
int numeroCuenta;
char apellidoPaterno[ 15 ];
char primerNombre[ 10 ];
double saldo;
}; // fin de la clase DatosCliente
#endif