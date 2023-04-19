// Fig. 14.14: Fig14_14.cpp
// Este programa lee un archivo de acceso aleatorio en forma secuencial,
// actualiza los datos escritos anteriormente en el archivo, crea datos
// para colocarlos en el archivo, y elimina los datos previamente almacenados.
#include <iostream>
#include <fstream> 
#include <iomanip>
#include <cstdlib>
#include "DatosCliente.h" // definición de la clase DatosCliente
using namespace std;

int escribirOpcion();
void crearArchivoTexto( fstream& );
void actualizarRegistro( fstream& );
void nuevoRegistro( fstream& );
void eliminarRegistro( fstream& );
void imprimirLinea( ostream&, const DatosCliente & );
int obtenerCuenta( const char * const );
enum Opciones { IMPRIMIR = 1, ACTUALIZAR, NUEVO, ELIMINAR, TERMINAR };
int main()
{
// abre el archivo para leer y escribir 
fstream creditoEntSal( "credito.dat", ios::in | ios::out | ios::binary );
// sale del programa si fstream no puede abrir el archivo
if ( !creditoEntSal ) 
{
cerr << "No se pudo abrir el archivo." << endl;
exit ( EXIT_FAILURE );
} // fin de if
int opcion; // almacena la opción del usuario
// permite al usuario especificar una acción
while ( ( opcion = escribirOpcion() ) != TERMINAR ) 
{
switch ( opcion ) 
{
case IMPRIMIR: // crea un archivo de texto a partir del archivo de registros
crearArchivoTexto( creditoEntSal );
break;
case ACTUALIZAR: // actualiza el registro
actualizarRegistro( creditoEntSal );
break;
case NUEVO: // crea un registro
nuevoRegistro( creditoEntSal );
break;
case ELIMINAR: // elimina un registro existente
eliminarRegistro( reditoEntSal );
break;
default: // muestra un error si el usuario no selecciona una opción válida
cerr << "Opcion incorrecta" << endl;
break;
} // fin de switch

creditoEntSal.clear(); // restablece el indicador de fin de archivo
} // fin de while
} // fin de main
// permite al usuario introducir la opción del menú
int escribirOpcion()
{
// muestra las opciones disponibles
cout << "\nEscriba su opcion" << endl
<< "1 - almacenar un archivo de texto con formato de las cuentas" << endl
<< " llamado \"imprimir.txt\" para imprimirlo" << endl
<< "2 - actualizar una cuenta" << endl
<< "3 - agregar una nueva cuenta" << endl
<< "4 - eliminar una cuenta" << endl
<< "5 - fin del programa\n? ";
int opcionMenu;
cin >> opcionMenu; // introduce la selección del menú que hizo el usuario
return opcionMenu;
} // fin de la función escribirOpcion
// crea un archivo de texto con formato para imprimirlo
void crearArchivoTexto( fstream &leerDelArchivo )
{
// crea un archivo de texto 
ofstream archivoImprimirSalida( "imprimir.txt", ios::out );
// sale del programa si ofstream no puede crear el archivo
if ( !archivoImprimirSalida ) 
{
cerr << "No se pudo crear el archivo." << endl;
exit( EXIT_FAILURE );
} // fin de if
// imprime los encabezados de las columnas
archivoImprimirSalida << left << setw( 10 ) << "Cuenta" << setw( 16 )
<< "Apellido" << setw( 11 ) << "Nombre" << right 
<< setw( 10 ) << "Saldo" << endl; 
// establece el apuntador de posición del archivo en el inicio de leerDelArchivo
leerDelArchivo.seekg( 0 ); 
// lee el primer registro del archivo de registros
DatosCliente cliente;
leerDelArchivo.read( reinterpret_cast< char * >( &cliente ),
sizeof( DatosCliente ) ); 
// copia todos los registros del archivo de registros al archivo de texto
while ( !leerDelArchivo.eof() ) 
{
// escribe un solo registro en el archivo de texto
if ( cliente.obtenerNumeroCuenta() != 0 ) // omite los registros vacíos
imprimirLinea( archivoImprimirSalida, cliente );

// lee el siguiente registro del archivo de registros 
leerDelArchivo.read( reinterpret_cast< char * >( &cliente ),
sizeof( DatosCliente ) ); 
} // fin de while
} // fin de la función crearArchivoTexto
// actualiza el saldo en el registro
void actualizarRegistro( fstream &actualizarArchivo )
{
// obtiene el número de la cuenta que se va a actualizar
int numeroCuenta = obtenerCuenta( "Escriba la cuenta que se debe actualizar" );
// desplaza el apuntador de posición del archivo al registro correcto en el archivo
actualizarArchivo.seekg( ( numeroCuenta - 1 ) * sizeof( DatosCliente ) );
// lee el primer registro del archivo
DatosCliente cliente;
actualizarArchivo.read( reinterpret_cast< char * >( &cliente ),
sizeof( DatosCliente ) ); 
// actualiza el registro
if ( cliente.obtenerNumeroCuenta() != 0 ) 
{
imprimirLinea( cout, cliente ); // muestra el registro
// solicita al usuario que especifique la transacción
cout << "\nEscriba el cargo (+) o pago (-): ";
double transaction; // cargo o pago
cin >> transaction;
// actualiza el saldo del registro
double saldoAnterior = cliente.obtenerSaldo();
cliente.establecerSaldo( saldoAnterior + transaccion );
imprimirLinea( cout, cliente ); // muestra el registro
// desplaza el apuntador de posición del archivo al registro correcto en el archivo
actualizarArchivo.seekp( ( numeroCuenta - 1 ) * sizeof( DatosCliente ) );
// escribe el registro actualizado sobre el registro anterior en el archivo 
actualizarArchivo.write( reinterpret_cast< const char * >( &cliente ),
sizeof( DatosCliente ) ); 
} // fin de if
else // muestra un error si la cuenta no existe
cerr << "La cuenta #" << numeroCuenta 
<< " no tiene informacion." << endl;
} // fin de la función actualizarRegistro
// crea e inserta un registro
void nuevoRegistrod( fstream &insertarEnArchivo )
{
// obtiene el número de cuenta que se debe crear
int numeroCuenta = obtenerCuenta( "Escriba el nuevo numero de cuenta" );

// desplaza el apuntador de posición del archivo al registro correcto en el 
archivo
insertarEnArchivo.seekg( ( numeroCuenta - 1 ) * sizeof( DatosCliente ) );
// lee un registro del archivo
DatosCliente cliente;
insertarEnArchivo.read( reinterpret_cast< char * >( &cliente ),
sizeof( DatosCliente ) ); 
// crea un registro, si no es que ya existe
if ( cliente.obtenerNumeroCuenta() == 0 ) 
{
string apellidoPaterno;
string primerNombre;
double saldo;
// el usuario introduce el apellido paterno, primer nombre y saldo
cout << "Escriba apellido paterno, primer nombre y saldo\n? ";
cin >> setw( 15 ) >> apellidoPaterno;
cin >> setw( 10 ) >> primerNombre;
cin >> saldo;
// usa los valores para llenar los valores de la cuenta
cliente.establecerApellidoPaterno( apellidoPaterno );
cliente.establecerPrimerNombre( primerNombre );
cliente.establecerSaldo( saldo );
cliente.establecerNumeroCuenta( numeroCuenta );
// desplaza el apuntador de posición del archivo al registro correcto 
en el archivo 
insertarEnArchivo.seekp( ( numeroCuenta - 1 ) * sizeof( DatosCliente ) );
// inserta el registro en el archivo 
insertarEnArchivo.write( reinterpret_cast< const char * >( &cliente ),
sizeof( DatosCliente ) ); 
} // fin de if
else // muestra un error si la cuenta ya existe
cerr << "La cuenta #" << numeroCuenta
<< " ya contiene información." << endl;
} // fin de la función nuevoRegistro
// elimina un registro existente
void eliminarRegistro( fstream &eliminarDelArchivo )
{
// obtiene el número de cuenta que debe eliminar
int numeroCuenta = obtenerCuenta( "Escriba la cuenta a eliminar" );
// desplaza el apuntador de posición del archivo al registro correcto en el archivo
eliminarDelArchivo.seekg( ( numeroCuenta - 1 ) * sizeof( DatosCliente ) );
// lee el registro del archivo
DatosCliente cliente;
eliminarDelArchivo.read( reinterpret_cast< char * >( &cliente ),
sizeof( DatosCliente ) );

// elimina el registro, si es que existe en el archivo
 if ( cliente.obtenerNumeroCuenta() != 0 ) 
{
DatosCliente clienteEnBlanco; // crea un registro en blanco

// desplaza el apuntador de posición del archivo al 
registro correcto en el archivo
eliminarDelArchivo.seekp( ( numeroCuenta - 1 ) * 
sizeof( DatosCliente ) ); 
// reemplaza el registro existente con uno en blanco 
eliminarDelArchivo.write( 
reinterpret_cast< const char * >( &clienteEnBlanco ),
sizeof( DatosCliente ) ); 
cout << "La cuenta #" << numeroCuenta << " se elimino.\n";
} // fin de if
else // muestra un error si el registro no existe
cerr << "La cuenta #" << numeroCuenta << " esta vacia.\n";
} // fin de eliminarRegistro
// muestra un solo registro
void imprimirLinea( ostream &salida, const DatosCliente &registro )
{
salida << left << setw( 10 ) << registro.obtenerNumeroCuenta()
<< setw( 16 ) << registro.obtenerApellidoPaterno()
<< setw( 11 ) << registro.obtenerPrimerNombre()
<< setw( 10 ) << setprecision( 2 ) << right << fixed 
<< showpoint << registro.obtenerSaldo() << endl;
} // fin de la función imprimirLinea
// obtiene el valor del número de cuenta del usuario
int obtenerCuenta( const char * const indicador )
{
int numeroCuenta;
// obtiene el valor del número de cuenta
do
{
cout << indicador << " (1 - 100): ";
cin >> numeroCuenta;
} while ( numeroCuenta < 1 || numeroCuenta > 100 );
return numeroCuenta;
} // fin de la función obtenerCuenta