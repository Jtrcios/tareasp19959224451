#include <iostream>
#include "player.h"
#include "mapcell.h"
#include "gamemap.h"
#include "gamemap2.h"
#include "gamemap3.h"

using namespace std;

int main()
{
    // Aplicativo elaborado en el curso de Programacion I - Universidad Mariano Galvez
    // desarrollador: daguilae - Marzo 2022


    gamemap map;
    gamemap2 map2;
    gamemap3 map3;
    player hero;
    map.drawPortada();
    cout << "     _____                                   " <<endl;
    cout << " ___|   _ |__  ____  __    _ ______  ____    " <<endl;
    cout << "|    \\ | |   ||    |\\  \\  //|   ___||    |   " <<endl;
    cout << "|     \\| |   ||    | \\  \\// |   ___||    |_  " <<endl;
    cout << "|__/\\____| __||____|  \\__/  |______||______| " <<endl;
    cout << "    |_____|                                  " <<endl;
    cout << "     _____                                   " <<endl;
    cout << "  __|  _  |__  ____   _  _____                " <<endl;
    cout << " |  | | |    ||    \\ | |/     \\               " <<endl;
    cout << " |  |_| |    ||     \\| ||     |               " <<endl;
    cout << " |______|  __||__/\\____|\\_____/               " <<endl;
    cout << "    |_____|                                  " <<endl;
    cout << "Pulse cualquier tecla para comenzar"<<endl;
    //map.draw();
    while(map.isGameOver==false)
    {
      cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
      hero.callInput();

      //Actualizar informaci�n del jugador en el mapa
      if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
      {
     //   system("cls");
        map.draw();
      } else
      {
       // system("cls");
        hero.resetToSafePosition();
        //Dibujamos el mapa
        map.draw();
      }
      //map.draw();

    }

     if(map.isGameOver==true){
        cout << "     _____                                   " <<endl;
    cout << " ___|   _ |__  ____  __    _ ______  ____    " <<endl;
    cout << "|    \\ | |   ||    |\\  \\  //|   ___||    |   " <<endl;
    cout << "|     \\| |   ||    | \\  \\// |   ___||    |_  " <<endl;
    cout << "|__/\____| __||____|  \\__/  |______||______| " <<endl;
    cout << "    |_____|                                  " <<endl;
    cout << "     _____                                   " <<endl;
    cout << "  __|__   |__  _____  ______                 " <<endl;
    cout << " |     \\     |/     \\|   ___|                " <<endl;
    cout << " |      \\    ||     | `-.`-.                 " <<endl;
    cout << " |______/  __|\\_____/|______|                " <<endl;
    cout << "    |_____|                                  " <<endl;
    hero.resetToSafePosition();
    while(map2.isGameOver==false)
    {
    cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
    hero.callInput();
    if(map2.setPlayerCell2(hero.getValueX(), hero.getValueY()))
    {
        map2.draw();
    } else
    {
      hero.resetToSafePosition();
    }
    }
     }
     if(map2.isGameOver==true){
         cout << "     _____                                   " << endl;
    cout << " ___|   _ |__  ____  __    _ ______  ____    " << endl;
    cout << "|    \\ | |   ||    |\\  \\  //|   ___||    |   " << endl;
    cout << "|     \\| |   ||    | \\  \\// |   ___||    |_  " << endl;
    cout << "|__/\____| __||____|  \\__/  |______||______| " << endl;
    cout << "    |_____|                                  " << endl;
    cout << "     _____                                   " << std::endl;
    cout << " ___|__   |__  _____   ______  ______        " << std::endl;
    cout << "|_    _|     ||     | |   ___||   ___|       " << std::endl;
    cout << " |    |      ||     \\ |   ___| `-.`-.        " << std::endl;
    cout << " |____|    __||__|\\__\\|______||______|       " << std::endl;
    cout << "    |_____|                                  " << std::endl;
     hero.resetToSafePosition();
    while(map3.isGameOver==false)
    {
    cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
    hero.callInput();
    if(map3.setPlayerCell3(hero.getValueX(), hero.getValueY()))
    {
        map3.draw();
    } else
    {
      hero.resetToSafePosition();
    }
    }
     }

    return 0;
}
