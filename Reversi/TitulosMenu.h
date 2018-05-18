#ifndef TITULOSMENU_H_INCLUDED
#define TITULOSMENU_H_INCLUDED

enum {JUGAR, INSTRUCCIONES, CREDITOS, SALIR};

void Subraya(int eleccion, char c);

void ImprimeTitulo(int t);

void ImprimeJugar(int t);

void ImprimeInstrucciones(int t);

void ImprimeCreditos(int t);

void ImprimeSalir(int t);

#endif // TITULOSMENU_H_INCLUDED
