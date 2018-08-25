#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Alumnos.h"

//Menu inicial
void MenuInicial();

//Despliega y lee la opcion para el menu principal de XX opciones
void MenuPrincipal(int &opcion, bool &isOP1Cargada);

//Seccion mensajes respecto a menu

//Mensaje para indicar segun la flag, para la opcion XX - XX del menu principal
void MensajeErrorAlumnosVacios();

//Emite mensaje, espera anyKey y limpia la pantalla dependiendo del SO
void LimpiarYPausa();

void OpcionCarga(bool &booleanoAcargar);

void MensajeSalida();

void logo();

#endif // MENU_H_INCLUDED
