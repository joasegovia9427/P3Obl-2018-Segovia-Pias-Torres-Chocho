#include "Alumnos.h"

//4.1 MAKE
//Crea un diccionario vacío.
//crea el abb en null, como modifica el mismo abb hay que pasarlo por referencia
void makeAlumnos(Alumnos &Alumnos)
{
    Alumnos = NULL;
}

//4.2 MEMBER
//Member : Diccionario x K --> Boolean
//Determina si en el diccionario existe un elemento con la clave especificada.
bool memberAlumnos(Alumnos abb, Alumno a)
{

    if(abb == NULL)
        return false;
    else if (DarCIAlumno(a) == DarCIAlumno(abb->info))
        return true;
    else if(DarCIAlumno(a) < DarCIAlumno(abb->info))
        return memberAlumnos(abb->Hizq, a);
    else
        return memberAlumnos(abb->Hder, a);

}

//4.3 INSERT
//Insert : Diccionario x T --> Diccionario
//Inserta un elemento de tipo T en el diccionario.
//Precondición: el elemento a insertar no es miembro del diccionario.
void insertAlumnos(Alumnos &abbAlumnos, Alumno a)
{

    if (abbAlumnos == NULL)
    {
        abbAlumnos = new nodoAlumnoAlias;
        abbAlumnos->info = a;
        abbAlumnos->Hizq = NULL;
        abbAlumnos->Hder = NULL;
    }
    else
    {
        if (DarCIAlumno(a) <  DarCIAlumno(  abbAlumnos->info ))
        {
            insertAlumnos(abbAlumnos->Hizq, a);
        }
        else
        {
            insertAlumnos(abbAlumnos->Hder, a);
        }
    }

}

//4.4 FIND
//Find : Diccionario x K --> T
//Dada la clave de un elemento devuelve el elemento con dicha clave
//Precondición: el elemento es miembro del diccionario.
Alumno findAlumnos(Alumnos abb, int ci)
{
    if (ci == DarCIAlumno(abb->info))
        return abb->info;
    else if(ci < DarCIAlumno(abb->info))
        return findAlumnos(abb->Hizq, ci);
    else
        return findAlumnos(abb->Hder, ci);
}

//4.5 MODIFY
//Modify : Diccionario x T --> Diccionario
//Sustituye el viejo elemento de tipo T en el diccionario por el nuevo elemento.
//Precondición: el elemento a sustituir es miembro del diccionario.
void modifyAlumnos(Alumnos &abb, Alumno a)
{
    if (DarCIAlumno(a) == DarCIAlumno(abb->info))
    {
        String nombre, apellido, domicilio;
        StringCrear(nombre);
        StringCrear(apellido);
        StringCrear(domicilio);
        DarNombreAlumno(a,nombre);
        DarApellidoAlumno(a, apellido);
        DarDomicilioAlumno(a,domicilio);
        ModificarAlumno(abb->info, DarCIAlumno(abb->info),
                        nombre,
                        apellido,
                        domicilio,
                        DarTelefonoAlumno(a),
                        DarAprobacionesAlumno(a));
        StringDelete(nombre);
        StringDelete(apellido);
        StringDelete(domicilio);
    }
    else if(DarCIAlumno(a) < DarCIAlumno(abb->info))
        modifyAlumnos(abb->Hizq, a);
    else
        modifyAlumnos(abb->Hder, a);
}

void ModifyEscolaridadAlumnos(Alumnos &abb, int ci, Escolaridad e)
{
    if (ci == DarCIAlumno(abb->info))
    {
        insertEscolaridades(abb->info.aprobaciones, e);
    }
    else if(ci < DarCIAlumno(abb->info))
        ModifyEscolaridadAlumnos(abb->Hizq, ci, e);
    else
        ModifyEscolaridadAlumnos(abb->Hder, ci, e);
}

//4.7
bool IsVacioAlumnos(Alumnos abbAlumnos)
{
    if(abbAlumnos == NULL)
        return true;
    else
        return false;
}


//4.8
Alumno DarRaizAlumnos(Alumnos abbAlumnos)
{
    return abbAlumnos->info;
}


//4.9
Alumno DarHizqAlumnos(Alumnos abbAlumnos)
{
    return abbAlumnos->Hizq->info;
}


//4.10
Alumno DarHderAlumnos(Alumnos abbAlumnos)
{
    return abbAlumnos->Hder->info;
}

//4.11
void deleteAllAlumnos(Alumnos &abb)
{
    if (abb != NULL)
    {
        deleteAllAlumnos(abb -> Hizq);
        deleteAllAlumnos(abb -> Hder);
        DeleteAlumno(abb->info);
        abb = NULL;
    }
}

//4.12
void listAllAlumnos(Alumnos alus)
{
    if (alus != NULL)
    {
        listAllAlumnos(alus -> Hizq);
        printf("\n\n================================================\n");
        printf("\nDatos Alumno: ");
        MostrarDatosAlumno(alus->info);
        listAllAlumnos(alus -> Hder);
    }
}

//4.13
bool memberAlumnosByCI(Alumnos alu, int ci)
{
    if(alu == NULL)
        return false;
    else if (ci == DarCIAlumno(alu->info))
        return true;
    else if (ci < DarCIAlumno(alu->info))
        return memberAlumnosByCI(alu->Hizq, ci);
    else
        return memberAlumnosByCI(alu->Hder, ci);
}

//4.14
void listAllAlumnosConEscolaridad(Alumnos alus)
{
    if (alus != NULL)
    {
        listAllAlumnos(alus -> Hizq);

        printf("\n\n================================================\n");
        printf("\nDatos Alumno: ");
        MostrarDatosAlumno(alus->info);
        fflush(stdin);
        if (tieneAlgunaEscolaridad(DarAprobacionesAlumno(alus->info)) )
        {
            printf("\n\nEscolaridad:");
            listarAllEscolaridades(DarAprobacionesAlumno(alus->info) );
        }
        else
        {
            printf("\nEste alumno no tiene aprobaciones");
        }
        printf("\n\n");

        listAllAlumnos(alus -> Hder);
    }
}
