#include "Previaturas.h"

//LISTA ===========================================

//7.1 MAKE
//Crea un diccionario vacío.
void makePreviaturasIndex(PreviaturasIndex &grafo)
{
    for (int i=0; i<N ; i++ )
    {
        grafo[i] = NULL;
    }
}

//7.2 MEMBER
//Member : Diccionario x K --> Boolean
//Determina si en el diccionario existe un elemento con la clave especificada.
bool memberPreviaturas(Previaturas lp, int id)
{
    bool hay = false;
    Previaturas aux = lp;
    while (!hay && aux!=NULL)
    {
        if (aux->info == id)
        {
            hay = true;
        }
//        else
        aux = aux->sig;
    }
//    delete aux;
    return hay;
} //id de Asignatura

//7.3 INSERT
//Insert : Diccionario x T --> Diccionario
//Inserta un elemento de tipo T en el diccionario.
//Precondición: el elemento a insertar no es miembro del diccionario.
void insertPreviaturas(Previaturas &lp, int as)
{
    nodoPreviatura* nuevoNodo = new nodoPreviatura;
    nuevoNodo->info = as;
    nuevoNodo->sig = lp;
    lp = nuevoNodo;
}

//7.6 DELETE
//modificado para que elimine toda la lista y no un elemento solo, cambio en base a que no se pide eliminar un elemento solo como requerimiento
void deletePreviaturas(Previaturas &lp)
{
    while (lp != NULL)
    {
        Previaturas aux = lp;
        lp = aux->sig;
        delete aux;
    }
}

//GRAFO ===========================================

//7.11 INSERTAR ARISTA
//Inserta la nueva arista al grafo.
//Precondición: la arista no pertenece al grafo.
void PreviaturasIndexInsertAristaGrafo(PreviaturasIndex &grafo, int id1, int id2)
{
    //segun la logica de la pregunta que se le hace al usuario en el menu,
    //se insertara la id1 en la lista del id2
    insertPreviaturas(grafo[id2],id1);
}

//7.13
void deleteAllPreviaturasIndex(PreviaturasIndex &grafo)
{
    for (int i=0; i<N ; i++ )
    {
        deletePreviaturas(grafo[i]);
        grafo[i] = NULL;
    }
}

//7.14
void puedeInsertarPreviatura(PreviaturasIndex grafo, int a1, int a2, int &isErrorPorPertenenciaDirecta, bool &puedo)
{
    //desde el menu la logica dice que insertara al a la lista colgando del a2
    puedo = true;
    isErrorPorPertenenciaDirecta = 0;
    //primero valido que el a1 ya no sea previatura de la lista que cualga del a2
    if (memberPreviaturas(grafo[a2],a1)) //la previatura a1 que quiero agregarle a la a2, ya esta en su lista de directas?
    {
        puedo = false;
        isErrorPorPertenenciaDirecta = 1;
    }
    else if (memberPreviaturas(grafo[a1],a2))//la previatura a1 que quiero agregarle a la a2, es previatura de las directas de a1?
    {
        puedo = false;
        isErrorPorPertenenciaDirecta = 2;
    }
    else//la previatura a1 que quiero agregarle a la a2, es previatura de alguna de sus indirectas?
    {
        //si no cualga, tengo que fijarme que no este en toda su lista de previaturas directas e indirectas... hay que usar el 7.16
        //hay que recorrer la lista que tenga todas las previaturas directas e indirectas e ir obteniendo los id
        //entrar con este id en cada sublista y hacerle un member a cada lista que cualga de cada id obtenido con el 7.16
        //luego ver si el a2 ya es previatura de alguna, entonces puedo = false;
        //sino se estaria generando ciclo
        bool visitados[N];
        for (int i=0; i<N ; i++ )
        {
            visitados[i] = false;
        }
        Previaturas pvs;
        makePreviaturas(pvs);
        getAllPreviaturasByID(grafo, a1, pvs, visitados );
        if (memberPreviaturas( pvs, a2) )
        {
            puedo = false;
            isErrorPorPertenenciaDirecta = 3; //pues es error por pertenencia indirecta
        }
    }
//algoritmo que validara si se puede insertar la materia a1 como previatura de a2
//requerimiento 3 de la letra, tener cuidado de no generar ciclos y
//creo hay qye usar la 7.9
}

