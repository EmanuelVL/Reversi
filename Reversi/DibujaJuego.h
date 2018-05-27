#ifndef DIBUJAJUEGO_H_INCLUDED
#define DIBUJAJUEGO_H_INCLUDED

void DibujaFicha(int x, int y, miColor color);

void DibujaTablero();

void ImprimeMovimientoIncorrecto();

void ImprimeCasilla(int col, int ren);

void ResaltaCasilla(int col, int ren, miColor color);

void ImprimirNumero(int num, int x, int y);

void CapturaDibujaNombres(char nombre1[], char nombre2[]);

#endif // DIBUJAJUEGO_H_INCLUDED
