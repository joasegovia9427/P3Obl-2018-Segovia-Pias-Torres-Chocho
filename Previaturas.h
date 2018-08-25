#ifndef PREVIATURAS_H_INCLUDED
#define PREVIATURAS_H_INCLUDED

#include "Asignaturas.h"

typedef struct nodoPreviaturaAlias{
    int info;
    nodoPreviaturaAlias * sig;
}nodoPreviatura;

typedef nodoPreviatura * Previaturas;

//const definida en string para una futura utilizacion en todos los modulos ya que Asignaturas no le hereda a nadie

typedef Previaturas PreviaturasIndex[N];

//LISTA ===========================================

//7.1 MAKE
//Crea un diccionario vacío.
void makePreviaturasIndex(PreviaturasIndex &grafo);

//7.2 MEMBER
//Member : Diccionario x K --> Boolean
//Determina si en el diccionario existe un elemento con la clave especificada.
bool memberPreviaturas(Previaturas lp, int id); //id de Asignatura

//7.3 INSERT
//Insert : Diccionario x T --> Diccionario
//Inserta un elemento de tipo T en el diccionario.
//Precondición: el elemento a insertar no es miembro del diccionario.
void insertPreviaturas(Previaturas &lp, int as);

//7.6 DELETE
void deletePreviaturas(Previaturas &lp);

//GRAFO ===========================================

//7.11 INSERTAR ARISTA
//Inserta la nueva arista al grafo.
//Precondición: la arista no pertenece al grafo.
void PreviaturasIndexInsertAristaGrafo(PreviaturasIndex &grafo, int id1, int id2);

//7.13
void deleteAllPreviaturasIndex(PreviaturasIndex &grafo);

//7.14
void puedeInsertarPreviatura(PreviaturasIndex grafo, int a1, int a2, int &isErrorPorPertenenciaDirecta, bool &puedo);

//7.16
//Precondicion: debe tener alguna previatura, usar 7.17
void getAllPreviaturasByID(PreviaturasIndex grafo, int a1, Previaturas &pvs, bool visitado[N]);

//7.17
bool tieneAlgunaPreviatura(PreviaturasIndex grafo, int a1);

//7.18
void cargarPreviaturasAutomaticamente(PreviaturasIndex &grafo);

//7.19
void listAllPreviaturasByID(Previaturas pvs, Asignaturas asgs);

//7.20
void crearPreviaturas(Previaturas &pvs);

//7.21
void getAllPreviaturasByIDRec(PreviaturasIndex grafo, int a1, Previaturas &pvs);

//7.22
void getSoloPreviaturasDirectasByID(PreviaturasIndex grafo, int a1, Previaturas &pvs);

//7.23
void makePreviaturas(Previaturas &pvs);

//7.24
void ordenarPreviaturas(Previaturas &pvs);

#endif // LISTAADYPREVIATURAS_H_INCLUDED
