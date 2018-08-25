#ifndef EscolaridadES_H_INCLUDED
#define EscolaridadES_H_INCLUDED

#include "Escolaridad.h"
#include "Previaturas.h"

typedef struct nodoEscolaridadAlias{
    Escolaridad info;
    nodoEscolaridadAlias * sig;
}nodoEscolaridad;

typedef nodoEscolaridad * Escolaridades;

//6.1 MAKE
//Crea un diccionario vacío.
void makeEscolaridades(Escolaridades &le);

//6.2 MEMBER
//Member : Diccionario x K --> Boolean
//Determina si en el diccionario existe un elemento con la clave especificada.
bool memberEscolaridades(Escolaridades le, int id); //id de Asignatura

//6.3 INSERT
//Insert : Diccionario x T --> Diccionario
//Inserta un elemento de tipo T en el diccionario.
//Precondición: el elemento a insertar no es miembro del diccionario.
void insertEscolaridades(Escolaridades &le, Escolaridad e);

//6.4 FIND
//Find : Diccionario x K --> T
//Dada la clave de un elemento devuelve el elemento con dicha clave
//Precondición: el elemento es miembro del diccionario.
Escolaridad findEscolaridades(Escolaridades le, int id);

//6.5 MODIFY
//Modify : Diccionario x T --> Diccionario
//Sustituye el viejo elemento de tipo T en el diccionario por el nuevo elemento.
//Precondición: el elemento a sustituir es miembro del diccionario.
void modifyEscolaridades(Escolaridades &le, Escolaridad e);

//6.6 DELETE
//Delete: Diccionario x K --> Diccionario
//Dada la clave de un elemento lo borra del diccionario
//Precondición: el elemento es miembro del diccionario.
void deleteEscolaridades(Escolaridades &le, int id);

//6.7
void listarAllEscolaridades(Escolaridades esc);

//6.8
void ordenarAllEscolaridades(Escolaridades &escs);

//6.9
bool tieneAlgunaEscolaridad(Escolaridades escs);

#endif // Escolaridades_H_INCLUDED
