//CaloriesClient.cpp
// Un  programa que te indique las calorías perdidas a la hora de ejercitarte en el gimnasio, 
// teniendo en cuenta el tipo de ejercicio, las repeticiones realizadas, 
// la altura, edad y peso del usuario.

#include <iostream>
#include "CaloriesLibrary.h"
#include <windows.h> 
#include <CaloriesLibrary.cpp>
using namespace std;


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



    

//Variables
int proporcionarDatos;
int opcion;
int cantidadejercicios;
int ejercicio;
int repeticiones;
int edad;
int peso;
int altura;
string sexo;
int MB;
int estilo_vida;
float factorActividad;
float calorias_quemadas_sin_ejercicio;
int calorias_totales;


int main()
{
    CaloriesLibrary::initEjercicios();
    
    system("CLS");
    cout << LGREEN << "----CALCULADORA DE CALORIAS----" << RESET << "\n\n\n";
    Sleep(2000);
    cout  << "Para empezar necesitamos ciertos datos personales para calcular correctamente las calorias perdidas:\n-Altura\n-Edad\n-Peso \n\n";
    Sleep(2000);
    cout << "Acepta proporcionarnos los datos anteriormente mencionados?\n1. Si\n2. No\n";
    cin >> proporcionarDatos;
    system("CLS");
    cout << LGREEN << "----CALCULADORA DE CALORIAS----" << RESET << "\n\n\n";
    if (proporcionarDatos == 1) {
        do {
            cout << "Que quiere hacer?\n";
            cout << "1. Ver listado ejercicios - calorias\n";
            cout << "2. Acceder a la calculadora de calorias\n";
            cout << "3. Salir\n";
            cin >> opcion;
            system("CLS");
            cout << LGREEN << "----CALCULADORA DE CALORIAS----" << RESET << "\n\n\n";

            switch (opcion) {
            case 1:
                cout << "Listado de ejercicios:\n";
                CaloriesLibrary::listaEjercicios();
                Sleep(2000);
                cout << "Que quiere hacer?\n";
                cout << "1. Volver al menu\n";
                cout << "2. Salir\n";
                cin >> opcion;
                system("CLS");
                cout << LGREEN << "----CALCULADORA DE CALORIAS----" << RESET << "\n\n\n";
                if (opcion == 2) {
                    opcion = 0;
                }
                break;

            case 2:
               
                cout << "Eres hombre o mujer?(H/M)\n";
                cin >> sexo;

                

                cout << "Cuantos anos tienes?\n";
                cin >> edad;
                cout << "Cuantos pesas?\n";
                cin >> peso;
                cout << "Cuanto mides (cm)?\n";
                cin >> altura;

                if (sexo == "H" || sexo == "h") {
                    MB = 88.362 + (13.397 * peso) + (4.799 * altura) - (5.677 * edad);
                }
                else if (sexo == "M" || sexo == "m") {
                    MB = 447.593 + (9.247 * peso) + (3.098 * altura) - (4.330 * edad);
                }
                else {
                    cout << "Opcion no valida.\n\n\n\n";
                    return 1;
                }

                cout << "Selecciona estilo de vida:\n";
                cout << "1. Sedentario\n";
                cout << "2. Levemente activo\n";
                cout << "3. Moderadamente activo\n";
                cout << "4. Muy activo\n";
                cout << "5. Extremadamente activo\n";
                cin >> estilo_vida;

                switch (estilo_vida) {
                case 1:
                    factorActividad = 1.2;
                    break;
                case 2:
                    factorActividad = 1.375;
                    break;
                case 3:
                    factorActividad = 1.55;
                    break;
                case 4:
                    factorActividad = 1.725;
                    break;
                case 5:
                    factorActividad = 1.9;
                    break;
                default:
                    cout << "Opción no valida.";
                    factorActividad = 1.2;
                }

                calorias_quemadas_sin_ejercicio = MB * factorActividad;

                CaloriesLibrary::listaEjercicios();
                cout << "Cuantos ejercicios diferentes has realizado?\n";
                cin >> cantidadejercicios;

                calorias_totales = calorias_quemadas_sin_ejercicio;

                for (size_t i = 0; i <= cantidadejercicios - 1; i++)
                {
                    CaloriesLibrary::listaEjercicios();
                    cout << "Seleccione el ejercicio " << i + 1 << "\n";
                    cin >> ejercicio;
                    CaloriesLibrary::ejercicios_realizados[i] = ejercicio;
                    cout << "Cuantas repeticiones has hecho de " << CaloriesLibrary::ejercicios[ejercicio - 1] << "\n";
                    cin >> repeticiones;
                    CaloriesLibrary::repeticiones_realizadas[i] = repeticiones;

                    int caloriasEjercicio = repeticiones * CaloriesLibrary::calorias_repeticion[ejercicio - 1];

                    calorias_totales = calorias_totales + caloriasEjercicio;
                }
                system("CLS");
                cout << LGREEN << "----CALCULADORA DE CALORIAS----" << RESET << "\n\n\n";
                cout << "Has quemado un total aproximado de " << LGREEN << calorias_totales << RESET << "calorias\n\n\n";
                Sleep(2000);
                cout << "Que quiere hacer?\n";
                cout << "1. Volver al menu\n";
                cout << "2. Salir\n";
                cin >> opcion;
                system("CLS");
                cout << LGREEN << "----CALCULADORA DE CALORIAS----" << RESET << "\n\n\n";
                if (opcion == 2) {
                    opcion = 0;
                }
                break;

            case 3:
                opcion = 0;
                CaloriesLibrary::salir();
                break;
            }
        } while (opcion != 0);
    }
    else {
        cout << "Si no proporciona esos datos no podemos calcular las calorias\n";
    }

    return 0;
}