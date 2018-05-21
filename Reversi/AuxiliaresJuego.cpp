
#include "ManejoConsola.h"
#include "DibujaJuego.h"
#include "AuxiliaresJuego.h"

bool MovimientoPosible(espacioCasilla Tab[][10], espacioCasilla Jugador, int x, int y){
    espacioCasilla Oponente = (Jugador = BLANCA ? NEGRA : BLANCA);

    for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; (i == 0 ? j +=2 : j++)){ //Saltando el caso i = 0, j = 0
            int dX = i, dY = j;
            while(Tab[x + dX][y + dY] == Oponente && x + dX > 0 && x + dX < 9 && y + dY > 0 && y + dY < 9){
                dX += i;
                dY += j;
            }

            if(Tab[x + dX][y + dY] == Jugador && dX != i) return true;
        }

    return false;
}

void RealizaMovimiento(espacioCasilla Tab[][10], int x, int y, espacioCasilla Jugador, int &scoreJugador, int &scoreOponente){

    espacioCasilla Oponente = (Jugador = BLANCA ? NEGRA : BLANCA);

    for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; (i == 0 ? j +=2 : j++)){ //Saltando el caso i = 0, j = 0
            int dX = i, dY = j;

            while(x + dX > 0 && x + dX < 9 && y + dY > 0 && y + dY < 9 && Tab[x + dX][y + dY] == Oponente){

                dX += i;
                dY += j;
            }

            if(Tab[x + dX][y + dY] == Jugador && dX != i){
                dX -= i;
                dY -= j;
                while(Tab[x + dX][y + dY] == Oponente){
                    Tab[x + dX][y + dY] = Jugador;
                    scoreJugador++;
                    scoreOponente--;
                    dX -= i;
                    dY -= j;
                }
            }
        }

    Tab[x][y] = Jugador;

}

void ColocarFicha(int x, int y, miColor color){
    DibujaFicha(((x-1)*8)+((((ANCHOVENTANA-57)/2)+1)-((x-1)*2)+(x-1)), ((y-1)*4)+((((ALTOVENTANA-40)/2)+1)+((y-1))), miColor(color));
}

void InicializaTablero(espacioCasilla Tab[][10]){
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            Tab[i][j] = VACIO;

    Tab[4][4] = BLANCA;
    Tab[4][5] = NEGRA;
    Tab[5][4] = NEGRA;
    Tab[5][5] = BLANCA;
}

void ImprimeTablero(espacioCasilla Tab[][10]){
    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++)
            if (Tab[i][j] == BLANCA) ColocarFicha(i, j, BLANCO);
            else if (Tab[i][j] == NEGRA) ColocarFicha(i, j, NEGRO);
}
