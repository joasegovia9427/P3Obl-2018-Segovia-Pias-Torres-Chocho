#ifndef AlumnoS_H_INCLUDED
#define AlumnoS_H_INCLUDED

#include "Alumno.h"

typedef struct nodoAlumnoAlias
{
    Alumno info;
    nodoAlumnoAlias *Hizq;
    nodoAlumnoAlias *Hder;
} nodoAlumnos;

typedef nodoAlumnos * Alumnos;

//4.1 MAKE
//Crea un diccionario vacío.
//crea el abb en null, como modifica el mismo abb hay que pasarlo por referencia
void makeAlumnos(Alumnos &Alumnos);

//4.2 MEMBER
//Member : Diccionario x K --> Boolean
//Determina si en el diccionario existe un elemento con la clave especificada.
bool memberAlumnos(Alumnos alu, Alumno a);

//4.3 INSERT
//Insert : Diccionario x T --> Diccionario
//Inserta un elemento de tipo T en el diccionario.
//Precondición: el elemento a insertar no es miembro del diccionario.
void insertAlumnos(Alumnos &Alumnos, Alumno a);

//4.4 FIND
//Find : Diccionario x K --> T
//Dada la clave de un elemento devuelve el elemento con dicha clave
//Precondición: el elemento es miembro del diccionario.
Alumno findAlumnos(Alumnos abb, int ci);

//4.5 MODIFY
//Modify : Diccionario x T --> Diccionario
//Sustituye el viejo elemento de tipo T en el diccionario por el nuevo elemento.
//Precondición: el elemento a sustituir es miembro del diccionario.
void modifyAlumnos(Alumnos &abb, Alumno a);

//MODIFICA SOLO LA ESCOLARIDAD
void ModifyEscolaridadAlumnos(Alumnos &abb, int ci, Escolaridad e);

//4.6 DELETE
//Delete: Diccionario x K --> Diccionario
//Dada la clave de un elemento lo borra del diccionario
//Precondición: el elemento es miembro del diccionario.
void deleteAlumnos(Alumnos &abbAlumnos, int ci);

//4.7
bool IsVacioAlumnos(Alumnos abbAlumnos);

//4.8
Alumno DarRaizAlumnos(Alumnos abbAlumnos);

//4.9
Alumno DarHizqAlumnos(Alumnos abbAlumnos);

//4.10
Alumno DarHderAlumnos(Alumnos abbAlumnos);

//4.11
void deleteAllAlumnos(Alumnos &abb);

//4.12
void listAllAlumnos(Alumnos alus);

//4.13
bool memberAlumnosByCI(Alumnos alu, int ci);

//4.14
void listAllAlumnosConEscolaridad(Alumnos alus);

#endif // ARBOLAlumnoS_H_INCLUDED
