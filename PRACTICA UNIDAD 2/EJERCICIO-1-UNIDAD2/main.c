#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LONGITUD 20
#define MAX_NUM 15

//Funcion para cargar el arreglo con numeros aleatorios del 0 al 14:
void cargarArreglo(int arreglo[LONGITUD]){
    srand(time(NULL));
    printf("------------Cargando el arreglo----------------\n");
    for(int i = 0; i < LONGITUD; i++){
        arreglo[i] = rand() % MAX_NUM;
    }
    printf("------------fin de la carga----------------\n");
    return;
}
//Funcion para indicar si alguno de los numeros del arreglo es 0:
void existeCeros(int arreglo[LONGITUD]){
    int bandera = 0;
    int i = 0;
    while(bandera == 0 && i < LONGITUD){
        if(arreglo[i] == 0){
            bandera = 1;
            printf("Hay uno o mas ceros en el arreglo\n");
        } else {
            i++;
        }

    }
    if(bandera == 0){
        printf("No hay ningun 0 en el arreglo\n");
    }
    return;
}

//Funcion para mostrar todos los numeros del arreglo:
void mostrarArreglo(int arreglo[LONGITUD]){
    for(int i = 0; i < LONGITUD; i++){
        printf(" posicion %d, valor = %d \n", i, arreglo[i]);
    }
    return;
}

//Funcion para mostrar el valor de las posiciones pares:
void mostrarArregloPosicionesPares(int arreglo[LONGITUD]){
    for(int i = 0; i < LONGITUD; i++){
            if(i % 2 == 0){
                printf(" posicion %d, valor = %d \n", i, arreglo[i]);
            }
    }
}

//Funcion para indicar la cantidad de numeros pares en el arreglo:
int contarNumerosPares(int arreglo[LONGITUD]){
    int contador = 0;
    for(int i = 0; i < LONGITUD; i++){
        if(arreglo[i] % 2 == 0){
                contador++;
            }
    }
    return contador;
}

int main()
{
    int arreglo[LONGITUD];

    cargarArreglo(arreglo);
    printf("------------Mostrar el arreglo----------------\n");
    mostrarArreglo(arreglo);
    printf("----Existen uno o mas ceros en el arreglo----\n");
    existeCeros(arreglo);
    printf("----Mostrar valor de pociciones pares del arreglo----\n");
    mostrarArregloPosicionesPares(arreglo);
    printf("-----Mostrar cantidad de numeros pares-----\n");
    printf("Hay %d numero(s) par(es) en el arreglo\n", contarNumerosPares(arreglo));
    printf("------------FIN----------------\n");


    return 0;
}
