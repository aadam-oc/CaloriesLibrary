// CaloriesLibrary.cpp


#include "CaloriesLibrary.h"
#include <iostream>
#include <windows.h> 



//colors
#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"


std::string CaloriesLibrary::ejercicios[30];
int CaloriesLibrary::calorias[30];
int CaloriesLibrary::ejercicios_realizados[30];
int CaloriesLibrary::repeticiones_realizadas[30];
int CaloriesLibrary::calorias_repeticion[30];

void CaloriesLibrary::initEjercicios() {
    ejercicios[0] = "Abdominales";
    ejercicios[1] = "Flexiones";
    ejercicios[2] = "Prensa de piernas";
    ejercicios[3] = "Sentadillas";
    ejercicios[4] = "Levantamiento de pesas";
    ejercicios[5] = "Burpees";
    ejercicios[6] = "Zancadas";
    ejercicios[7] = "Fondos de triceps";
    ejercicios[8] = "Peso muerto";
    ejercicios[9] = "Elevaciones laterales";
    ejercicios[10] = "Curl de biceps";
    ejercicios[11] = "Pull-ups";
    ejercicios[12] = "Plancha";
    ejercicios[13] = "Box jumps";
    ejercicios[14] = "Remo en máquina";
    ejercicios[15] = "Step-ups";
    ejercicios[16] = "Lunges";
    ejercicios[17] = "Press de hombros";
    ejercicios[18] = "Abducciones de cadera";
    ejercicios[19] = "Crunches";
    ejercicios[20] = "Press de banca";
    ejercicios[21] = "Pulldown de triceps";
    ejercicios[22] = "Remo sentado";
    ejercicios[23] = "Curl de biceps con barra";
    ejercicios[24] = "Press de triceps";
    ejercicios[25] = "Vuelos laterales";
    ejercicios[26] = "Pullover";
    ejercicios[27] = "Curl de piernas";
    ejercicios[28] = "Extension de piernas";
    ejercicios[29] = "Encogimientos de hombros";

    calorias[0] = 4;  // Calorías para Abdominales
    calorias[1] = 3;  // Calorías para Flexiones
    calorias[2] = 2;  // Calorías para Prensa de piernas
    calorias[3] = 3;  // Calorías para Sentadillas
    calorias[4] = 5;  // Calorías para Levantamiento de pesas
    calorias[5] = 8;  // Calorías para Burpees
    calorias[6] = 3;  // Calorías para Zancadas
    calorias[7] = 4;  // Calorías para Fondos de triceps
    calorias[8] = 5;  // Calorías para Peso muerto
    calorias[9] = 3;  // Calorías para Elevaciones laterales
    calorias[10] = 3; // Calorías para Curl de biceps
    calorias[11] = 6; // Calorías para Pull-ups
    calorias[12] = 2; // Calorías para Plancha
    calorias[13] = 9; // Calorías para Box jumps
    calorias[14] = 6; // Calorías para Remo en máquina
    calorias[15] = 4; // Calorías para Step-ups
    calorias[16] = 3; // Calorías para Lunges
    calorias[17] = 4; // Calorías para Press de hombros
    calorias[18] = 3; // Calorías para Abducciones de cadera
    calorias[19] = 4; // Calorías para Crunches
    calorias[20] = 5; // Calorías para Press de banca
    calorias[21] = 4; // Calorías para Pulldown de triceps
    calorias[22] = 6; // Calorías para Remo sentado
    calorias[23] = 3; // Calorías para Curl de biceps con barra
    calorias[24] = 4; // Calorías para Press de triceps
    calorias[25] = 3; // Calorías para Vuelos laterales
    calorias[26] = 4; // Calorías para Pullover
    calorias[27] = 4; // Calorías para Curl de piernas
    calorias[28] = 3; // Calorías para Extension de piernas
    calorias[29] = 2; // Calorías para Encogimientos de hombros

    for (size_t i = 0; i < 30; i++)
    {
        ejercicios_realizados[i] = 0;
    }
    for (size_t i = 0; i < 30; i++)
    {
        repeticiones_realizadas[i] = 0;
    }
    
    calorias_repeticion[0] = 0.35;   // Abdominales
    calorias_repeticion[1] = 0.45;    // Flexiones
    calorias_repeticion[2] = 0.25;   // Prensa de piernas
    calorias_repeticion[3] = 0.3;   // Sentadillas
    calorias_repeticion[4] = 0.4;   // Levantamiento de pesas
    calorias_repeticion[5] = 0.8;   // Burpees
    calorias_repeticion[6] = 0.35;   // Zancadas
    calorias_repeticion[7] = 0.5;   // Fondos de tríceps
    calorias_repeticion[8] = 0.4;   // Peso muerto
    calorias_repeticion[9] = 0.3;   // Elevaciones laterales
    calorias_repeticion[10] = 0.3;  // Curl de bíceps
    calorias_repeticion[11] = 0.6;  // Pull-ups
    calorias_repeticion[12] = 0.2;   // Plancha
    calorias_repeticion[13] = 0.7;  // Box jumps
    calorias_repeticion[14] = 0.45;  // Remo en máquina
    calorias_repeticion[15] = 0.4;  // Step-ups
    calorias_repeticion[16] = 0.35;  // Lunges
    calorias_repeticion[17] = 0.35;  // Press de hombros
    calorias_repeticion[18] = 0.3;  // Abducciones de cadera
    calorias_repeticion[19] = 0.3;  // Crunches
    calorias_repeticion[20] = 0.5;   // Press de banca
    calorias_repeticion[21] = 0.4;  // Pulldown de tríceps
    calorias_repeticion[22] = 0.45;  // Remo sentado
    calorias_repeticion[23] = 0.3;   // Curl de bíceps con barra
    calorias_repeticion[24] = 0.4;  // Press de tríceps
    calorias_repeticion[25] = 0.3;   // Vuelos laterales
    calorias_repeticion[26] = 0.4;   // Pullover
    calorias_repeticion[27] = 0.4;  // Curl de piernas
    calorias_repeticion[28] = 0.3;   // Extensión de piernas
    calorias_repeticion[29] = 0.25;   // Encogimientos de hombros

}

namespace CaloriesLibrary
{
    void listaEjercicios()
    {
        constexpr int numExercises = sizeof(ejercicios) / sizeof(ejercicios[0]);

        std::cout << "----------------------------------------------\n";
        for (int i = 0; i < numExercises; ++i)
        {
            std::cout << i + 1 << ". " << ejercicios[i];
            if (i == 2 || i == 7 || i == 10 || i == 14 || i == 17 || i == 20 || i == 21 || i == 22 || i == 24 || i == 25 || i == 27)
                std::cout << LGREEN << "\t\t" << calorias[i] * 60 << " calorias/h\n" << RESET;
            else if (i == 4 || i == 9 || i == 18 || i == 23 || i == 28 || i == 29)
                std::cout << LGREEN << "\t" << calorias[i] * 60 << " calorias/h\n" << RESET;
            else
                std::cout << LGREEN << "\t\t\t" << calorias[i] * 60 << " calorias/h\n" << RESET;
        }
        std::cout << "----------------------------------------------\n\n\n\n\n";
    }

    void salir() {
        std::cout << "Saliendo del programa";
        Sleep(1000);
        std::cout << ".";
        Sleep(1000);
        std::cout << ".";
        Sleep(1000);
        std::cout << ".\n\n\n\n";
        Sleep(1000);
    }
    int caloriasquemadas() {
        return 0;
    }
}