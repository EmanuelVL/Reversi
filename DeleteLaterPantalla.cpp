/*
Nombre del archivo:
Nombre del autor: Sandoval del Hoyo María Ximena
Fecha:
Descripción:
*/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cstdio>
#include <conio.h>

#define ANCHOVENTANA 120
#define ALTOVENTANA 60

#define FLECHA_ARRIBA 72
#define FLECHA_IZQ 75
#define FLECHA_DER 77
#define FLECHA_ABAJO 80
#define ENTER 13



// Estados del cursor
enum estadoCursor{APAGADO, ENCENDIDO};
// Modos del cursor
enum modoCursor{MINI = 5, NORMAL = 20, SOLIDO = 80};

void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);
void AjustaVentana();
void gotoxy(int x, int y);

using namespace std;

void ImprimeFinDelJuego(int t);
void ImprimeGana(int t);
void ImprimeJugador1(int t);
void ImprimeJugador2(int t);
void ImprimeEmpate(int t);
void ImprimeVolverAJugar(int t);
void ImprimeSi(int t);
void ImprimeNo(int t);
void Subraya(int eleccion, char c);


enum {JUGADOR1, JUGADOR2, EMPATE};
enum {SI, NO};
int main()
{
    char tecla = '\0';
    int Resultado = EMPATE;
    int eleccion = SI;

    int xMedio = ANCHOVENTANA/2;
    ImprimeFinDelJuego(3);

    switch (Resultado){
    case JUGADOR1:
        ImprimeGana(0);
        ImprimeJugador1(0);
        break;
    case JUGADOR2:
        ImprimeGana(0);
        ImprimeJugador2(0);
        break;
    case EMPATE:
        ImprimeEmpate(0);
        break;
    }

    ImprimeVolverAJugar(0);
    ImprimeSi(0);
    ImprimeNo(0);
    Subraya(eleccion, char(205));

     while(tecla != ENTER){
        if (kbhit()){
            tecla = getch();

            if(tecla == FLECHA_IZQ){
                eleccion--;
                if (eleccion < 0) eleccion += 2; //Se mantienen los límites del seleccionador
                Subraya(eleccion, char(205));
            }

            if(tecla == FLECHA_DER){
                eleccion++;
                if (eleccion > 2) eleccion -= 2; //Se mantienen los límites del seleccionador
                Subraya(eleccion, char(205));
            }
        }
    }

    return eleccion;
}



