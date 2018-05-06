/*
Nombre: .cpp
Autor: Raúl Octavio Murcia Yocupicio
Fecha:
Descripción:
*/

#define _WIN32_WINNT 0x0500

#include <iostream>
#include <cstdlib>
#include <windows.h>

void ImprimeJugar(int x, int y, int t);
void ImprimeTitulo(int x, int y, int t);
void ImprimeInstrucciones(int x, int y, int t);
void ImprimeSalir(int x, int y, int t);
void Subraya(int eleccion, int xMedio, int y0, int y1, int y2, char c);

using namespace std;

enum {JUGAR, INSTRUCCIONES, SALIR};

int main()
{
    system("pause");

    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    int alto = (r.bottom - r.top) / 12 - 25, ancho = (r.right - r.left) / 8;

    ImprimeTitulo((ancho - 61)/2, (alto - 7)/2, 3);
    ImprimeJugar((ancho - 28)/2, (alto - 4)/2 + 10, 1);
    ImprimeInstrucciones((ancho - 61)/2, (alto - 4)/2 + 17, 1);
    ImprimeSalir((ancho - 24)/2, (alto - 4)/2 + 24, 1);

    int eleccion = JUGAR;
    Subraya(eleccion, ancho/2, (alto - 4)/2 + 14, (alto - 4)/2 + 21, (alto - 4)/2 + 28, '_');

    do{
        if(GetAsyncKeyState(VK_UP) & 0x8000){
            Subraya(eleccion, ancho/2, (alto - 4)/2 + 14, (alto - 4)/2 + 21, (alto - 4)/2 + 28, ' ');
            eleccion--;
            if (eleccion < 0) eleccion += 3;
            Subraya(eleccion, ancho/2, (alto - 4)/2 + 14, (alto - 4)/2 + 21, (alto - 4)/2 + 28, '_');
            Sleep(200);
        }
        if(GetAsyncKeyState(VK_DOWN) & 0x8000){
            Subraya(eleccion, ancho/2, (alto - 4)/2 + 14, (alto - 4)/2 + 21, (alto - 4)/2 + 28, ' ');
            eleccion++;
            if (eleccion > 2) eleccion -= 3;
            Subraya(eleccion, ancho/2, (alto - 4)/2 + 14, (alto - 4)/2 + 21, (alto - 4)/2 + 28, '_');
            Sleep(200);
        }
        if(GetAsyncKeyState(VK_RETURN) & 0x8000) break;

        }while(true);


    system("pause");
    return 0;
}

void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD coord = {x-1, y-1};
    SetConsoleCursorPosition (handle, coord);
}

void Subraya(int eleccion, int xMedio, int y0, int y1, int y2, char c)
{
    switch(eleccion){
        case JUGAR:
            gotoxy (xMedio - 14, y0);
            for(int i = 0; i < 28; i++) cout << c;
            break;
        case INSTRUCCIONES:
            gotoxy (xMedio - 30, y1);
            for(int i = 0; i < 61; i++) cout << c;
            break;
        case SALIR:
            gotoxy (xMedio - 12, y2);
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
