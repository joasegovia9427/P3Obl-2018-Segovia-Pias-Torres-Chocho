#ifdef __MINGW32__ //tildes
    #define LETRA_A "\267"
    #define LETRA_a "\240"
    #define LETRA_E "\220"
    #define LETRA_e "\202"
    #define LETRA_I "\326"
    #define LETRA_i "\241"
    #define LETRA_O "\340"
    #define LETRA_o "\242"
    #define LETRA_U "\351"
    #define LETRA_u "\243"
    #define LETRA_N "\245"
    #define LETRA_n "\244"
#endif // __MINGW32__

#ifdef _MIN32 //tildes
    #define LETRA_A "\267"
    #define LETRA_a "\240"
    #define LETRA_E "\220"
    #define LETRA_e "\202"
    #define LETRA_I "\326"
    #define LETRA_i "\241"
    #define LETRA_O "\340"
    #define LETRA_o "\242"
    #define LETRA_U "\351"
    #define LETRA_u "\243"
    #define LETRA_N "\245"
    #define LETRA_n "\244"
#endif // _MIN32

#ifdef __linux__
    #define LETRA_A "\u00C1"
    #define LETRA_a "\u00E1"
    #define LETRA_E "\u00C9"
    #define LETRA_e "\u00E9"
    #define LETRA_I "\u00CD"
    #define LETRA_i "\u00ED"
    #define LETRA_O "\u00D3"
    #define LETRA_o "\u00F3"
    #define LETRA_U "\u00DA"
    #define LETRA_u "\u00FA"
    #define LETRA_N "\u00D1"
    #define LETRA_n "\u00F1"
#endif // __linux__

#ifdef __APPLE__
    #define LETRA_A "\u00C1"
    #define LETRA_a "\u00E1"
    #define LETRA_E "\u00C9"
    #define LETRA_e "\u00E9"
    #define LETRA_I "\u00CD"
    #define LETRA_i "\u00ED"
    #define LETRA_O "\u00D3"
    #define LETRA_o "\u00F3"
    #define LETRA_U "\u00DA"
    #define LETRA_u "\u00FA"
    #define LETRA_N "\u00D1"
    #define LETRA_n "\u00F1"
#endif // __APPLE__

#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdio.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

//Validar fecha
bool IsValidFecha(Fecha fecha);

//Carga fecha por teclado
void CargarFecha(Fecha &fecha);

//Despliega fecha
void ImprimirFecha(Fecha fecha);

//Compara fechas
int CompararFechas(Fecha fecha1, Fecha fecha2);

//Selectoras

//Retorna el dia de la fecha
int DarDia(Fecha fecha);

//Retorna el mes de la fecha
int DarMes(Fecha fecha);

//Retorna el año de la fecha
int DarAnio(Fecha fecha);

void PreCargarFecha(Fecha &fecha, int dia, int mes, int anio);

#endif // FECHA_H_INCLUDED
