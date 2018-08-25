#include "Asignaturas.h"

//5.1 MAKE
//Crea un diccionario vacío.
void makeAsignaturas(Asignaturas &a)
{
    Asignatura newA;
    String nombreAsig;
    StringCrear(nombreAsig);

    for (int i=0; i<N ; i++ )
    {
        CargarAsignatura(newA, N+1,nombreAsig);
        a[i] = newA;
    }
    StringDelete(nombreAsig);
}
//5.2 MEMBER CI
//Member : Diccionario x K --> Boolean
//Determina si en el diccionario existe un elemento con la clave especificada.
bool memberIDAsignaturas(Asignaturas a, int id)
{
    bool encontre = false;
    int indice = 0;
    while(indice < N && !encontre)
    {
        int cod = DarIdAsignatura(a[indice]);
        if (cod == id)
            encontre = true;
        else
            indice++;
    }
    return encontre;
}

//5.3 MEMBER Nombre
//Member : Diccionario x K --> Boolean
//Determina si en el diccionario existe un elemento con la clave especificada.
bool memberNombreAsignaturas(Asignaturas a, String nombre)
{
    bool encontre = false;
    int indice = 0;
    String name;
    StringCrear(name);
    while(indice<N && !encontre)
    {
        DarNombreAsignatura(a[indice], name);
        if (StringEqual(name,nombre))
        {
            encontre = true;
        }
        else
            indice++;
    }
    return encontre;
    StringDelete(name);
}

//5.4 INSERT
//Insert : Diccionario x T --> Diccionario
//Inserta un elemento de tipo T en el diccionario.
//Precondición: el elemento a insertar no es miembro del diccionario.
void insertAsignaturas(Asignaturas &a, Asignatura aa)
{
//insert en la id de la asignatura
    int indice = DarIdAsignatura(aa);
    a[indice] = aa;
}

//5.7 DELETE
//Delete: Diccionario x K --> Diccionario
//Dada la clave de un elemento lo borra del diccionario
//Precondición: el elemento es miembro del diccionario.
void deleteUnaAsignaturaDeAsignaturas(Asignaturas &a, int id)
{
    DeleteAsignatura(a[id]);
}

//5.8
//Controlara que esten todas las N asignaturas cargadas ( N = 12 )
bool isAllLoadedAignaturas(Asignaturas a)
{
    bool isAllLoaded = true;
    int i = 0;
    while (isAllLoaded && i<N)
    {
        if ( i != DarIdAsignatura(a[i])   )
        {
            isAllLoaded = false;
        }
        else
        {
            i++;
        }
    }
    return isAllLoaded;
}

//5.9
void deleteAllAsignaturas(Asignaturas &a)
{
    for (int i = 0; i <N; i++)
    {
        deleteUnaAsignaturaDeAsignaturas(a, i);
    }
}

//5.10
void listAllAsignaturas(Asignaturas a)
{
    for (int i = 0; i<N ; i++ )
    {
        printf("\n\n================================================\n");
        MostrarDatosAsignatura(a[i]);
    }
}

//5.11
void cargarAsignaturasManualmente(Asignaturas &asigs)
{
    for (int i = 0; i<N ; i++ )
    {
        String nombreAsignatura;
        StringCrear(nombreAsignatura);
        printf("\n\nIngrese nombre para la asignatura de ID %d: ",i);
        fflush(stdin);
        StringScan(nombreAsignatura);
        printf("\nNombre ingresado: ");
        StringPrint(nombreAsignatura);

        if (memberNombreAsignaturas(asigs, nombreAsignatura))
        {
            printf("\n***ERROR, el nombre de esta asignatura ya esta ingresado, reintente");
            i = i-1;
        }
        else if(memberIDAsignaturas(asigs, i))
        {
            printf("\n***ERROR de sistema, el id de esta asignatura ya esta ingresado, reintente");
            i = i-1;
        }
        else
        {
            Asignatura nuevaAsignatura;
            CargarAsignatura(nuevaAsignatura, i, nombreAsignatura);
            insertAsignaturas(asigs, nuevaAsignatura);
        }
    }
}

//5.12
void cargarAsignaturasAutomaticamente(Asignaturas &asigs)
{
    String as1, as2, as3, as4, as5, as6, as7, as8, as9, as10, as11, as12;
    crearNombresAsignaturas(as1, as2, as3, as4, as5, as6, as7, as8, as9, as10, as11, as12);
    Asignatura asig1, asig2, asig3, asig4, asig5, asig6, asig7, asig8, asig9, asig10, asig11, asig12;

    CargarAsignatura(asig1, 0, as1);
    CargarAsignatura(asig2, 1, as2);
    CargarAsignatura(asig3, 2, as3);
    CargarAsignatura(asig4, 3, as4);
    CargarAsignatura(asig5, 4, as5);
    CargarAsignatura(asig6, 5, as6);
    CargarAsignatura(asig7, 6, as7);
    CargarAsignatura(asig8, 7, as8);
    CargarAsignatura(asig9, 8, as9);
    CargarAsignatura(asig10, 9, as10);
    CargarAsignatura(asig11, 10, as11);
    CargarAsignatura(asig12, 11, as12);

    insertAsignaturas(asigs, asig1);
    insertAsignaturas(asigs, asig2);
    insertAsignaturas(asigs, asig3);
    insertAsignaturas(asigs, asig4);
    insertAsignaturas(asigs, asig5);
    insertAsignaturas(asigs, asig6);
    insertAsignaturas(asigs, asig7);
    insertAsignaturas(asigs, asig8);
    insertAsignaturas(asigs, asig9);
    insertAsignaturas(asigs, asig10);
    insertAsignaturas(asigs, asig11);
    insertAsignaturas(asigs, asig12);
}
