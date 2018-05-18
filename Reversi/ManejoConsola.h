#ifndef MANEJOCONSOLA_H_INCLUDED
#define MANEJOCONSOLA_H_INCLUDED

#define ANCHOVENTANA 120
#define ALTOVENTANA 60

// Estados del cursor
enum estadoCursor{APAGADO, ENCENDIDO};
// Modos del cursor
enum modoCursor{MINI = 5, NORMAL = 20, SOLIDO = 80};

void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);

void AjustaVentana();

void gotoxy(int x, int y);

#endif // MANEJOCONSOLA_H_INCLUDED
