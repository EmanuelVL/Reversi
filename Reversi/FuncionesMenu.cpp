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


#include <windows.h>

using namespace std;

void Creditos(){
    int x = (ANCHOVENTANA - 24)/ 2, y = (ALTOVENTANA - 18) / 2 - 5;
    char linea[50];
    ifstream stream;

    stream.open("textos//Creditos.txt");

    gotoxy(x, y++);

    while(!stream.eof()){
        stream.getline(linea, 50, '\n');
        cout << linea;
        gotoxy(x, y++);
    }

    stream.close();
    gotoxy((ANCHOVENTANA - 35) / 2, y);
    system("pause");
}

void Instrucciones(){
    char linea[200];
    ifstream stream;

    stream.open("textos//Instrucciones.txt");

    while(! stream.eof()){
        stream.getline(linea, 200, '\n');
        cout << linea << endl;
    }

    stream.close();
    cout << endl;
    system("pause");
}

bool JuegaReversi(){
    espacioCasilla JugadorActual = NEGRA, tablero[10][10];
    bool PosiblesMovimientos[9][9], posible;
    int x, y, score1 = 2, score2 = 2, fichasEnTablero = 4, turnosSinMov = 0;
    char nombreNegras[10], nombreBlancas[10];

    CapturaDibujaNombres(nombreNegras, nombreBlancas);

    DibujaTablero();

    InicializaTablero(tablero);
    ImprimeTablero(tablero);

    ImprimeScores(score1, score2);

    do{

        posible = false;

        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                PosiblesMovimientos[i][j] = false;

        for(int i = 1; i < 9; i++)
            for(int j = 1; j < 9; j++){
                if (MovimientoPosible(tablero, JugadorActual, i, j)){
                    posible = true;
                    PosiblesMovimientos[i][j] = true;
                }
            }

        if (posible){
            turnosSinMov = 0;

            do{
                CapturaMovimiento(x, y, JugadorActual == NEGRA ? NEGRO : BLANCO);
                posible = PosiblesMovimientos[x][y];
                if (!posible) {
                    ImprimeMovimientoIncorrecto();
                }

            }while(!posible);

            RealizaMovimiento(tablero, x, y, JugadorActual, (JugadorActual == NEGRA ? score1 : score2), (JugadorActual == NEGRA ? score2 : score1));

            if(JugadorActual == NEGRA) score1++;
            else score2++;

            ImprimeTablero(tablero);
            fichasEnTablero++;

        }else{
            turnosSinMov++;
        }

        ImprimeScores(score1, score2);

        JugadorActual = (JugadorActual == NEGRA ? BLANCA : NEGRA);

    }while(fichasEnTablero < 64 && turnosSinMov < 2);

    system("pause");
    //return JugarDeNuevo();
    return false;


}
