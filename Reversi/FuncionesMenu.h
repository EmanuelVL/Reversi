#ifndef FUNCIONESMENU_H_INCLUDED
#define FUNCIONESMENU_H_INCLUDED

enum {JUGAR, INSTRUCCIONES, CREDITOS, SALIR};

void Subraya(int eleccion, int xMedio, int y0, int y1, int y2, int y3, char c);

void ImprimeTitulo(int x, int y, int t);

void ImprimeJugar(int x, int y, int t);

void ImprimeInstrucciones(int x, int y, int t);

void ImprimeSalir(int x, int y, int t);

void ImprimeCreditos(int x, int y, int t);

#endif // FUNCIONESMENU_H_INCLUDED
