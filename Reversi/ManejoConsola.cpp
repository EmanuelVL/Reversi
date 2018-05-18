
#include "ManejoConsola.h" /*Se define antes que windows.h
                            debido a que se definen constantes
                            que se ocupan antes*/
#include <windows.h>
#include <cstdio>

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
