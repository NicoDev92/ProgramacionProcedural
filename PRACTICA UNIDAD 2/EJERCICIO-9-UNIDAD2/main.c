/*
Ejercicio 9
En la Facultad se realiza un congreso para el cual se destinan 6 salas de conferencias y cada una representa un área
temática. En cada sala se dictan 4 conferencias en distintos turnos. Por cada interesado se ingresa número del área
temática (1-6), y turno al que quiere asistir (1-4). La Facultad desea llevar un registro de la cantidad de alumnos
inscriptos en cada área y en cada turno, para ello realizar los siguientes items:
    a) Carga de los datos. La carga es desordenada, cada alumno indica área y turno. No se sabe la cantidad de alumnos.
    b) Indicar la cantidad de inscriptos en cada turno de cada área.
    c) Dada un área temática, indicar el promedio de inscriptos.
*/



#include <stdio.h>
#include <stdlib.h>
#define AREAS 6
#define TURNOS 4

// Cargar el Arreglo
void cargarArreglo(int arreglo[AREAS][TURNOS]){
    int fila, columna;
    char continuar = 's';

    // Cerar arreglo:
    for(int i = 0; i < AREAS; i++){
        for(int j = 0; j < TURNOS; j++){
            arreglo[i][j]=0;
        }
    }

    // Cargar arreglo:
    while (continuar == 's' || continuar == 'S') {
        // Solicitar al usuario la fila y la columna
        printf("Ingrese el area (1 a %d) donde quiere inscribirse: ", AREAS);
        scanf("%d", &fila);
        fila--;

        printf("Ingrese el turno (1 a %d) donde quiere inscribirse: ", TURNOS);
        scanf("%d", &columna);
        columna--;

        // Validar que la fila y la columna estén dentro del rango permitido
        if (fila < 0 || fila >= AREAS || TURNOS < 0 || columna >= TURNOS) {
            printf("Area o turno invalido. Intente nuevamente.\n");
        } else {
            arreglo[fila][columna]++;
        }

        // Preguntar si desea continuar ingresando valores
        printf("¿Desea ingresar otro valor? (s/n): ");
        scanf(" %c", &continuar);
    }
    return;
}

// Mostrar inscriptos por area:
void mostrarInscriptos(int arreglo[AREAS][TURNOS]){
    int i, j;
    for(i = 0; i < AREAS; i++){
        printf(">>Inscriptos en el area %d: \n", i+1);
        for(j = 0; j < TURNOS; j++){
        printf(">>>Turno %d: - Inscriptos: %d \n", j, arreglo[i][j]);
        }
    }
    return;
}

// Promedio de inscriptos por area tematica:
void promedioPorArea(int arreglo[AREAS][TURNOS]){
    int acumulador = 0;
    int promedio, area;
    printf("Ingrese el area a conocer el promedio de alumnos: \n");
    scanf("%d", &area);
    getchar();

    for(int j = 0; j < TURNOS; j++){
        acumulador += arreglo[area-1][j];
    }
    promedio = acumulador/TURNOS;
    printf("Para el area %d hay en promedio %d alumnos inscriptos. \n", area, promedio);
}
int main()
{
    int inscriptos[AREAS][TURNOS];
    cargarArreglo(inscriptos);
    mostrarInscriptos(inscriptos);
    promedioPorArea(inscriptos);

    return 0;
}
