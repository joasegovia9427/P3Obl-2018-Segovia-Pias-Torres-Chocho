#ifdef __MINGW32__ //tildes
    #define LIMPIAR "cls"
    #define REDIM "mode con: cols=140 lines=30"
    #define COLOR "color 70"
    #define COLOR2 "color 71"
    #define TITULO "title AcademiaDeCocina"
    #define LOGO "type titulo.tit"
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
    #define LIMPIAR "cls"
    #define REDIM "mode con: cols=120 lines=30"
    #define TITULO "title AcademiaDeCocina"
    #define LOGO "type titulo.tit"
    #define COLOR "color 70"
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
    #define LIMPIAR "clear"
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
    #define LIMPIAR "clear"
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

#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#include <stdio.h>

const int N = 12; //cantidad de Asignaturas

#endif // CONSTANTES_H_INCLUDED
