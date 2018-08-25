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

#include <stdio.h>
#include <stdlib.h>

using namespace std;

#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

const int MAX = 80;
typedef char * String;

void StringCrear(String &s);

int StringLargo(String s);

void StringCopiar(String &s1, String s2);

void StringScan(String &s);

void StringSwap(String &s1, String &s2);

void StringPrint(String s);

bool StringMenor(String s1, String s2);

bool StringEqual(String s1, String s2);

void crearNombresAsignaturas(String &as1, String &as2, String &as3, String &as4, String &as5, String &as6, String &as7, String &as8, String &as9, String &as10, String &as11, String &as12);

void StringDelete(String s);

bool StringContieneSoloLetras(String s1);

int StringToNumeric(String s1);

void StringQuitarSimboloSignoNeg(String &s1);

//Funcion que verifica si el string contiene al menos un caracter numerico.
bool StringContieneNumeros(String s1);

//valida que el s1 sea igual a un numero entero
bool StringEqualNumeroEntero(String s1);

#endif // STRING_H_INCLUDED
