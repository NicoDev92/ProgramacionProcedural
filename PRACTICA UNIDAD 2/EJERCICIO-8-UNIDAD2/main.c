/*
Realizar un programa en lenguaje C, que usando funciones óptimas realice lo siguiente:
    a) Generar y cargar un arreglo bidimensional de enteros de 3x4.
    b) Mostrar en el main la suma de los elementos con valor impar.
    c). Ingresar un número de fila y mostrar en el main la cantidad de elementos mayores a 10 (realice una función que
    devuelva la cantidad al main).
*/



#include <stdio.h>
#include <stdlib.h>

#define FILAS 3
#define COLUMNAS 4

// Funcion para Cargar Arreglo:
void cargarArreglo(int arreglo[FILAS][COLUMNAS]){
    int i, j;
    for(i=0; i<FILAS; i++){
        for(j=0; j<COLUMNAS;j++){
            printf("Ingrese el elemento[%d][%d]\n", i, j);
            scanf("%d", &arreglo[i][j]);
            getchar();
        }
    }
    return;
}

// Funcion para la suma de elementos impares
int sumaImpares(int arreglo[FILAS][COLUMNAS]){
    int sumador = 0;
    int i, j;
    for(i=0; i<FILAS; i++){
        for(j=0; j<COLUMNAS;j++){
            if(arreglo[i][j] % 2 != 0){
                sumador += arreglo[i][j];
            }
        }
    }
   return sumador;
}
// CONTAR los mayores  a 10
int mayoresADiez(int arreglo[FILAS][COLUMNAS], int fila){
    int contador = 0;
    for(int j = 0; j<COLUMNAS; j++){
        if(arreglo[fila-1][j]>10){
            contador++;
        }
    }
    return contador;
}
// METODO QUE BUSCAN LOS PROFESORES
int mayoresADiez2(int arreglo[COLUMNAS]){
    int contador = 0;
    for(int j = 0; j<COLUMNAS; j++){
        if(arreglo[j]>10){
            contador++;
        }
    }
    printf("Contador=%d", contador);
    return contador;
}



int main()
{
    int arreglo[FILAS][COLUMNAS];
    int cant, fila;

    cargarArreglo(arreglo);
    printf("La suma de los elementos impares es: %d\n", sumaImpares(arreglo));
    printf("Ingrese el Numero de fila: \n");
    scanf("%d", &fila);
    getchar();
    cant = mayoresADiez(arreglo, fila);
    if(cant > 0){
        printf("Hay %d numeros mayores a 10\n", cant);
    } else {
        printf("No hay numeros mayores a 10\n");
    }

    mayoresADiez2(arreglo[fila-1]);

    return 0;
}
