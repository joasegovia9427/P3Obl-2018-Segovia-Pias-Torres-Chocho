#include "Alumno.h"

//1.1
//carga Alumno
void CargaAlumno(Alumno &a, int ci, String nombre, String apellido, String domicilio, int telefono)
{
    a.ci = ci;
    StringCrear(a.nombre);
    StringCrear(a.apellido);
    StringCrear(a.domicilio);
    StringCopiar(a.nombre, nombre);
    StringCopiar(a.apellido, apellido);
    StringCopiar(a.domicilio, domicilio);
    a.telefono = telefono;
    makeEscolaridades(a.aprobaciones);

}

//1.2
bool AreIgualesAlumno(Alumno  a1, Alumno a2)
{
    if(a1.ci == a2.ci)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//1.3
bool MenorQueAlumno(Alumno a1, Alumno a2)
{
    if(a1.ci < a2.ci)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Selectora

//1.4
int DarCIAlumno(Alumno a)
{
    return (a.ci);
}

//1.5
void DarNombreAlumno(Alumno a, String &nombre)
{
    StringCopiar(nombre, a.nombre);
}

//1.6
void DarApellidoAlumno(Alumno a, String &apellido)
{
    StringCopiar(apellido, a.apellido);
}

//1.7
void DarDomicilioAlumno(Alumno a, String &domicilio)
{
    StringCopiar(domicilio, a.domicilio);
}

//1.8
int DarTelefonoAlumno(Alumno a)
{
    return (a.telefono);
}

//1.9
void MostrarDatosAlumno(Alumno a)
{
    String nombre, apellido, domicilio;

    StringCrear(nombre);
    StringCrear(apellido);
    StringCrear(domicilio);

    DarNombreAlumno(a,nombre);
    DarApellidoAlumno(a,apellido);
    DarDomicilioAlumno(a,domicilio);

    printf("\nCI: %d", DarCIAlumno(a));
    printf("\nNombre: ");
    StringPrint(nombre);
    printf("\nApellido: ");
    StringPrint(apellido);
    printf("\nDomicilio: ");
    StringPrint(domicilio);
    printf("\nTelefono: %d", DarTelefonoAlumno(a));

    StringDelete(nombre);
    StringDelete(apellido);
    StringDelete(domicilio);
}

//1.10
Escolaridades DarAprobacionesAlumno(Alumno a)
{
    return a.aprobaciones;
}

//1.11
void AgregarAprobacionAlumno(Alumno &a, Escolaridad nuevaAprobacion, PreviaturasIndex previasAcademia)
{
    int id = DarIdAprobacion(nuevaAprobacion);
    //Busco si no esta ya esa materia
    if ( memberEscolaridades(a.aprobaciones, id) )
    {
        printf("\n***ERROR: La asignatura de ID: %d, ya se enceuntra en el registro, reintente con otra asignatura",id);
    }
    else
    {
        //Si no esta, me fijo si tienen todas las previas para poder insertar
        if (  tieneTodasLasPreviaturas(a.aprobaciones, id, previasAcademia)  ) // falta la llamada a lo que busque y retorne true si a una id pasada... estan todas sus previaturas
        {
            //Si tiene todo lo necesario, inserto
            insertEscolaridades(a.aprobaciones, nuevaAprobacion);
        }
        else
        {
            printf("\n***ERROR: La asignatura de ID: %d, no puede ser ingresada pues no tiene todas las previaturas necesarias, reintente con otra asignatura",id);
        }
    }
}

//1.12
bool tieneTodasLasPreviaturas(Escolaridades aprobaciones, int id, PreviaturasIndex previasAcademia)
{
    //falta
    //obtengo todas las previaturas directas
    Previaturas listPvsDir;
    crearPreviaturas(listPvsDir);
    getSoloPreviaturasDirectasByID(previasAcademia, id, listPvsDir);

    //voy recorriendo las previaturas directas y me fijo uno a uno si el id esta en aprobaciones
    //mientras todas esten no cambio de variable y luego retorno el bool
    bool isTodas = true;
    while (isTodas && listPvsDir != NULL)
    {
        if (!memberEscolaridades(aprobaciones, listPvsDir->info))
        {
            isTodas = false;
        }
        listPvsDir = listPvsDir->sig;
    }
    deletePreviaturas(listPvsDir);
    return isTodas;
}

//1.13
void ModificarAlumno(Alumno &a, int ci, String nombre, String apellido, String domicilio, int telefono, Escolaridades aprobaciones)
{
    a.ci = ci;
    StringCopiar(a.nombre, nombre);
    StringCopiar(a.apellido, apellido);
    StringCopiar(a.domicilio, domicilio);
    a.telefono = telefono;
    a.aprobaciones = aprobaciones;
}

void DeleteAlumno(Alumno &a)
{
    StringDelete(a.domicilio);
    StringDelete(a.apellido);
    StringDelete(a.nombre);
}
