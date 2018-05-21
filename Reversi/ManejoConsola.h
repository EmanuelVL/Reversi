#ifndef MANEJOCONSOLA_H_INCLUDED
#define MANEJOCONSOLA_H_INCLUDED

#define ANCHOVENTANA 120
#define ALTOVENTANA 60

// Estados del cursor
enum estadoCursor{APAGADO, ENCENDIDO};
// Modos del cursor
enum modoCursor{MINI = 5, NORMAL = 20, SOLIDO = 80};

enum miColor{NEGRO, AZUL, VERDE, AGUAMARINA,
            ROJO, PURPURA, AMARILLO, GRISCLARO,
            GRIS, AZULCLARO, VERDECLARO, AGUAMARINACLARO,
            ROJOCLARO, PURPURACLARO, AMARILLOCLARO, BLANCO};

void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);

void AjustaVentana();

void gotoxy(int x, int y);

void EstableceColor(miColor colorFondo, miColor colorTexto);

#endif // MANEJOCONSOLA_H_INCLUDED
