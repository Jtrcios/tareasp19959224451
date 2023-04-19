// Fig. 14.10: DatosCliente.cpp
// La clase DatosCliente almacena la información de crédito del cliente.
#include <string>
#include "DatosCliente.h"
using namespace std;

// constructor predeterminado de DatosCliente
DatosCliente::DatosCliente( int valorNumeroCuenta, const string &apellidoPaterno, 
const string &primerNombre, double valorSaldo )
: numeroCuenta( valorNumeroCuenta ), saldo( valorSaldo )
{
establecerApellidoPaterno( valorApellidoPaterno );
establecerPrimerNombre( valorPrimerNombre );
} // fin del constructor de DatosCliente

// obtiene el valor del número de cuenta
int DatosCliente::obtenerNumeroCuenta() const
{
return numeroCuenta;
} // fin de la función obtenerNumeroCuenta

// establece el valor del número de cuenta
void DatosCliente::establecerNumeroCuenta( int valorNumeroCuenta )
{
numeroCuenta = valorNumeroCuenta; // debe validar
} // fin de la función establecerNumeroCuenta

// obtiene el valor del apellido paterno
string DatosCliente::obtenerApellidoPaterno() const
{
return apellidoPaterno;
} // fin de la función obtenerApellidoPaterno

// establece el valor del apellido paterno
void DatosCliente::establecerApellidoPaterno( const string &cadenaApellidoPaterno )
{
// copia a lo más 15 caracteres de la cadena a apellidoPaterno
int longitud = cadenaApellidoPaterno.size(); 
longitud = ( longitud < 15 ? llongitud : 14 );
cadenaApellidoPaterno.copy( apellidoPaterno, longitud );
apellidoPaterno[ longitud ] = '\0'; // adjunta un carácter nulo a apellidoPaterno
} // fin de la función establecerApellidoPaterno

// obtiene el valor del primer nombre
string DatosCliente::obtenerPrimerNombre() const
{
return primerNombre;
} // fin de la función obtenerPrimerNombre

// establece el valor del primer nombre
void DatosCliente::establecerPrimerNombre( const string &cadenaPrimerNombre )
{
// copia a lo más 10 caracteres de la cadena a primerNombre
int longitud = cadenaPrimerNombre.size();
longitud = ( longitud < 10 ? longitud : 9 );
cadenaPrimerNombre.copy( primerNombre, longitud );
primerNombre[ longitud ] = '\0'; // adjunta un carácter nulo a primerNombre
} // fin de la función establecerPrimerNombre

// obtiene el valor del saldo
double DatosCliente::obtenerSaldo() const
{
return saldo;
} // fin de la función obtenerSaldo

// establece el valor del saldo
void DatosCliente::establecerSaldo( double valorSaldo )
{
saldo = valorSaldo;
} // fin de la función establecerSaldo