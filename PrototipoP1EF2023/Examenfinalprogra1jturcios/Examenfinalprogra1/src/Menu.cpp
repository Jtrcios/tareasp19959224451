#include "Menu.h"
#include <iostream>
#include <ctime>

void Menu::mostrarMenuCatalogos() {
    cout << "=== Submenú de Catálogo ===" << endl;
    cout << "1. Agregar registro" << endl;
    cout << "2. Eliminar registro" << endl;
    cout << "3. Modificar registro" << endl;
    cout << "4. Mostrar registros" << endl;
    cout << "5. Generar reporte en archivo .txt" << endl;
    cout << "r. Regresar al menú anterior" << endl;

    char opcion;
    cout << "Ingrese una opción: ";
    cin >> opcion;

    switch (opcion) {
        case '1': {
            string registro;
            cout << "Ingrese el registro a agregar: ";
            cin.ignore();
            getline(cin, registro);
            catalogo.agregarRegistro(registro);
            cout << "Registro agregado correctamente." << endl;
            mostrarMenuCatalogos();
            break;
        }
        case '2': {
            string registro;
            cout << "Ingrese el registro a eliminar: ";
            cin.ignore();
            getline(cin, registro);
            catalogo.eliminarRegistro(registro);
            cout << "Registro eliminado correctamente." << endl;
            mostrarMenuCatalogos();
            break;
        }
        case '3': {
            string registroAnterior, registroNuevo;
            cout << "Ingrese el registro a modificar: ";
            cin.ignore();
            getline(cin, registroAnterior);
            cout << "Ingrese el nuevo valor del registro: ";
            getline(cin, registroNuevo);
            catalogo.modificarRegistro(registroAnterior, registroNuevo);
            cout << "Registro modificado correctamente." << endl;
            mostrarMenuCatalogos();
            break;
        }
        case '4': {
            vector<string> registros = catalogo.obtenerRegistros();
            cout << "=== Registros ===" << endl;
            for (const string& reg : registros) {
                cout << reg << endl;
            }
            mostrarMenuCatalogos();
            break;
        }
        case '5': {
            string nombreArchivo;
            cout << "Ingrese el nombre del archivo de reporte: ";
            cin.ignore();
            getline(cin, nombreArchivo);
            bitacora.generarArchivo(nombreArchivo);
            mostrarMenuCatalogos();
            break;
        }
        case 'r':
            mostrarMenuGeneral();
            break;
        default:
            cout << "Opción inválida." << endl;
            mostrarMenuCatalogos();
            break;
    }
}

void Menu::mostrarMenuProcesos() {
    cout << "=== Submenú de Procesos ===" << endl;
    cout << "a. Facturación" << endl;
    cout << "b. Consulta de bitácora de seguridad" << endl;
    cout << "r. Regresar al menú anterior" << endl;

    char opcion;
    cout << "Ingrese una opción: ";
    cin >> opcion;

    switch (opcion) {
        case 'a':
            facturacion();
            break;
        case 'b':
            consultaBitacora();
            break;
        case 'r':
            mostrarMenuGeneral();
            break;
        default:
            cout << "Opción inválida." << endl;
            mostrarMenuProcesos();
            break;
    }
}

void Menu::mostrarMenuReportes() {
    cout << "=== Submenú de Reportes ===" << endl;
    cout << "1. Generar archivo de bitácora" << endl;
    cout << "r. Regresar al menú anterior" << endl;

    char opcion;
    cout << "Ingrese una opción: ";
    cin >> opcion;

    switch (opcion) {
        case '1': {
            string nombreArchivo;
            cout << "Ingrese el nombre del archivo de reporte: ";
            cin.ignore();
            getline(cin, nombreArchivo);
            bitacora.generarArchivo(nombreArchivo);
            mostrarMenuReportes();
            break;
        }
        case 'r':
            mostrarMenuGeneral();
            break;
        default:
            cout << "Opción inválida." << endl;
            mostrarMenuReportes();
            break;
    }
}

void Menu::mostrarMenuGeneral() {
    cout << "=== Menú General ===" << endl;
    cout << "1. Catálogos" << endl;
    cout << "2. Procesos" <<endl;
    cout << "3. Reportes" << endl;
    cout << "4. Salir del sistema" << endl;

    char opcion;
    cout << "Ingrese una opción: ";
    cin >> opcion;

    switch (opcion) {
        case '1':
            mostrarMenuCatalogos();
            break;
        case '2':
            mostrarMenuProcesos();
            break;
        case '3':
            mostrarMenuReportes();
            break;
        case '4':
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opción inválida." << endl;
            mostrarMenuGeneral();
            break;
    }
}

void Menu::iniciarSesion() {
    string nombre, contrasena;
    cout << "=== Iniciar Sesión ===" << endl;
    cout << "Ingrese su nombre de usuario: ";
    cin >> nombre;
    cout << "Ingrese su contraseña: ";
    cin >> contrasena;

    bool autenticado = manejadorUsuarios.autenticarUsuario(nombre, contrasena);

    if (autenticado) {
        cout << "Inicio de sesión exitoso." << endl;
        mostrarMenuGeneral();
    } else {
       cout << "Nombre de usuario o contraseña incorrectos." <<endl;
        iniciarSesion();
    }
}

void Menu::facturacion() {
    // Lógica de facturación
}

void Menu::consultaBitacora() {
    vector<Bitacora::Registro> registros = bitacora.obtenerRegistros();
    cout << "=== Bitácora de Seguridad ===" << endl;
    for (const Bitacora::Registro& reg : registros) {
        cout << "Usuario: " << reg.usuario << endl;
        cout << "Aplicación: " << reg.aplicacion << endl;
        cout << "Hora-Fecha: " << reg.horaFecha << endl;
        cout << "Acción: " << reg.accion << endl;
        cout << endl;
    }
    mostrarMenuProcesos();
}

void Menu::ejecutar() {
    // Agregar registros de ejemplo
    catalogo.agregarRegistro("Registro 1");
    catalogo.agregarRegistro("Registro 2");
    bitacora.agregarRegistro("Usuario1", "Aplicación1", "2023-06-07 10:00", "Acción 1");
    bitacora.agregarRegistro("Usuario2", "Aplicación2", "2023-06-07 11:00", "Acción 2");

    // Iniciar sesión
    iniciarSesion();
}
