#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

#define NUMERO_EQUIPOS 5
#define NUMERO_PUNTUACION 5
#define MAX_PUNTOS 50
#define MIN_PUNTOS 0
#define MAXIMA_LONGITUD_CADENA 100
void Matrices(string Matrizresultante)

{
int busquedaAleatorios(int minimo, int maximo);
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz(float matriz[NUMERO_EQUIPOS][NUMERO_PUNTUACION + 1]);
{
    int y, x;
    for (y = 0; y < NUMERO_EQUIPOS; y++)
    {
        float suma = 0;
        for (x = 0; x < NUMERO_PUNTUACION; x++)
        {
            int calificacion = busquedaAleatorios(MIN_PUNTOS, MAX_PUNTOS);
            suma += (float)calificacion;
            matriz[y][x] = calificacion;
        }
        float promedio = suma / NUMERO_PUNTUACION;
        matriz[y][NUMERO_PUNTUACION] = promedio;
    }
}

void imprimirMatrizLinea()
{
    int x;
    cout << "+--------";
    for (x = 0; x < NUMERO_PUNTUACION + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}
void imprimirMatriz(float matriz[NUMERO_EQUIPOS][NUMERO_PUNTUACION + 1], char equipos[NUMERO_EQUIPOS][MAXIMA_LONGITUD_CADENA])
{
    int y, x;
    float promedioMayor = matriz[0][NUMERO_PUNTUACION];
    float promedioMenor = matriz[0][NUMERO_PUNTUACION];
    char equipoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char equipoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(equipoPromedioMayor, equipos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(equipoPromedioMenor, equipos[0], MAXIMA_LONGITUD_CADENA);

    imprimirMatrizLinea();
    cout << setw(9) << "Equipos";
    for (x = 0; x < NUMERO_PUNTUACION; x++)
    {
        cout << setw(9) << "Punt" << x + 1;
    }
    cout << setw(8) << "Prom" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_EQUIPOS; y++)
    {
        cout << "!" << setw(8) << equipos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_PUNTUACION; x++)
        {
            int puntuacion = matriz[y][x];
            cout << setw(9) << puntuacion << "!";
        }
        float promedio = matriz[y][NUMERO_PUNTUACION];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(equipoPromedioMayor, equipos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(equipoPromedioMenor, equipos[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
}