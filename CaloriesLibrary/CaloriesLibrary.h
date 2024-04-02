// CaloriesLibrary.h

#pragma once
#include <string>

namespace CaloriesLibrary
{
    extern std::string ejercicios[30];
    extern int calorias[30];
    extern int ejercicios_realizados[30];
    extern int repeticiones_realizadas[30];
    extern int calorias_repeticion[30];
    void initEjercicios();
    void listaEjercicios();
    int caloriasquemadas();
} 
