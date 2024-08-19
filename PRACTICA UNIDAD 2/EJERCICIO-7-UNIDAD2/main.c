/*
Cargar aleatoriamente una tabla de 5x4 con números enteros y:
    a) Mostrar la suma de cada una de las filas.
    b) Calcular el promedio de la tercera columna.
    c) Decir cuántos números mayores a 100 se ingresaron.
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 3
#define COLUMNAS 2
#define MAX_RANDOM_NUM 200


// Cargar arreglo con numeros aleatorios
void cargarArreglo(int arreglo[FILAS][COLUMNAS]){
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

// Mostrar suma de filas:
void mostrarSumaFilas(int arreglo[FILAS][COLUMNAS]){
    int acumulador, i, j;
    for(i=0; i<FILAS; i++){
        acumulador = 0;
        for(j=0; j<COLUMNAS; j++){
            acumulador += arreglo[i][j];
        }
        printf("Suma Fila %i = %i\n", i, acumulador);
    }
    return;
}

// Contar numeros mayores a 100:
void contarNumerosMayores(int arreglo[FILAS][COLUMNAS], int numero){
    int i, j, contador = 0;
    for(i=0; i<FILAS;i++){
        for(j=0; j<COLUMNAS; j++){
            if(arreglo[i][j] > numero){
                contador++;
            }
        }
    }
    printf("Hay %i numeros mayores a %i\n", contador, numero);
    return;
}

// Mostrar el promedio de la 3er columna:
void calcularPromedio(int arreglo[FILAS][COLUMNAS]){
    int acum = 0;
    float result;
    for(int i = 0; i < FILAS; i++){
        acum += arreglo[i][2];
    }
    result = acum / FILAS;

    printf("El promedio es %f \n", result);

    return;
}

int main()
{
    int matriz[FILAS][COLUMNAS];
    cargarArreglo(matriz);
    mostrarSumaFilas(matriz);
    contarNumerosMayores(matriz, 100);
    return 0;
}
