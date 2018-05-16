
#include "ManejoConsola.h" /*Se define antes que windows.h
                            debido a que se definen constantes
                            que se ocupan antes*/
#include <windows.h>

void CambiaCursor(estadoCursor estado, modoCursor modo/* = NORMAL*/)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;
    ConCurInf.bVisible = estado;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}

void MaximizaVentana(){
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD coord = {x-1, y-1};
    SetConsoleCursorPosition (handle, coord);
}

void ObtieneDimensionesVentana(int &ancho, int &alto)
{
    HWND console = GetConsoleWindow(); //Obtiene dimensiones de la ventana en pixeles
    RECT r;
    GetWindowRect(console, &r);

    alto = (r.bottom - r.top) / 12; //Se convierte alto y ancho a caracteres
    ancho = (r.right - r.left) / 8;

}
