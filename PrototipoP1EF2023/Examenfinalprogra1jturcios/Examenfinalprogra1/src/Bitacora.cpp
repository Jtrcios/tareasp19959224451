#include "Bitacora.h"
#include <fstream>

void Bitacora::agregarRegistro(const string& usuario, const string& aplicacion, const string& horaFecha, const string& accion) {
    Registro reg;
    reg.usuario = usuario;
    reg.aplicacion = aplicacion;
    reg.horaFecha = horaFecha;
    reg.accion = accion;
    registros.push_back(reg);
}

vector<Bitacora::Registro> Bitacora::obtenerRegistros() const {
    return registros;
}

void Bitacora::generarArchivo(const string& nombreArchivo) const {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (const Registro& reg : registros) {
            archivo << "Usuario: " << reg.usuario << endl;
            archivo << "Aplicación: " << reg.aplicacion << endl;
            archivo << "Hora-Fecha: " << reg.horaFecha << endl;
            archivo << "Acción: " << reg.accion << endl;
            archivo << endl;
        }
        archivo.close();
        cout << "Archivo generado exitosamente: " << nombreArchivo << endl;
    } else {
        cout << "No se pudo generar el archivo: " << nombreArchivo << endl;
    }
}
