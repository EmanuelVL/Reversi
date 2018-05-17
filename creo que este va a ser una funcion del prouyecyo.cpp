/*
Nombre: .cpp
Autor: Raúl Octavio Murcia Yocupicio
Fecha:
Descripción:
*/

#include <iostream>
#include <cstdlib>
#include <windows.h>

#define CENTRO_OX 19
#define CENTRO_OY 17

#define CENTRO_XX 23
#define CENTRO_XY 17
#define SQ 4

enum estadoCasilla{VACIO = 0, BLANCA, NEGRA};

void DibujarTablero(int x, int y);
void gotoxy (int x, int y);
void PosicionO(int x, int y, int arreglo_x, int arreglo_y, char Tablero[8][8]);
void PosicionX(int x, int y, int arreglo_x, int arreglo_y, char Tablero[8][8]);
void PosicionInicial(char Tablero[8][8]);
bool Movimiento(estadoCasilla Tab[][10], estadoCasilla Jugador, int x, int y);

using namespace std;

int main()
{
    estadoCasilla Tablero[10][10];



    DibujarTablero(xMedio - 57/2, yMedio - 57/2);




    system("pause");
    return 0;
}

bool Movimiento(estadoCasilla Tab[][10], estadoCasilla Jugador, int x, int y){

    estadoCasilla Oponente = (Jugador = BLANCA ? NEGRA : BLANCA);
    bool movPermitido = false;

    if (Tab[x][y] != VACIO) return false;

    for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; (i == 0 ? j +=2 : j++)){ //Saltando el caso i = 0, j = 0
            int dX = i, dY = j;

            while(Tab[x + dX][y + dY] == Oponente &&
                  (x + dX > 0 && x + dX < 9 && y + dY > 0 && y + dY < 9)){

                dX += i;
                dY += j;
            } //ahhh

            if(Tab[x + dX][y + dY] == Jugador){
                dX -= i;
                dY -= j;
                while(Tab[x + dX][y + dY] == Oponente){
                    bool movPermitido = true;
                    Tab[x + dX][y + dY] = Jugador;
                    dX -= i;
                    dY -= j;
                }
            }
        }

    return movPermitido;
}

void DibujarTablero(int x, int y){

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

void PosicionO(int x, int y, int arreglo_x, int arreglo_y, char Tablero[8][8]){
    gotoxy(x,y);
    Tablero[arreglo_x][arreglo_y] = char(79);
    cout << Tablero[arreglo_x][arreglo_y];
}

void PosicionX(int x, int y, int arreglo_x, int arreglo_y, char Tablero[8][8]){
    gotoxy(x,y);
    Tablero[arreglo_x][arreglo_y] = char(88);
    cout << Tablero[arreglo_x][arreglo_y];
}

void gotoxy (int x, int y){
    HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD coord = {x-1, y-1};
    SetConsoleCursorPosition(handle, coord);
}

void PosicionInicial(char Tablero[8][8]){
    PosicionO(CENTRO_OX, CENTRO_OY, 4, 4, Tablero);
	PosicionX(CENTRO_XX, CENTRO_XY, 5, 4, Tablero);
	PosicionX(CENTRO_XX-SQ, CENTRO_XY+SQ, 4, 5, Tablero);
	PosicionO(CENTRO_OX+SQ, CENTRO_OY+SQ, 5, 5, Tablero);
}
