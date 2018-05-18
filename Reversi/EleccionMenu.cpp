/*
Nombre: .cpp
Autor: Raúl Octavio Murcia Yocupicio
Fecha:
Descripción:
*/

#include <iostream>
#include <cstdlib>

#include "ManejoConsola.h"

using namespace std;

void DibujaTablero(int x, int y){

    enum simSimple{ESD = 191, EII, EID = 217, ESI, EH = 196, EV = 179};

    gotoxy(x, y);

    cout << char(ESI);
    for(int j = 0; j < 8; j++){
        for (int i = 0; i < 6; i++) cout << char(EH);
        cout << char(194);
    }
    cout << '\b' << char(ESD);
    gotoxy(x, ++y);

    for(int k = 0; k < 7; k++){
        for(int j = 0; j < 4; j++){
            cout << char(EV);
            for (int i = 0; i < 8; i++) cout << "      " << char(EV);
            gotoxy(x, ++y);
        }

        cout << char(195);
        for(int j = 0; j < 8; j++){
            for (int i = 0; i < 6; i++) cout << char(EH);
            cout << char(197);
        }
        cout << '\b' << char(180);

        gotoxy(x, ++y);
    }

    for(int j = 0; j < 4; j++){
        cout << char(EV);
        for (int i = 0; i < 8; i++) cout << "      " << char(EV);
        gotoxy(x, ++y);
    }

    cout << char(EII);
    for(int j = 0; j < 8; j++){
        for (int i = 0; i < 6; i++) cout << char(EH);
        cout << char(193);
    }
    cout << '\b' << char(EID);
}

bool JuegaReversi(){
    int x, y;
    ObtieneDimensionesVentana(x, y);
    DibujaTablero((x - 57) / 2, (y - 46) / 2);



    system("pause");

    return false;
}

