#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "Escolaridades.h"

typedef struct
{
    int ci;
    String nombre;
    String apellido;
    String domicilio;
    int telefono;
    Escolaridades aprobaciones;
}Alumno;

//1.1
//carga el nombre de una Alumno pasada por parametro y devuelve una Alumnos con valores = 0
void CargaAlumno(Alumno &a, int ci, String nombre, String apellido, String domicilio, int telefono);

//1.2
//recibe dos variables y determina si se llaman igual
bool AreIgualesAlumno(Alumno a1, Alumno a2);

//1.3
//significa que v1 es menor que v2
bool MenorQueAlumno(Alumno a1, Alumno a2);

//selectoras

//1.4
int DarCIAlumno(Alumno a);

//1.5
void DarNombreAlumno(Alumno a, String &nombre);

//1.6
void DarApellidoAlumno(Alumno a, String &apellido);

//1.7
void DarDomicilioAlumno(Alumno a, String &domicilio);

//1.8
int DarTelefonoAlumno(Alumno a);

//1.9
void MostrarDatosAlumno(Alumno a);

//1.10
Escolaridades DarAprobacionesAlumno(Alumno a);

//1.11
void AgregarAprobacionAlumno(Alumno &a, Escolaridad nuevaAprobacion, PreviaturasIndex previasAcademia);

//1.12
bool tieneTodasLasPreviaturas(Escolaridades aprobaciones, int id, PreviaturasIndex previasAcademia);

//1.13
void ModificarAlumno(Alumno &a, int ci, String nombre, String apellido, String domicilio, int telefono, Escolaridades aprobaciones);

void DeleteAlumno(Alumno &a);

#endif // ALUMNO_H_INCLUDED
