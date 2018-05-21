/*
Nombre: .cpp
Autor: Raúl Octavio Murcia Yocupicio
Fecha:
Descripción:
*/

#include <iostream>

#include "ManejoConsola.h"

using namespace std;

void DibujaFicha(int x, int y, miColor color)
{
    gotoxy(x, y++);

    EstableceColor(miColor(VERDE), miColor(color));
    cout << " " << char (220);
    EstableceColor(miColor(color), miColor(color));
    cout << "  ";
    EstableceColor(miColor(VERDE), miColor(color));
    cout << char (220);
    gotoxy(x, y++);
    EstableceColor(miColor(color), miColor(color));
    cout << "      ";
    EstableceColor(miColor(VERDE), miColor(color));

    gotoxy(x, y++);
    EstableceColor(miColor(color), miColor(color));
    cout << "      ";
    EstableceColor(miColor(VERDE), miColor(color));

    gotoxy(x, y++);
    cout << " ";
    cout << char (223);
    EstableceColor(miColor(color), miColor(color));
    cout << "__";
    EstableceColor(miColor(VERDE), miColor(color));
    cout << char (223);
    EstableceColor(miColor(NEGRO), miColor(VERDECLARO));
}

void DibujaTablero(){

    enum simSimple{ESD = 191, EII, EID = 217, ESI, EH = 196, EV = 179};

    int x = (ANCHOVENTANA - 57) / 2, y =(ALTOVENTANA - 40) / 2;

    EstableceColor(VERDE, BLANCO);

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