void ImprimeFinDelJuego(int t)
{
    int c =59;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 5;

    string var0 = "  ___ ___ _  _   ___  ___ _         _ _   _ ___ ___  ___  ";
    string var1 = " | __|_ _| \\| | |   \\| __| |     _ | | | | | __/ __|/ _ \\ ";
    string var2 = " | _| | || .` | | |) | _|| |__  | || | |_| | _| (_ | (_) |";
    string var3 = " |_| |___|_|\\_| |___/|___|____|  \\__/ \\___/|___\\___|\\___/ ";

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

void ImprimeGana(int t)
{
    int c =26;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 4 + 5;

    string var0 = "   ___                  _ ";
    string var1 = "  / __|__ _ _ _  __ _  (_)";
    string var2 = " | (_ / _` | \' \\/ _` |  _ ";
    string var3 = "  \\___\\__,_|_||_\\__,_| (_)";

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


void ImprimeJugador1(int t)
{
    int c =39;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 4 + 9;

    string var0 = "     _                   _           _ ";
    string var1 = "  _ | |_  _ __ _ __ _ __| |___ _ _  / |";
    string var2 = " | || | || / _` / _` / _` / _ \\ \'_| | |";
    string var3 = "  \\__/ \\_,_\\__, \\__,_\\__,_\\___/_|   |_|";
    string var4 = "           |___/                       ";

    Sleep(t);

    gotoxy(x, y++);
    cout << var0;

    gotoxy(x, y++);
    cout << var1;

    gotoxy(x, y++);
    cout << var2;

    gotoxy(x, y++);
    cout << var3;

    gotoxy(x, y++);
    cout << var4;
}

void ImprimeJugador2(int t)
{
    int c =41;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 4 + 9;

    string var0 = "     _                   _           ___ ";
    string var1 = "  _ | |_  _ __ _ __ _ __| |___ _ _  |_  )";
    string var2 = " | || | || / _` / _` / _` / _ \\ \'_|  / / ";
    string var3 = "  \\__/ \\_,_\\__, \\__,_\\__,_\\___/_|   /___|";
    string var4 = "           |___/                         ";

    Sleep(t);

    gotoxy(x, y++);
    cout << var0;

    gotoxy(x, y++);
    cout << var1;

    gotoxy(x, y++);
    cout << var2;

    gotoxy(x, y++);
    cout << var3;

    gotoxy(x, y++);
    cout << var4;
}

void ImprimeEmpate(int t)
{
    int c =31;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 4 + 5;

    string var0 = "  ___                  _       ";
    string var1 = " | __|_ __  _ __  __ _| |_ ___ ";
    string var2 = " | _|| \'  \\| \'_ \\/ _` |  _/ -_)";
    string var3 = " |___|_|_|_| .__/\\__,_|\\__\\___|";
    string var4 = "           |_|                 ";

    Sleep(t);

    gotoxy(x, y++);
    cout << var0;

    gotoxy(x, y++);
    cout << var1;

    gotoxy(x, y++);
    cout << var2;

    gotoxy(x, y++);
    cout << var3;

    gotoxy(x, y++);
    cout << var4;
}

void ImprimeVolverAJugar(int t)
{
    int c =68;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 2;

    string var0 = "   _   __   __   _                        _                      ___ ";
    string var1 = "  (_)  \\ \\ / /__| |_ _____ _ _   __ _    (_)_  _ __ _ __ _ _ _  |__ \\";
    string var2 = " / /_   \\ V / _ \\ \\ V / -_) \'_| / _` |   | | || / _` / _` | \'_|   /_/";
    string var3 = " \\___|   \\_/\\___/_|\\_/\\___|_|   \\__,_|  _/ |\\_,_\\__, \\__,_|_|    (_) ";
    string var4 = "                                       |__/     |___/                ";

    Sleep(t);

    gotoxy(x, y++);
    cout << var0;

    gotoxy(x, y++);
    cout << var1;

    gotoxy(x, y++);
    cout << var2;

    gotoxy(x, y++);
    cout << var3;

    gotoxy(x, y++);
    cout << var4;
}

void ImprimeSi(int t)
{
    int c =8;
    int x = (ANCHOVENTANA - c)/3, y = ALTOVENTANA / 2 + 6;

    string var0 = "  ___ _ ";
    string var1 = " / __(_)";
    string var2 = " \\__ \\ |";
    string var3 = " |___/_|";

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

void ImprimeNo(int t)
{
    int c =11;
    int x = 2*(ANCHOVENTANA - c)/3, y = ALTOVENTANA / 2 + 6;

    string var0 = "  _  _     ";
    string var1 = " | \\| |___ ";
    string var2 = " | .` / _ \\";
    string var3 = " |_|\\_\\___/";

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

void Subraya(int eleccion, char c)
{
    static int eleccionAnterior = NO;

    switch(eleccionAnterior){ //Se borra el subrayado anterior
        case SI:
            gotoxy ((ANCHOVENTANA - 8)/3 + 1, ALTOVENTANA / 2 + 10);
            for(int i = 0; i < 7; i++) cout << ' ';
            break;
        case NO:
            gotoxy (2*(ANCHOVENTANA - 11)/3 + 1, ALTOVENTANA / 2 + 10);
            for(int i = 0; i < 10; i++) cout << ' ';
            break;
    }

    switch(eleccion){
        case SI:
            gotoxy ((ANCHOVENTANA - 8)/3 + 1, ALTOVENTANA / 2 + 10);
            for(int i = 0; i < 7; i++) cout << c;
            break;
        case NO:
            gotoxy (2*(ANCHOVENTANA - 11)/3 + 1, ALTOVENTANA / 2 + 10);
            for(int i = 0; i < 10; i++) cout << c;
            break;
    }

    Beep(440, 50);

    eleccionAnterior = eleccion;

}


void CambiaCursor(estadoCursor estado, modoCursor modo/* = NORMAL*/)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;
    ConCurInf.bVisible = estado;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}

void AjustaVentana(){
    char str[60];
    sprintf(str, "mode con: cols=%d lines=%d", ANCHOVENTANA, ALTOVENTANA);
    system(str); //Enviamos la cadena con la instrucción a la consola
}

void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD coord = {x-1, y-1};
    SetConsoleCursorPosition (handle, coord);
}

