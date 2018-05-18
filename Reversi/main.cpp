
#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "ReconocimientoTeclado.h"
#include "TitulosMenu.h"
#include "ManejoConsola.h"

int Menu();
bool JuegaReversi();

using namespace std;

int main()
{
    int eleccion;

    do{
        system("cls");

        eleccion = Menu();

        system("cls");

        switch(eleccion){
            case JUGAR:
/*
                bool JuegaDeNuevo;

                do{
                    JuegaDeNuevo = JuegaReversi();
                }while(JuegaDeNuevo);
*/
                break;
            case INSTRUCCIONES:
                break;
            case CREDITOS:
                break;
            case SALIR:
                break;
        }

    }while(eleccion != SALIR);

    return 0;
}

int Menu()
{
    int eleccion = JUGAR;
    char tecla = '\0';

    AjustaVentana(); //Ajusta el tamaño de la pantalla
    CambiaCursor(APAGADO); //Oculta el cursor

    ImprimeTitulo(3); //Se imprimen los títulos

    ImprimeJugar(50);
    ImprimeInstrucciones(50);    ImprimeCreditos(50);
    ImprimeSalir(50);

    Subraya(eleccion, char(205));

    while(tecla != ENTER){
        if (kbhit()){
            tecla = getch();

            if(tecla == FLECHA_ARRIBA){
                eleccion--;
                if (eleccion < 0) eleccion += 4; //Se mantienen los límites del seleccionador
                Subraya(eleccion, char(205));
            }

            if(tecla == FLECHA_ABAJO){
                eleccion++;
                if (eleccion > 3) eleccion -= 4; //Se mantienen los límites del seleccionador
                Subraya(eleccion, char(205));
            }
        }
    }

    return eleccion;
}
