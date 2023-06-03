#include "gamemap2.h"
#include <iostream>
#include <fstream>
//Implementacion de toda la funcionabilidad del mapa del juego

using namespace std;
gamemap2::gamemap2()
{
    //ctor
    playerCell2 = NULL;
    loadMapFromFile2();
    isGameOver = false;
}
void gamemap2::draw(){
    //system("cls");
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // Utilizar las celulas cuando se dibuja el mapa
            cout << cell [i][j].id;
        }
        cout << endl;
    }
}
bool gamemap2::setPlayerCell2(int playerX, int playerY)
{
    if (cell[playerX][playerY].isBlockedCell() == false)
    {
        if (cell[playerX][playerY].id == '$')
        {
            drawVictoria();
            isGameOver = true;
            return true;
        } else
        { // eval�a espacio
            //Se verifica que maque con cero la posicion que abandona el jugador
            if (playerCell2 != NULL)
            {
                // Cambio permitira quitar los ceros en el camino del jugador, al traslador un cero a un char se convierte en espacio
                playerCell2->id='0';
                playerCell2->id=60;
            }
            //cout << "Las coordenadas del jugador estan en: " << playerX << "," << playerY << endl;
            //Cambio de coordenadas para corregiro problema de los movimientos del jugador en el eje X
            //playerCell = &cell[playerY][playerX];
            playerCell2 = &cell[playerX][playerY];

          //ascii 60
        }

        return true;
    }
    else
    {
        return false;
    }

}
void gamemap2::loadMapFromFile2()
{
    string line;
    int row = 0;
    char userInput = ' ';
    ifstream myFile("mapa2.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            //cout << line << endl;
            for (int p = 0; p < line.length(); p++)
            {
                if (line[p] == '0')
                {
                    cell[row][p].id = 0;
                } else
                {
                    cell[row][p].id = line[p];
                }
                // Cambio para quitar ceros y colocar espacios en blanco en el mapa
                // cell[row][p].id = line[p];
            }

            row++;
        }
        myFile.close();
    }
    else
    {
        cout << "Error FATAL: archivo del mapa no pudo ser cargado" << endl;
        cout << "Desea crearlo? " << endl;
        cin >> userInput;
        if (userInput='s')
        {
            createMapToFile2();
        } else
        {
            cout << "NO podemos continuar el juego" << endl;
        }
    }

}
void gamemap2::createMapToFile2()
{
    ofstream myFile("mapa2.txt");
    if (myFile.is_open())
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == 0 || i == 14)
                {
                    myFile << "1";
                } else
                {
                    if (j == 0 || j == 9)
                    {
                        myFile << "1";
                    } else
                    {
                        myFile << "0";
                    }
                }

            }
            myFile << endl;
        }
        myFile.close();
    } else
    {
        cout << "Error FATAL: archivo no pudo ser creado" << endl;
    }
}
void gamemap2::drawPortada()
{
    string line;
    char userInput = ' ';
    ifstream myFile("portada.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
    }
}
void gamemap2::drawVictoria()
{
    string line;
    char userInput = ' ';
    ifstream myFile("premio.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}

gamemap2::~gamemap2()
{
    //dtor
}
