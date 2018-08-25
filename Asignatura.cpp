#include "Asignatura.h"

//2.1
void CargarAsignatura(Asignatura &a, int id, String nombre){
    a.id = id;
    StringCrear(a.nombre);
    StringCopiar(a.nombre, nombre);
}

//2.2
void MostrarDatosAsignatura(Asignatura a){
    printf("\nId asignatura: %d", DarIdAsignatura(a));
    printf("\nNombre: ");
    StringPrint(a.nombre);
}

//selectoras
//2.3
int DarIdAsignatura(Asignatura a){
    return a.id;
}

//2.4
void DarNombreAsignatura(Asignatura a, String &nombre){
    StringCopiar(nombre, a.nombre);
}

//Eliminar Asignatura
//2.5
void DeleteAsignatura(Asignatura &a){
   a.id = -1;
   StringDelete(a.nombre);
}
