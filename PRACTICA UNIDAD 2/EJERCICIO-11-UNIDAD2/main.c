
/*
Un supermercado ingresa las ventas de los últimos 6 meses, realizadas en los 8 departamentos de venta que posee.
Por cada venta se ingresa mes (1 ... 12), número de departamento (1 ... 8) e importe. Las ventas no traen ningún orden
particular. Realizar un programa en C, que a través de funciones permita:
    a) Almacenar la información en una tabla que posea por cada mes, el importe total de ventas de cada departamento.
    La carga finaliza con mes igual a cero.
    b) Dado un mes, mostrar en el programa principal el departamento que menos vendió (suponer único).
    c) Mostrar el importe promedio de venta del supermercado.
    d) Dado un mes y un departamento, indicar si supera el importe promedio del ítem anterior.
*/

#include <stdio.h>
#include <stdlib.h>
#define MESES 12
#define DPTOS 8

// Cerar el arreglo
void cerarArreglo(float arreglo[MESES][DPTOS]){
    int i, j;
    for(i = 0; i<MESES; i++){
        for(j = 0; j<DPTOS; j++){
            arreglo[i][j] = 0;
        }
    }
    return;
}

// Cargar las ventas al arreglo
void cargarArreglo(float arreglo[MESES][DPTOS]){
    int mes, dpto;
    float monto;

    printf("Ingrese el mes a cargar (1 a 12):\n");
    scanf("%d", &mes);
    getchar();

    while(mes != 0){
        printf("Ingrese el nro de departamento(1 a 8): \n");
        scanf("%d", &dpto);
        if(dpto <= DPTOS && mes <= MESES){
            printf("Ingrese el monto a cargar: \n");
            scanf("%f", &monto);
            getchar();

            arreglo[mes-1][dpto-1] += monto;
        } else {
            printf("El mes o dpartamento es incorrecto, intente nuevamente.\n");
        }

        printf("Ingrese el mes a cargar (1 a 12) o 0 para salir:\n");
        scanf("%d", &mes);
        getchar();
    }

    return;
}

// Mostrar departamento con menos venta segun mes
int mostrarMenorVenta(float arreglo[MESES][DPTOS], int mes){
    int i, dpto;
    float min = 99999999.999;

    if(mes <= MESES){
        for(i = 0; i < DPTOS; i++){
            if (arreglo[mes-1][i] <= min){
                min = arreglo[mes-1][i];
                dpto = i+1;
            }
        }
    } else {
        printf("El mes o dpartamento es incorrecto, intente nuevamente.\n");
    }
    return dpto;
}

// Mostrar promedio
float ventasPromedio(float arreglo[MESES][DPTOS]){
    float acum = 0;
    float prom;
    int i, j;
    for (i = 0; i < MESES; i++){
        for(j = 0; j < DPTOS; j++){
            acum += arreglo[i][j];
        }
    }
    prom = acum / MESES;
    return prom;
}

// Supera promedio
void superaPromedio(float arreglo[MESES][DPTOS]){
    int mes, dpto;
    printf("Ingrese el mes (1 a 12): \n");
    scanf("%d", &mes);
    getchar();

    printf("Ingrese el departamento (1 a 8): \n");
    scanf("%d", &dpto);
    getchar();

    if(mes <= MESES && dpto <= DPTOS){
        if(arreglo[mes-1][dpto-1]>ventasPromedio(arreglo)){
            printf("El mes supera el promedio de ventas. \n");
        } else {
            printf("El mes no supera el promedio de ventas. \n");
        }
    } else {
        printf("Mes o departamento incorrecto, intente nuevamente\n");
    }
    return;
}
int main()
{
    float ventas[MESES][DPTOS];
    int mes;

    cerarArreglo(ventas);
    cargarArreglo(ventas);

    printf("Ingrese el mes a mostrar la menor venta(1 a 12):\n");
    scanf("%d", &mes);
    getchar();
    printf("El dpto %d es el de menor ventas para el mes %d", mostrarMenorVenta(ventas, mes), mes);

    printf("El promedio de ventas para la tienda es de: %f\n", ventasPromedio(ventas));

    superaPromedio(ventas);


    return 0;
}
