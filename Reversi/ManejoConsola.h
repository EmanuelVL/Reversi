#ifndef MANEJOCONSOLA_H_INCLUDED
#define MANEJOCONSOLA_H_INCLUDED

#define _WIN32_WINNT 0x0500

// Estados del cursor
enum estadoCursor{APAGADO, ENCENDIDO};
// Modos del cursor
enum modoCursor{MINI = 5, NORMAL = 20, SOLIDO = 80};

void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);

void MaximizaVentana();

void gotoxy(int x, int y);

void ObtieneDimensionesVentana(int &ancho, int &alto);

#endif // MANEJOCONSOLA_H_INCLUDED
