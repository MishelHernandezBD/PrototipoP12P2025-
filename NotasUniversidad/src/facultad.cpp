#include "facultad.h"
#include <iostream>

using namespace std;

Facultad::Facultad()
{
    promedio_facultad_1=0;
    promedio_facultad_2=0;
    promedio_facultad_3=0;
}
void Facultad::llamaCiclo(){
    //Declaracion de variables
    int numeroDeCalculos = 0 ;
    int victoriasFacultad1 = 0;
    int victoriasFacultad2 = 0;
    int victoriasFacultad3 = 0;
    //Declaraci�n de matrices por cada facultad
    float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    char opcion;  //Variable que controla el ciclo de repetici�n
    bool repetir = true;  //Variable booleana del ciclo de repetici�n
    //Declaraci�n de matriz que almacenar� los nombres de los alumnos
    char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA] = {"Carlos","Luis","Maria","Pedro","Juan"};
    //Ciclo repetitivo del comparativo de facultades
    do
    {
        system("cls");
        //Inicializar los promedios por facultad
        promedio_facultad_1=0;
        promedio_facultad_2=0;
        promedio_facultad_3=0;
        cout << "*** Comparativo de Facultades ***" << endl << endl;
        llenarMatriz(matriz_facultad_1); //Calculo de las notas por facultad
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, alumnos, "Facultad de Ingenieria"); //Despliegue de valores por facultad
        llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, alumnos, "Facultad de Arquitectura");
        llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, alumnos, "Facultad de Administracion");

        //Calculo del mejor promedio de las facultades
        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3)
        {
            //Facultad 1 es mayor
            cout << " La facultad con el mejor promedio es : " << "Facultad de Ingenieria" << " Promedio: " << promedio_facultad_1 << endl;
            victoriasFacultad1++;
        } else
        if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3)
        {
            //Facultad 2 es mayor
            cout << " La facultad con el mejor promedio es : " << "Facultad de Arquitectura" << " Promedio: " << promedio_facultad_2 << endl;
            victoriasFacultad2++;

        } else
        if (promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_1)
        {
            //Facultad 3 es mayor
            cout << " La facultad con el mejor promedio es : " << "Facultad de Administracion" << " Promedio: " << promedio_facultad_3 << endl;
            victoriasFacultad3++;
        } else
        {
            //Varias facultades son iguales en promedio
            cout << " Algunas facultades tienen el mismo promedio " << endl << endl;
        }
        //Contador de calculos
        numeroDeCalculos++;

        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n')
        {
            repetir=false;
        }

    } while (repetir);
    Desplegar_Resultados(numeroDeCalculos, victoriasFacultad1, victoriasFacultad2, victoriasFacultad3);
}

void Facultad::imprimirMatrizLinea()
    //Funci�n que despliega titulo de cada nota calculada
    int x;

    cout << "+--------";
    for (x = 0; x < NUMERO_NOTAS + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}
float Facultad::imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad);
{
    //Funci�n que imprime la matriz en pantalla y realizando los calculos necesarios del promedio
    int y, x;

    float promedioMayor = matriz[0][NUMERO_NOTAS];
    float promedioMenor = matriz[0][NUMERO_NOTAS];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char alumnoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    //almacenar a los mejores alumnos por curso
    char mejoresAlumnos[NUMERO_NOTAS][MAXIMA_LONGITUD_CADENA];
    float mejoresPromedios[NUMERO_NOTAS];
    memcpy(alumnoPromedioMayor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    cout << nombreFacultad << endl;
    cout << "(Nota1)=>Primer Parcial  (Nota2)=>Segundo Parcial (Nota3)=>Final (Nota4)=>Actividades" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Alumno";
    for (x = 0; x < NUMERO_NOTAS; x++)
    {
        cout << setw(9) << "Nota" << x + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_ALUMNOS; y++)
    {
        cout << "!" << setw(8) << alumnos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_NOTAS; x++)
        {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";

        }
        float promedio = matriz[y][NUMERO_NOTAS];
        totalGeneral += matriz[y][NUMERO_NOTAS];
        if (promedio > promedioMayor) //Se va guardando la nota mayor y el nombre del alumno
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor) //Se va guardando la nota menor y el nombre del alumno
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    //Calculo del promedio general de cada facultad
    promedioGeneral = totalGeneral / NUMERO_ALUMNOS;
    cout << "Nota mayor: " << setw(10) << alumnoPromedioMayor <<  setw(10) << promedioMayor << endl;
    cout << "Nota menor: " << setw(10) << alumnoPromedioMenor <<  setw(10) << promedioMenor << endl;
    cout << "Nota prom : " << setw(10) <<  promedioGeneral << endl << endl;

    return promedioGeneral; //Retorno del promedio general por facultad
}
void Facultad::Desplegar_Resultados(int numeroDeCalculos, int victoriasFacultad1, int victoriasFacultad2, int victoriasFacultad3);
{
    cout << "\nResultados Finales" << endl;

    cout<< "Numero de calculos realizados: " << numeroDeCalculos << endl;
    //Calculo del mejor promedio de las facultades
    if (victoriasFacultad1 > victoriasFacultad2 && victoriasFacultad1 > victoriasFacultad3)
    {
        cout << "La mejor facultad es: Ingenieria" << endl;
        cout << "Gano un total de:  " << victoriasFacultad1 << endl;
    }
    else if (victoriasFacultad2 > victoriasFacultad1 && victoriasFacultad2 > victoriasFacultad3)
    {
        cout << "La mejor facultad es: Arquitectura" << endl;
        cout << "Gano un total de:  " << victoriasFacultad2 << endl;
    }
    else if (victoriasFacultad3 > victoriasFacultad2 && victoriasFacultad3 > victoriasFacultad1)
    {
        cout << "La mejor facultad es: Administracion" << endl;
        cout << "Gano un total de:  " << victoriasFacultad3 << endl;
    }
}
void Facultad::llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]);
{
    //Funci�n que permite llenar cada matriz con valores aleatorios
    int y, x;
    for (y = 0; y < NUMERO_ALUMNOS; y++)
    {
        float suma = 0;
        int calificacion = 0;
        for (x = 0; x < NUMERO_NOTAS; x++)
        {
            if (x == 0 || x == 3)  //Calculo del primer parcial o actividades
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 20);
            } else if (x == 1)  //Calculo del segundo parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 25);
            } else if (x == 2)  //Calculo del examen final
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 35);
            }
            suma += (float)calificacion;
            matriz[y][x] = calificacion;
            calificacion=0;
        }
        // Agregar promedio al final de la matriz

        matriz[y][NUMERO_NOTAS] = suma;
    }
}

int Facultad::busquedaAleatorios(int minimo, int maximo)
{
    //Calculo de valores aleatorios tomando como base la nota minima y m�xima del parcial
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
