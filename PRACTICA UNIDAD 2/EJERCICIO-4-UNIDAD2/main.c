#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CANT_POSTULANTES 20
//Lote de control:
/*
Maria Lopez
F
23456789
30
2
Carlos Sanchez
M
34567890
28
3
Ana Torres
F
45678901
22
4
Pedro Gomez
M
56789012
35
5
Lucia Diaz
F
67890123
29
6
Miguel Ruiz
M
78901234
31
7
Laura Martinez
F
89012345
27
8
Diego Fernandez
M
90123456
26
9
Sofia Garcia
F
11234567
33
10
Martin Alvarez
M
22345678
32
11
Carla Herrera
F
33456789
24
12

Alberto Rios
M
44567890
36
13
Elena Romero
F
55678901
23
14
Javier Vega
M
66789012
34
15
Natalia Castro
F
77890123
21
16
Tomas Ortiz
M
88901234
37
17
Valeria Silva
F
99012345
29
18
Andres Flores
M
10123456
38
19
Paula Mendez
F
21234567
26
1
*/


struct Postulante {
    char nombre[40];
    char sexo;
    long dni;
    int edad;
    int codLocalidad;
};

// Funcion para cargar los postulantes
void cargarPostulantes(struct Postulante postulantes[CANT_POSTULANTES]) {
    printf("==Ingreso de postulantes al sistema==\n");
    for (int i = 0; i < CANT_POSTULANTES; i++) {
        printf("CARGANDO %d de %d\n", (i + 1), CANT_POSTULANTES);
        printf("Ingrese el nombre del postulante: \n");
        fgets(postulantes[i].nombre, 40, stdin);

        printf("Ingrese el sexo (F: femenino, M: masculino) del postulante: \n");
        scanf(" %c", &postulantes[i].sexo);
        getchar();

        printf("Ingrese el DNI del postulante: \n");
        scanf("%ld", &postulantes[i].dni);
        getchar();

        printf("Ingrese el edad del postulante: \n");
        scanf("%d", &postulantes[i].edad);
        getchar();

        printf("Ingrese la localidad del postulante: (de 1 a 19)\n");
        scanf("%d", &postulantes[i].codLocalidad);
        getchar();
    }
    printf("==Fin de la carga==\n");
    return;
}

//Funcion para contar los postulantes menores a una edad
int postulantesMenoresA(int edadComparar, char sexoComparar, struct Postulante postulantes[CANT_POSTULANTES]) {
    int contador = 0;
    for (int i = 0; i < CANT_POSTULANTES; i++) {
        if (tolower(postulantes[i].sexo) == tolower(sexoComparar) && postulantes[i].edad < edadComparar) {
            contador++;
        }
    }
    return contador;
}

//Funcion para sacar edad promedio por sexo
int calcularEdadPromedioPorSexo(char sexoComp, struct Postulante postulantes[CANT_POSTULANTES]){
    float promedio;
    int cantPostulantes = 0;
    int sumador = 0;

    for(int i = 0; i < CANT_POSTULANTES; i++){
        if(tolower(postulantes[i].sexo) == tolower(sexoComp)){
            sumador += postulantes[i].edad;
            cantPostulantes++;
            }
        }

    if(cantPostulantes > 0){
        promedio = sumador / cantPostulantes;
    } else {
        promedio = 0;
    }

    return (int)promedio;
}

//Funcion para mostrar nombre y dni de los postulantes segun localidad
void mostrarPostulantePorSector(int localidad, struct Postulante postulantes[CANT_POSTULANTES]){
    printf("Postulantes para la localidad %d\n", localidad);
    for(int i = 0; i < CANT_POSTULANTES; i++){
        if(postulantes[i].codLocalidad == localidad){
            printf("Nombre: %s \t DNI.: %d\n", postulantes[i].nombre, postulantes[i].dni);
        } else {
            printf("No hay postulantes para la localidad %d\n", localidad);
        }
    }
    return;
}
int main() {
    struct Postulante postulantes[CANT_POSTULANTES];
    cargarPostulantes(postulantes);

    int edadComparar = 30;
    char sexoComparar = 'F';
    int edadPromedio = calcularEdadPromedioPorSexo('m', postulantes);
    int menores = postulantesMenoresA(edadComparar, sexoComparar, postulantes);

    printf("Cantidad de postulantes menores a %d anios y sexo %c: %d\n", edadComparar, sexoComparar, menores);
    if(edadPromedio > 0){
        printf("la edad promedio de los postulantes varones es de: %d\n", edadPromedio);
    } else {
        printf("No hay postulantes varones.\n");
    }

    return 0;
}
