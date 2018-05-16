
#include <iostream>
#include <cstdlib>
#include <conio.h>


#include <windows.h>

#include "ReconocimientoTeclado.h"
#include "FuncionesMenu.h"
#include "ManejoConsola.h"

int Menu();

using namespace std;

int main()
{
    int eleccion;

    do{
        system("cls");
        eleccion = Menu();

        switch(eleccion){
            case JUGAR:
                /*
                do{
                    bool JuegaDeNuevo = JuegaReversi();
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
    int ancho, alto;

    MaximizaVentana(); //Maximiza pantalla
    CambiaCursor(APAGADO);
    ObtieneDimensionesVentana(ancho, alto); //Obtiene las dimensiones en carácteres

    ImprimeTitulo((ancho - 61)/2, alto/4, 3); //Se imprime a una cuarta parte del alto

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
                Beep(440, 50);
            }

            if(tecla == FLECHA_ABAJO){
                Subraya(eleccion, ancho/2, yJugar + 4, yInstrucciones + 4, yCreditos + 4, ySalir + 4, ' ');
                eleccion++;
                if (eleccion > 3) eleccion -= 4;
                Subraya(eleccion, ancho/2, yJugar + 4, yInstrucciones + 4, yCreditos + 4, ySalir + 4, char(205));
                Beep(440, 50);
            }

            if(tecla == ENTER) break;
        }
    }

    return eleccion;
}
