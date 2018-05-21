/*
Nombre: .cpp
Autor: Raúl Octavio Murcia Yocupicio
Fecha:
Descripción:
*/

#include <iostream>
#include <windows.h>

#include "TitulosMenu.h"
#include "ManejoConsola.h"

using namespace std;

void Subraya(int eleccion, char c)
{
    static int eleccionAnterior = JUGAR;
    int xMedio = ANCHOVENTANA / 2;

    switch(eleccionAnterior){ //Se borra el subrayado anterior
        case JUGAR:
            gotoxy (xMedio - 14, ALTOVENTANA / 2 + 4);
            for(int i = 0; i < 27; i++) cout << ' ';
            break;
        case INSTRUCCIONES:
            gotoxy (xMedio - 31, ALTOVENTANA / 2 + 11);
            for(int i = 0; i < 61; i++) cout << ' ';
            break;
        case CREDITOS:
            gotoxy(xMedio - 19, ALTOVENTANA / 2 + 18);
            for (int i = 0; i < 37; i++) cout << ' ';
            break;
        case SALIR:
            gotoxy (xMedio - 12, ALTOVENTANA / 2 + 25);
            for(int i = 0; i < 24; i++) cout << ' ';
    }

    switch(eleccion){
        case JUGAR:
            gotoxy (xMedio - 14, ALTOVENTANA / 2 + 4);
            for(int i = 0; i < 27; i++) cout << c;
            break;
        case INSTRUCCIONES:
            gotoxy (xMedio - 31, ALTOVENTANA / 2 + 11);
            for(int i = 0; i < 61; i++) cout << c;
            break;
        case CREDITOS:
            gotoxy(xMedio - 19, ALTOVENTANA / 2 + 18);
            for (int i = 0; i < 37; i++) cout << c;
            break;
        case SALIR:
            gotoxy (xMedio - 12, ALTOVENTANA / 2 + 25);
            for(int i = 0; i < 24; i++) cout << c;
    }

    Beep(440, 50);

    eleccionAnterior = eleccion;
}

void ImprimeTitulo(int t)
{
    int c = 61;
    int x = (ANCHOVENTANA - c) / 2, y = ALTOVENTANA / 4 - 3;

    string var0 = " ______    _______  __   __  _______  ______    _______  ___ ";
    string var1 = "|    _ |  |       ||  | |  ||       ||    _ |  |       ||   |";
    string var2 = "|   | ||  |    ___||  |_|  ||    ___||   | ||  |  _____||   |";
    string var3 = "|   |_||_ |   |___ |       ||   |___ |   |_||_ | |_____ |   |";
    string var4 = "|    __  ||    ___||       ||    ___||    __  ||_____  ||   |";
    string var5 = "|   |  | ||   |___  |     | |   |___ |   |  | | _____| ||   |";
    string var6 = "|___|  |_||_______|  |___|  |_______||___|  |_||_______||___|";

    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        cout << var0[i];
        Sleep(t);
    }
    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        cout << var1[i];
        Sleep(t);
    }
    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        cout << var2[i];
        Sleep(t);
    }
    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        cout << var3[i];
        Sleep(t);
    }
    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        cout << var4[i];
        Sleep(t);
    }
    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        cout << var5[i];
        Sleep(t);
    }
    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        cout << var6[i];
        Sleep(t);
    }
    gotoxy(x, y++);
}

void ImprimeJugar(int t)
{
    int c = 28;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 2;

    string var0 = "    _ _   _  ___   _   ___  ";
    string var1 = " _ | | | | |/ __| /_\\ | _ \\ ";
    string var2 = "| || | |_| | (_ |/ _ \\|   / ";
    string var3 = " \\__/ \\___/ \\___/_/ \\_\\_|_\\ ";

    Sleep(t);

    gotoxy(x, y++);
    cout << var0;

    gotoxy(x, y++);
    cout << var1;

    gotoxy(x, y++);
    cout << var2;

    gotoxy(x, y++);
    cout << var3;
}

void ImprimeInstrucciones(int t)
{
    int c = 61;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 2 + 7;

    string var0 = " ___ _  _ ___ _____ ___ _   _  ___ ___ ___ ___  _  _ ___ ___ ";
    string var1 = "|_ _| \\| / __|_   _| _ \\ | | |/ __/ __|_ _/ _ \\| \\| | __/ __|";
    string var2 = " | || .` \\__ \\ | | |   / |_| | (_| (__ | | (_) | .` | _|\\__ \\";
    string var3 = "|___|_|\\_|___/ |_| |_|_\\\\___/ \\___\\___|___\\___/|_|\\_|___|___/";

    Sleep(t);

    gotoxy(x, y++);
    cout << var0;

    gotoxy(x, y++);
    cout << var1;

    gotoxy(x, y++);
    cout << var2;

    gotoxy(x, y++);
    cout << var3;
}

void ImprimeCreditos(int t)
{
    int c = 38;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 2 + 14;

    string var0 = "  ___ ___ ___ ___ ___ _____ ___  ___    ";
    string var1 = " / __| _ \\ __|   \\_ _|_   _/ _ \\/ __|";
    string var2 = "| (__|   / _|| |) | |  | || (_) \\__ \\ ";
    string var3 = " \\___|_|_\\___|___/___| |_| \\___/|___/";

    Sleep(t);

    gotoxy(x, y++);
    cout << var0;

    gotoxy(x, y++);
    cout << var1;

    gotoxy(x, y++);
    cout << var2;

    gotoxy(x, y++);
    cout << var3;
}

void ImprimeSalir(int t)
{
    int c = 24;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 2 + 21;

    string var0 = " ___   _   _    ___ ___ ";
    string var1 = "/ __| /_\\ | |  |_ _| _ \\";
    string var2 = "\\__ \\/ _ \\| |__ | ||   /";
    string var3 = "|___/_/ \\_\\____|___|_|_\\";

    Sleep(t);

    gotoxy(x, y++);
    cout << var0;

    gotoxy(x, y++);
    cout << var1;

    gotoxy(x, y++);
    cout << var2;

    gotoxy(x, y++);
    cout << var3;
}