//7.16
//Precondicion: El id_asignatura "a1", debe existir.
void getAllPreviaturasByID(PreviaturasIndex grafo, int a1, Previaturas &pvs, bool visitado[N])
{
    visitado[a1] = true;
    Previaturas aux;
    aux = NULL;
    getAllPreviaturasByIDRec(grafo,a1,aux);
    // Recorro las Previaturas Inmediatas
    while(aux != NULL)
    {
        if(!visitado[aux->info])
        {
            if(!memberPreviaturas(pvs,aux->info))
            {
                insertPreviaturas(pvs,aux->info);
            }
            getAllPreviaturasByID(grafo,aux->info, pvs, visitado);
        }

        aux = aux->sig;
    }

}

//7.17
bool tieneAlgunaPreviatura(PreviaturasIndex grafo, int a1)
{
    Previaturas aux = grafo[a1];
    bool tiene = false;
    if (aux != NULL)
        tiene = true;
    return tiene;

}

//7.18
void cargarPreviaturasAutomaticamente(PreviaturasIndex &grafo)
{
    Previaturas p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;
    p0 = NULL;
    p1 = NULL;
    p2 = NULL;
    p3 = NULL;
    p4 = NULL;
    p5 = NULL;
    p6 = NULL;
    p7 = NULL;
    p8 = NULL;
    p9 = NULL;
    p10 = NULL;
    p11 = NULL;

    insertPreviaturas(p1, 0);
    insertPreviaturas(p2, 0);
    insertPreviaturas(p3, 1);
    insertPreviaturas(p4, 3);
    insertPreviaturas(p4, 2);
    insertPreviaturas(p5, 4);
    insertPreviaturas(p6, 4);
    insertPreviaturas(p7, 9);
    insertPreviaturas(p8, 5);
    insertPreviaturas(p9, 6);
    insertPreviaturas(p10, 4);
    insertPreviaturas(p11, 10);
    insertPreviaturas(p11, 8);
    insertPreviaturas(p11, 7);

    grafo[0] = p0;
    grafo[1] = p1;
    grafo[2] = p2;
    grafo[3] = p3;
    grafo[4] = p4;
    grafo[5] = p5;
    grafo[6] = p6;
    grafo[7] = p7;
    grafo[8] = p8;
    grafo[9] = p9;
    grafo[10] = p10;
    grafo[11] = p11;

}

//7.19
void listAllPreviaturasByID(Previaturas pvs, Asignaturas asgs)
{
    if( pvs != NULL)
    {
        ordenarPreviaturas(pvs);
        ////Recorro las Previaturas
        while(pvs != NULL)
        {
            printf("\n");
            String nombre;
            StringCrear(nombre);
            DarNombreAsignatura(asgs[pvs->info], nombre);
            printf("\n  Id Asignatura : %d", pvs->info);
            printf(" - Nombre Asignatura : ");
            StringPrint(nombre);
            printf("\n\n   =============================================");
            StringDelete(nombre);
            pvs = pvs->sig;
        }
    }
    else
    {
        printf("\n\nEsta asignatura no requiere previaturas");
    }

}

//7.20
void crearPreviaturas(Previaturas &pvs)
{
    pvs = NULL;
}

//7.21
void getAllPreviaturasByIDRec(PreviaturasIndex grafo, int a1, Previaturas &pvs)
{
    Previaturas aux = grafo[a1];
    while(aux != NULL)
    {
        insertPreviaturas(pvs,aux->info);
        aux = aux->sig;
    }
}

//7.22
void getSoloPreviaturasDirectasByID(PreviaturasIndex grafo, int a1, Previaturas &pvs)
{
    Previaturas aux = grafo[a1];
    while (aux != NULL)
    {
        if (!memberPreviaturas(pvs,aux->info))
            insertPreviaturas(pvs,aux->info);
        aux = aux->sig;
    }
}

//7.23
void makePreviaturas(Previaturas &pvs)
{
    pvs = NULL;
}

//7.24
void ordenarPreviaturas(Previaturas &pvs)
{
    Previaturas p = pvs;
    while (p != NULL)
    {
        Previaturas j = p->sig;
        while (j != NULL)
        {
            if (p->info > j->info)
            {
                int aux = j->info;
                j->info = p->info;
                p->info = aux;
            }
            j = j->sig;
        }
        p = p->sig;
    }
}
