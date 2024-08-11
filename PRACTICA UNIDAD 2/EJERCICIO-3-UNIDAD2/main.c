#include <stdio.h>
#include <stdlib.h>

#define CANT_ALUMNOS 10
struct Alumno {
    char nombre[20];
    char apellido[20];
    long dni;
};


// Funcion para cargr los alumnos a el arreglo
void cargarAlumnos(struct Alumno alumnos[CANT_ALUMNOS]){
    printf("==Comienzo de la carga==\n");

    for(int i = 0; i < CANT_ALUMNOS; i++){
        printf("CARGANDO %d de %d\n", (i+1), CANT_ALUMNOS);
        printf("ingrese el nombre del Alumno: ");
        gets(alumnos[i].nombre);
        printf("ingrese el apellido del Alumno: ");
        fgets(alumnos[i].apellido, 20, stdin);
        printf("Ingrese el DNI del alumno: ");
        scanf("%d", &alumnos[i].dni);
        getchar();
        printf("\n");
    }
    printf("==Fin de la carga==\n");
}

// Funcion para Mostrar la lista de alumnos
void mostrarListadoAlumnos(struct Alumno alumnos[CANT_ALUMNOS]){
    for(int i = 0; i < CANT_ALUMNOS; i++){
        printf("===Registro Num.: %d==\n", (i+1));
        printf("-Nombre: %s\n", alumnos[i].nombre);
        printf("-Apellido: %s\n", alumnos[i].apellido);
        printf("-DNI: %d\n", alumnos[i].dni);
    }
    printf("==Fin del listado ==\n");
}

// Funcion para mostrar la cantidad de alumnos con dni mayor a, en este caso, 40000000
int dniMayorA(struct Alumno alumnos[CANT_ALUMNOS], int dniComparar){
    int contador = 0;
    for(int i = 0; i < CANT_ALUMNOS; i++){
        if(alumnos[i].dni > dniComparar){
            contador++;
        }
    }
    return contador;
}
int main()
{
    struct Alumno alumnos[CANT_ALUMNOS];
    int dniComparar = 40000000;

    cargarAlumnos(alumnos);
    mostrarListadoAlumnos(alumnos);
    printf("Hay %d alumnos con DNI mayor a %d", dniMayorA(alumnos, dniComparar), dniComparar);

    return 0;
}
