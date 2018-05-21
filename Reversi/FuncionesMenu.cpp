/*
Nombre: .cpp
Autor: Raúl Octavio Murcia Yocupicio
Fecha:
Descripción:
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "ManejoConsola.h"
#include "DibujaJuego.h"
#include "AuxiliaresJuego.h"

using namespace std;

void Creditos(){
    int x = (ANCHOVENTANA - 28)/ 2, y = (ALTOVENTANA - 11) / 2 - 5;
    char chars;
    ifstream stream;

    stream.open("textos//Creditos.txt");
    stream.get(chars);

    gotoxy(x, y++);

    while(!stream.eof()){
        if (chars != '\n'){
            cout << chars;
        } else gotoxy(x, y++);

        stream.get(chars);
    }

    stream.close();
    cout << endl;
    system("pause");
}

void Instrucciones(){
    char chars;
    ifstream stream;

    stream.open("textos//Instrucciones.txt");
    stream.get(chars);

    while(! stream.eof()){
        cout << chars;
        stream.get(chars);
    }

    stream.close();
    cout << endl;
    system("pause");
}

bool JuegaReversi(){
    espacioCasilla JugadorActual = NEGRA, tablero[10][10];
    bool PosiblesMovimientos[9][9] = {};
    int x, y, score1 = 2, score2 = 2, fichasEnTablero = 4, turnosSinMov = 0;
    bool posible;

    DibujaTablero();

    InicializaTablero(tablero);
    ImprimeTablero(tablero);
/*
    do{
        posible = false;
        for(int i = 1; i < 9; i++)
            for(int j = 1; j < 9; j++){
                if (MovimientoPosible(i, j, JugadorActual, tablero)){
                    posible = true;
                    PosiblesMovimientos[i][j] = true;
                }
            }

        if (posible){
            turnosSinMov = 0;

            do{
                CapturaMovimiento(x, y);
                posible = PosiblesMovimientos[x][y];
                if (!posible) ImprimeMovimientoIncorrecto();

            }while(!posible);

            RealizaMovimiento(tablero, x, y, JugadorActual, (JugadorActual == NEGRA ? score1 : score2), (JugadorActual == NEGRA ? score2 : score1));
            ImprimeTablero();
            fichasEnTablero++;

        }else{
            turnosSinMov++;
        }

        ImprimeTablero(espacioCasilla Tab[][10]);

        JugadorActual = (JugadorActual == NEGRA ? BLANCA : NEGRA);

    }while(fichasEnTablero < 64 && turnosSinMov < 2);
*/
    system("pause");
    //return JugarDeNuevo();
    return false;


}
