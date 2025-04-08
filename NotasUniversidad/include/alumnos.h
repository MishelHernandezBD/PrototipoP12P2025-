#ifndef ALUMNOS_H
#define ALUMNOS_H

#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define NUMERO_NOTAS 4
#define NUMERO_ALUMNOS 5
#define MAXIMA_LONGITUD_CADENA 100

class alumnos
{
    public:
        alumnos();
        alumnos (int calificacion);
        float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad);

    private:
};

#endif // ALUMNOS_H
