/*
Nombre: .cpp
Autor: Raúl Octavio Murcia Yocupicio
Fecha:
Descripción:
*/

#include <iostream>
#include <windows.h>

#include "FuncionesMenu.h"
#include "ManejoConsola.h"

using namespace std;

void Subraya(int eleccion, int xMedio, int y0, int y1, int y2, int y3, char c)
{
    switch(eleccion){
        case JUGAR:
            gotoxy (xMedio - 14, y0);
            for(int i = 0; i < 27; i++) cout << c;
            break;
        case INSTRUCCIONES:
            gotoxy (xMedio - 31, y1);
            for(int i = 0; i < 61; i++) cout << c;
            break;
        case CREDITOS:
            gotoxy(xMedio - 19, y2);
            for (int i = 0; i < 37; i++) cout << c;
            break;
        case SALIR:
            gotoxy (xMedio - 12, y3);
            for(int i = 0; i < 24; i++) cout << c;
    }
}

void ImprimeTitulo(int x, int y, int t)
{
    int c = 61;

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

void ImprimeJugar(int x, int y, int t)
{
    string var0 = "    _ _   _  ___   _   ___  ";
    string var1 = " _ | | | | |/ __| /_\\ | _ \\ ";
    string var2 = "| || | |_| | (_ |/ _ \\|   / ";
    string var3 = " \\__/ \\___/ \\___/_/ \\_\\_|_\\ ";

    int c = 28;

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
}

void ImprimeInstrucciones(int x, int y, int t)
{
    string var0 = " ___ _  _ ___ _____ ___ _   _  ___ ___ ___ ___  _  _ ___ ___ ";
    string var1 = "|_ _| \\| / __|_   _| _ \\ | | |/ __/ __|_ _/ _ \\| \\| | __/ __|";
    string var2 = " | || .` \\__ \\ | | |   / |_| | (_| (__ | | (_) | .` | _|\\__ \\";
    string var3 = "|___|_|\\_|___/ |_| |_|_\\\\___/ \\___\\___|___\\___/|_|\\_|___|___/";

    int c = 61;

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
}

void ImprimeSalir(int x, int y, int t)
{
    string var0 = " ___   _   _    ___ ___ ";
    string var1 = "/ __| /_\\ | |  |_ _| _ \\";
    string var2 = "\\__ \\/ _ \\| |__ | ||   /";
    string var3 = "|___/_/ \\_\\____|___|_|_\\";

    int c = 24;

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
}

void ImprimeCreditos(int x, int y, int t)
{
    string var0 = "  ___ ___ ___ ___ ___ _____ ___  ___    ";
    string var1 = " / __| _ \\ __|   \\_ _|_   _/ _ \\/ __|";
    string var2 = "| (__|   / _|| |) | |  | || (_) \\__ \\ ";
    string var3 = " \\___|_|_\\___|___/___| |_| \\___/|___/";

    int c = 38;

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
}
