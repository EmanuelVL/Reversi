/*
Nombre: .cpp
Autor: Raúl Octavio Murcia Yocupicio
Fecha:
Descripción:
*/

#define _WIN32_WINNT 0x0500

#define FLECHA_ARRIBA 72
#define FLECHA_IZQ 75
#define FLECHA_DER 77
#define FLECHA_ABAJO 80
#define ENTER 13

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

// Estados del cursor
enum estadoCursor{APAGADO, ENCENDIDO};
// Modos del cursor
enum modoCursor{MINI = 5, NORMAL = 20, SOLIDO = 80};

void ImprimeJugar(int x, int y, int t);
void ImprimeTitulo(int x, int y, int t);
void ImprimeInstrucciones(int x, int y, int t);
void ImprimeCreditos(int x, int y, int t);
void ImprimeSalir(int x, int y, int t);
void Subraya(int eleccion, int xMedio, int y0, int y1, int y2, int y3, char c);
void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);

using namespace std;

enum {JUGAR, INSTRUCCIONES, CREDITOS, SALIR};

int main()
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    CambiaCursor(APAGADO);

    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    int alto = (r.bottom - r.top) / 12;
    int ancho = (r.right - r.left) / 8;

    ImprimeTitulo((ancho - 61)/2, alto/4, 3);

    int yJugar = alto/2;
    int yInstrucciones = yJugar + 7;
    int yCreditos = yInstrucciones + 7;
    int ySalir = yCreditos + 7;

    ImprimeJugar((ancho - 28)/2, yJugar, 0);
    ImprimeInstrucciones((ancho - 61)/2, yInstrucciones, 0);
    ImprimeCreditos((ancho - 38)/2, yCreditos, 0);
    ImprimeSalir((ancho - 24)/2, ySalir, 0);

    int eleccion = JUGAR;
    char tecla;
    Subraya(eleccion, ancho/2, yJugar + 4, yInstrucciones + 4, yCreditos + 4, ySalir + 4, char(205));

    while(true){
        if (kbhit()){
            tecla = getch();

            if(tecla == FLECHA_ARRIBA){
                Subraya(eleccion, ancho/2, yJugar + 4, yInstrucciones + 4, yCreditos + 4, ySalir + 4, ' ');
                eleccion--;
                if (eleccion < 0) eleccion += 4;
                Subraya(eleccion, ancho/2, yJugar + 4, yInstrucciones + 4, yCreditos + 4, ySalir + 4, char(205));
            }

            if(tecla == FLECHA_ABAJO){
                Subraya(eleccion, ancho/2, yJugar + 4, yInstrucciones + 4, yCreditos + 4, ySalir + 4, ' ');
                eleccion++;
                if (eleccion > 3) eleccion -= 4;
                Subraya(eleccion, ancho/2, yJugar + 4, yInstrucciones + 4, yCreditos + 4, ySalir + 4, char(205));
            }

            if(tecla == ENTER) break;
        }
    }


    system("pause");
    return 0;
}

void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD coord = {x-1, y-1};
    SetConsoleCursorPosition (handle, coord);
}

void CambiaCursor(estadoCursor estado, modoCursor modo)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;
    ConCurInf.bVisible = estado;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}

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
