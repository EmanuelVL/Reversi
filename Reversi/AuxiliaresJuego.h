#ifndef AUXILIARESJUEGO_H_INCLUDED
#define AUXILIARESJUEGO_H_INCLUDED

enum espacioCasilla{VACIO, BLANCA, NEGRA};

bool MovimientoPosible(espacioCasilla Tab[][10], espacioCasilla Jugador, int x, int y);

void RealizaMovimiento(espacioCasilla Tab[][10], int x, int y, espacioCasilla Jugador, int &scoreJugador, int &scoreOponente);

void ColocarFicha(int x, int y, miColor color);

void InicializaTablero(espacioCasilla Tab[][10]);

void ImprimeTablero(espacioCasilla Tab[][10]);

void CapturaMovimiento(int &x, int &y, miColor color);

void ImprimeScores(int score1, int score2);

#endif // AUXILIARESJUEGO_H_INCLUDED
