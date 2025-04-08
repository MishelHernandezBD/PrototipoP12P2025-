//Creado por britany Mishel Hernandez Davila
#ifndef FACULTAD_H
#define FACULTAD_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

//Declaraci�n de Constantes
#define NUMERO_ALUMNOS 5
#define NUMERO_MATERIAS 5
#define NUMERO_NOTAS 4
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100

class Facultad
{
    public:
        Facultad();
        void llamaCiclo(); //Funci�n que controla el Ciclo comparativo de datos por todas las facultades
        void imprimirMatrizLinea(); //Funci�n que apoya el despliegue de titulos en el comparativo de facultades
        float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad);
        //Funci�n que permite el despliegue de cada facultad con sus alumnos y el calculo de promedios (menor y mayor)
        void Desplegar_Resultados(int numeroDeCalculos, int victoriasFacultad1, int victoriasFacultad2, int victoriasFacultad3);



    private:
    void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]); //Funci�n que permite asignar a cada alumno las notas aleatorios
    int busquedaAleatorios(int minimo, int maximo); //Funci�n que permite obtener valores aleatorios en

    float promedio_facultad_1;
    float promedio_facultad_2;
    float promedio_facultad_3;

    //Almacenar� los nombres de los alumnos
    char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA] = {"Carlos","Luis","Maria","Pedro","Juan"};

};

#endif // FACULTAD_H
