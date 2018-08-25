#include "Escolaridades.h"

//6.1 MAKE
//Crea un diccionario vacío.
void makeEscolaridades(Escolaridades &le)
{
    le = NULL;
}

//6.2 MEMBER
//Member : Diccionario x K --> Boolean
//Determina si en el diccionario existe un elemento con la clave especificada.
bool memberEscolaridades(Escolaridades le, int id)
{
    bool existe = false;
    while(existe == false && le != NULL)
    {
        int ide = DarIdAprobacion(le->info);
        if( ide == id )
            existe = true;
        le = le->sig;
    }
    return existe;
} //id de Asignatura

//6.3 INSERT
//Insert : Diccionario x T --> Diccionario
//Inserta un elemento de tipo T en el diccionario.
//Precondición: el elemento a insertar no es miembro del diccionario.
void insertEscolaridades(Escolaridades &le, Escolaridad e)
{
    Escolaridades aux = new nodoEscolaridad;
    aux->info = e;
    aux->sig = le;
    le = aux;
    ordenarAllEscolaridades(le);
}

//6.4 FIND
//Find : Diccionario x K --> T
//Dada la clave de un elemento devuelve el elemento con dicha clave
//Precondición: el elemento es miembro del diccionario.
Escolaridad findEscolaridades(Escolaridades le, int id)
{
    bool existe = false;
    Escolaridad e;
    while (!existe && le != NULL)
    {
        if(DarIdAprobacion(le->info) == id )
        {
            existe = true;
            e = le->info;
        }
        else
        {
            le = le->sig;
        }
    }
    return e;
}

//6.7
void listarAllEscolaridades(Escolaridades esc)
{
    // este es llamado desde menu por lo obtenido del 1.10
    if (esc != NULL)
    {
        while(esc != NULL)
        {
            printf("\n\n---------------------------\n");
            printf("\n ID asignatura: %d", DarIdAprobacion(esc->info));
            printf(" - Fecha: ");
            ImprimirFecha(DarFechaAprobacion(esc->info));
            printf(" - Nota: ");
            printf("%.2f", DarCalificacionAprobacion(esc->info));
            esc = esc->sig;
        }
    }
    else
    {
        printf("\nNo tiene aprobaciones registradas ");
    }
}

//6.8
void ordenarAllEscolaridades(Escolaridades &escs)
{
    Escolaridades p = escs;
    while (p != NULL)
    {
        Escolaridades j = p->sig;
        while (j != NULL)
        {
            Fecha fp, fj;
            fp = DarFechaAprobacion(p->info);
            fj = DarFechaAprobacion(j->info);
            /**
            función comparaFecha, devuelve:
             -1 si fecha1 < fecha2
              0 si fecha1 = fecha2 //bien
              1 si fecha1 > fecha2 //bien
            **/
            if (CompararFechas(fp,fj) == 1)
            {
                Escolaridad aux = j->info;
                j->info = p->info;
                p->info = aux;
            }
            j = j->sig;
        }
        p = p->sig;
    }
}

//6.9
bool tieneAlgunaEscolaridad(Escolaridades escs)
{
    if (escs != NULL)
        return true;
    else
        return false;
}
