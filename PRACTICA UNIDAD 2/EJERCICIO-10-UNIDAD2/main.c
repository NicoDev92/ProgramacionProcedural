/*
Ejercicio 10
Un laboratorio abastece a 30 farmacias de la provincia (las farmacias están codificadas con números entre 1 y 30).
Dicho laboratorio comercializa 80 medicamentos (con código desde 100 hasta 179).
En forma ordenada por las farmacias se ingresan las ventas realizadas. Por cada venta se ingresa: código de
medicamento y cantidad de unidades, finalizando con código de medicamento igual a 0 (cero), como lo muestra el
siguiente ejemplo:

Codificar un programa en C, que utilizando funciones permita:
    a) Realizar la carga de la tabla.
    b) Calcular y mostrar el total de unidades vendidas de cada uno de los medicamentos.
    c) Dado el código de una farmacia, indicar el código del medicamento más vendido.
*/

#include <stdio.h>
#include <stdlib.h>
#define FARMACIAS 3
#define MEDICAMENT 8

// Cerar arreglo
void cerear(int arreglo[FARMACIAS][MEDICAMENT]){

    for(int i = 0; i<FARMACIAS; i++){
        for(int j = 0; j < MEDICAMENT; j++){
            arreglo[i][j]=0;
        }
    }
    return;
}

//cargar arreglo
void carga(int arreglo[FARMACIAS][MEDICAMENT]){
    int codMedic;
    int venta;
    for(int i = 0; i < FARMACIAS; i++){
        printf("Ingrese el cod del medicamento o 0 para salir: \n");
        scanf("%d", &codMedic);
        getchar();
        while(codMedic != 0){
            printf("Ingrese la cantidad vendida: \n");
            scanf("%d", &venta);
            getchar();
            arreglo[i][codMedic-100] += venta;
            venta = 0;
            printf("Ingrese el cod del medicamento o 0 para salir: \n");
            scanf("%d", &codMedic);
            getchar();
        }
    }
    return;
}

// Calcular unidades vendidas totales de medicamentos
void mostrarCantVendidas(int arreglo[FARMACIAS][MEDICAMENT]){
    int acum = 0;
    for(int i = 0; i < MEDICAMENT; i++){
        printf("Para el medicamento %d hay ", (i+100));
        for(int j = 0; j < FARMACIAS; j++){
            acum += arreglo[FARMACIAS][MEDICAMENT];
        }
        printf("%d vendidos.\n", acum);
        acum = 0;
    }
    return;
}

// Medicamento mas vendido:
void medicMasVendido(int arreglo[FARMACIAS][MEDICAMENT]){
    int codigoFarmacia, i, indice, max = 0;
    printf("Ingrese el codigo de farmacia: \n");
    scanf("%d", &codigoFarmacia);
    for(i = 0; i < MEDICAMENT; i++){
        if(max < arreglo[codigoFarmacia-1][i]){
            max = arreglo[codigoFarmacia-1][i];
            indice = i;
        }
    }

    printf("El medicamento mas vendido en la farmacia %d, fue %d.\n",codigoFarmacia, (i+100));
}


int main()
{
    int ventas[FARMACIAS][MEDICAMENT];
    cerear(ventas);
    carga(ventas);
    medicMasVendido(ventas);

    return 0;
}
