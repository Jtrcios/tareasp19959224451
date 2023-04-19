#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Estructura para el producto
struct Producto {
    int codigo;
    char nombre[50];
    float precio;
};

// Funciones para el CRUD de productos
void agregarProducto(ofstream &archivo);
void mostrarProductos(ifstream &archivo);
void buscarProducto(ifstream &archivo);
void eliminarProducto(ifstream &archivo, ofstream &temp);

int main() {
    // Autenticación de usuario
    const string USUARIO_ADMIN = "admin";
    const string CONTRASENA_ADMIN = "1234";
    string usuario, contrasena;
    cout << "Ingrese su usuario: ";
    cin >> usuario;
    cout << "Ingrese su contrasena: ";
    cin >> contrasena;
    if (usuario != USUARIO_ADMIN || contrasena != CONTRASENA_ADMIN) {
        cout << "Usuario o contrasena incorrectos. Saliendo del programa..." << endl;
        return 0;
    }
    
    // Menú general
    cout << "Bienvenido al sistema" << endl;
    cout << "Carné: 12345" << endl;
    cout << "Nombre completo: Juan Perez" << endl;
    cout << endl;
    cout << "1. Catálogos" << endl;
    cout << "2. Informes" << endl;
    cout << "3. Salir del sistema" << endl;
    cout << "Seleccione una opcion: ";
    int opcion;
    cin >> opcion;
    
    // Submenú de catálogos
    if (opcion == 1) {
        cout << endl;
        cout << "Submenú de Catálogos" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Eliminar producto" << endl;
        cout << "Seleccione una opcion: ";
        int opcionCatalogos;
        cin >> opcionCatalogos;
        cout << endl;
        
        // Archivo para productos
        ofstream archivoProductos("productos.dat", ios::app | ios::binary);
        ifstream archivoProductosLectura("productos.dat", ios::binary);
        ofstream archivoTemporal("temp.dat", ios::binary);
        
        switch(opcionCatalogos) {
            case 1:
                agregarProducto(archivoProductos);
                break;
            case 2:
                mostrarProductos(archivoProductosLectura);
                break;
            case 3:
                buscarProducto(archivoProductosLectura);
                break;
            case 4:
                eliminarProducto(archivoProductosLectura, archivoTemporal);
                break;
            default:
                cout << "Opción inválida" << endl;
        }
        
        // Cerrar archivos
        archivoProductos.close();
        archivoProductosLectura.close();
        archivoTemporal.close();
    }
return 0;
}
    

