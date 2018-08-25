#ifndef AsignaturaS_H_INCLUDED
#define AsignaturaS_H_INCLUDED

#include "Constantes.h"
#include "Asignatura.h"

//const definida en string para una futura utilizacion en todos los modulos ya que Asignaturas no le hereda a nadie

typedef Asignatura Asignaturas[N];

//5.1 MAKE
//Crea un diccionario vacío.
void makeAsignaturas(Asignaturas &a);

//5.2 MEMBER ID
//Member : Diccionario x K --> Boolean
//Determina si en el diccionario existe un elemento con la clave especificada.
bool memberIDAsignaturas(Asignaturas a, int id);

//5.3 MEMBER Nombre
//Member : Diccionario x K --> Boolean
//Determina si en el diccionario existe un elemento con la clave especificada.
bool memberNombreAsignaturas(Asignaturas a, String nombre);

//5.4 INSERT
//Insert : Diccionario x T --> Diccionario
//Inserta un elemento de tipo T en el diccionario.
//Precondición: el elemento a insertar no es miembro del diccionario.
//insert back
void insertAsignaturas(Asignaturas &a, Asignatura as);

//5.7 DELETE
//Delete: Diccionario x K --> Diccionario
//Dada la clave de un elemento lo borra del diccionario
//Precondición: el elemento es miembro del diccionario.
void deleteUnaAsignaturaDeAsignaturas(Asignaturas &a, int id);

//5.8
bool isAllLoadedAignaturas(Asignaturas a);

//5.9
void deleteAllAsignaturas(Asignaturas &a);

//5.10
void listAllAsignaturas(Asignaturas a);

//5.11
void cargarAsignaturasManualmente(Asignaturas &asigs);

//5.12
void cargarAsignaturasAutomaticamente(Asignaturas &asigs);

#endif // AsignaturaS_H_INCLUDED
