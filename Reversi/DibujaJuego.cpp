/*
Nombre: .cpp
Autor: Raúl Octavio Murcia Yocupicio
Fecha:
Descripción:
*/

#include <iostream>
#include <windows.h>

#include "ManejoConsola.h"
#include "DibujaJuego.h"

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
        cout << char(194); //Cruz sin arriba
    }
    cout << '\b' << char(ESD);
    gotoxy(x, ++y);

    for(int k = 0; k < 7; k++){
        for(int j = 0; j < 4; j++){
            cout << char(EV);
            for (int i = 0; i < 8; i++) cout << "      " << char(EV);
            gotoxy(x, ++y);
        }

        cout << char(195); //Cruz sin izq
        for(int j = 0; j < 8; j++){
            for (int i = 0; i < 6; i++) cout << char(EH);
            cout << char(197); //Cruz
        }
        cout << '\b' << char(180); //Cruz sin derecha

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
        cout << char(193); //Cruz sin abajo
    }
    cout << '\b' << char(EID);
}

void ResaltaCasilla(int col, int ren, miColor color){
    static int renAnt = 4, colAnt = 4;

    EstableceColor(miColor(VERDE), miColor(BLANCO));
    ImprimeCasilla(colAnt, renAnt);
    EstableceColor(miColor(color), miColor(color));
    ImprimeCasilla(col, ren);
    EstableceColor(miColor(NEGRO), miColor(VERDECLARO));

    renAnt = ren;
    colAnt = col;
}

void CapturaDibujaNombres(char nombre1[], char nombre2[]){
    for(int i = 0; i < 30; ++i){
        for(int j = 0; j < 50; ++j){
            if((i > 0 && i < 20) && (j == 0)){ cout << "\xBA";
            }else if(i == 0 && (j > 0 && j < 45)){ cout << "\xCD";
            }else if(i == 0 && j == 0){ cout << "\xC9";
            }else if(i == 20 && (j > 0 && j < 45)){ cout << "\xCD";
            }else if((i > 0 && i < 20) && (j == 45)){ cout << "\xBA";
            }else if(i == 20 && j == 0){ cout << "\xC8";
            }else if(i == 0 && j == 45){ cout << "\xBB";
            }else if(i == 20 && j == 45){ cout << "\xBC";
            }else cout << " ";
        }
        cout << endl;
    }

    gotoxy(7, 5);
    cout << "Jugador 1: ";

    gotoxy(7, 13);
    cout << "Jugador 2: ";

    gotoxy(18, 5);
    cin.getline(nombre1, 10);

    gotoxy(18, 13);
    cin.getline(nombre2, 10);

    system("cls");

    int x = ((ANCHOVENTANA - 57) / 2) / 2 - 5;
    int y = (ALTOVENTANA  / 8);

    gotoxy(x,y);
    cout << nombre1;

    x = ((ANCHOVENTANA + 57) / 2 + ANCHOVENTANA) / 2 - 5;

    gotoxy(x,y);
    cout << nombre2;
}

void ImprimeMovimientoIncorrecto(){
    int x = (ANCHOVENTANA - 23) / 2;
    int y = (ALTOVENTANA - 40) / 4;
    EstableceColor(miColor(ROJOCLARO), miColor(NEGRO));

    gotoxy(x, y);
    cout << " MOVIMIENTO INCORRECTO ";
    Beep(200, 100);
    Sleep(10);
    Beep(200, 100);
    Sleep(400);

    EstableceColor(miColor(NEGRO), miColor(VERDECLARO));

    gotoxy(x, y);
    cout << "                       ";
}

void ImprimeCasilla(int col, int ren){
    enum simSimple{ESD = 191, EII, CSAB, EID = 217, ESI, CSA = 194, CSI, EH, CRUZ, EV = 179, CSD};

    int x = ((ANCHOVENTANA - 57) / 2) + ((col - 1) * 7), y = ((ALTOVENTANA - 40) / 2) + ((ren - 1) * 5);

    gotoxy(x, y++);

    if (ren > 1){
        if (col > 1) cout << char(CRUZ);
        else cout << char(CSI);
    }else{
        if (col > 1) cout << char(CSA);
        else cout << char(ESI);
    }

    for(int i = 0; i < 6; i++) cout << char(EH);

    if (ren > 1){
        if (col < 8) cout << char(CRUZ);
        else cout << char(CSD);
    }else{
        if (col < 8) cout << char(CSA);
        else cout << char(ESD);
    }

    for(int i = 0; i < 5; i++){
        gotoxy(x += 7, y);
        cout << char(EV);
        gotoxy(x -= 7, y++);
        cout << char(EV);
    }
    cout << '\b';
    if (ren < 8){
        if (col > 1) cout << char(CRUZ);
        else cout << char(CSI);
    }else{
        if (col > 1) cout << char(CSAB);
        else cout << char(EII);
    }

    for(int i = 0; i < 6; i++) cout << char(EH);

    if (ren < 8){
        if (col < 8) cout << char(CRUZ);
        else cout << char(CSD);
    }else{
        if (col < 8) cout << char(CSAB);
        else cout << char(EID);
    }
}

void ImprimirNumero(int num, int x, int y){
    string L1, L2, L3, L4;

    switch(num){
        case 1:
            L1 = "   _ ";
            L2 = "  | |";
            L3 = "  | |";
            L4 = "  |_|";
            break;
        case 2:
            L1 = " ___ ";
            L2 = "|_  |";
            L3 = "|  _|";
            L4 = "|___|";
            break;
        case 3:
            L1 = " ___ ";
            L2 = "|_  |";
            L3 = "|_  |";
            L4 = "|___|";
            break;
        case 4:
            L1 = " ___ ";
            L2 = "| | |";
            L3 = "|_  |";
            L4 = "  |_|";
            break;
        case 5:
            L1 = " ___ ";
            L2 = "|  _|";
            L3 = "|_  |";
            L4 = "|___|";
            break;
        case 6:
            L1 = " ___ ";
            L2 = "|  _|";
            L3 = "| . |";
            L4 = "|___|";
            break;
        case 7:
            L1 = " ___ ";
            L2 = "|_  |";
            L3 = "  | |";
            L4 = "  |_|";
            break;
        case 8:
            L1 = " ___ ";
            L2 = "| . |";
            L3 = "| . |";
            L4 = "|___|";
            break;
        case 9:
            L1 = " ___ ";
            L2 = "| . |";
            L3 = "|_  |";
            L4 = "|___|";
            break;
        case 0:
            L1 = " ___ ";
            L2 = "|   |";
            L3 = "| | |";
            L4 = "|___|";
            break;
    }

    gotoxy(x, y++);
    cout << L1;
    gotoxy(x, y++);
    cout << L2;
    gotoxy(x, y++);
    cout << L3;
    gotoxy(x, y);
    cout << L4;

}
