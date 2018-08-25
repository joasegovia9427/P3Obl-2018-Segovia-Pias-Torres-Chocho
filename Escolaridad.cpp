#include "Escolaridad.h"

//3.1
void CargarEscolaridad(Escolaridad &e, int idAsignatura, Fecha f, float calificacion)
{
    e.idAsignatura = idAsignatura;
    e.fechaAprobacion = f;
    e.calificacionAprobacion = calificacion;
}

//3.2
void MostarDatosEscolaridad(Escolaridad e)
{
    printf("\nId asignatura: %i\n", DarIdAprobacion(e));
    printf("Fecha: ");
    ImprimirFecha(e.fechaAprobacion);
    printf("\n");
    printf("Nota : %.2f",  DarCalificacionAprobacion(e));
}

//selectoras

//3.3
int DarIdAprobacion(Escolaridad e)
{
    return e.idAsignatura;
}

//3.4
Fecha DarFechaAprobacion(Escolaridad e)
{
    return e.fechaAprobacion;
}

//3.5
float DarCalificacionAprobacion(Escolaridad e)
{
    return e.calificacionAprobacion;
}
