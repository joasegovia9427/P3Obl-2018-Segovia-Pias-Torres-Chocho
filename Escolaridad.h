#ifndef Escolaridad_H_INCLUDED
#define Escolaridad_H_INCLUDED

#include "Fecha.h"
#include "Asignaturas.h"

typedef struct{
    int idAsignatura;
    Fecha fechaAprobacion;
    float calificacionAprobacion;
}Escolaridad;

//3.1
void CargarEscolaridad(Escolaridad &e, int idAsignatura, Fecha f, float calificacion);

//3.2
void MostarDatosEscolaridad(Escolaridad e);

//selectoras

//3.3
int DarIdAprobacion(Escolaridad e);

//3.4
Fecha DarFechaAprobacion(Escolaridad e);

//3.5
float DarCalificacionAprobacion(Escolaridad e);

#endif // Escolaridad_H_INCLUDED
