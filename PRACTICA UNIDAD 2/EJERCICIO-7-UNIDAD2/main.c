/*
Cargar aleatoriamente una tabla de 5x4 con números enteros y:
    a) Mostrar la suma de cada una de las filas.
    b) Calcular el promedio de la tercera columna.
    c) Decir cuántos números mayores a 100 se ingresaron.
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 4
#define MAX_RANDOM_NUM 200


// Cargar arreglo con numeros aleatorios
void cargarArregloNumerosAleatorios(int arreglo[FILAS][COLUMNAS]){
    int i, j;
    srand(time(NULL));
    for(i = 0; i < FILAS; i++){
        for(j = 0; j < COLUMNAS; j++){
            arreglo[i][j] = rand() % MAX_RANDOM_NUM;
        }
    }

    return;
}

// Cargar arreglo de forma aleatoria
void cargarArregloAleatoriamente(int arreglo[FILAS][COLUMNAS]){
    int fila, columna, valor;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        // Solicitar al usuario la fila y la columna
        printf("Ingrese la fila (0 a %d) donde quiere almacenar un valor: ", FILAS - 1);
        scanf("%d", &fila);

        printf("Ingrese la columna (0 a %d) donde quiere almacenar un valor: ", COLUMNAS - 1);
        scanf("%d", &columna);

        // Validar que la fila y la columna estén dentro del rango permitido
        if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
            printf("Fila o columna inválida. Intente nuevamente.\n");
        }

        // Solicitar el valor
        printf("Ingrese el valor para almacenar en la posición [%d][%d]: ", fila, columna);
        scanf("%d", &valor);

        // Almacenar el valor en la posición indicada
        arreglo[fila][columna] = valor;

        // Preguntar si desea continuar ingresando valores
        printf("¿Desea ingresar otro valor? (s/n): ");
        scanf(" %c", &continuar);
    }
    return;
}



int main()
{
    printf("Hello world!\n");
    return 0;
}
