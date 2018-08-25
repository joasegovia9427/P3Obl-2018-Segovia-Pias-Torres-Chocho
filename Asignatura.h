#ifndef Asignatura_H_INCLUDED
#define Asignatura_H_INCLUDED

#include "String.h"

typedef struct{
    int id;
    String nombre;
}Asignatura;

//2.1
void CargarAsignatura(Asignatura &a, int id, String nombre);

//2.2
void MostrarDatosAsignatura(Asignatura a);

//selectoras

//2.3
int DarIdAsignatura(Asignatura a);

//2.4
void DarNombreAsignatura(Asignatura a, String &nombre);

//2.5
void DeleteAsignatura(Asignatura &a);

#endif // Asignatura_H_INCLUDED
