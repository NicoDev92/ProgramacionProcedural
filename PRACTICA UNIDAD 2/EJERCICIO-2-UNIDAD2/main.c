#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LARGO 30
#define LARGO_PALABRA 12

// Leer la cadena "Programacion Procedural 2023" desde teclado
void ingresarCadena(char cadena[LARGO], int longitud) {
    printf("Ingrese la frase 'Programacion Procedural 2023':\n");
    gets(cadena);
    return;
}

// Cambiar caracter '2' por caracter '0'
void cambiarCaracter(char cadena[LARGO], int longitud){
    for(int i; i < longitud; i++){
        if(cadena[i]=='2'){
            cadena[i] = '0';
        }
    }
    return;
}

// Copiar palabra "Programacion" a una nueva cadena
void copiarPalabra(char cadenaOrigen[LARGO], char cadenaDestino[LARGO_PALABRA], int inicio, int longitud) {
    strncpy(cadenaDestino, &cadenaOrigen[inicio], longitud);
    cadenaDestino[longitud] = '\0';
    return;
}

// Contar las vocales de la frase
int contarVocales(char cadena[]){
    int contador = 0;
    for(int i = 0; i < LARGO; i++){
        if (tolower(cadena[i]) == 'a' ||
            tolower(cadena[i]) == 'e' ||
            tolower(cadena[i]) == 'i' ||
            tolower(cadena[i]) == 'o' ||
            tolower(cadena[i]) == 'u'){
            contador++;
        }
    }
    return contador;
}

int main() {
    char cadena[LARGO];
    char palabra[LARGO_PALABRA];
    ingresarCadena(cadena, sizeof(cadena));
    printf("=== La frase ingresada es: %s\n", cadena);
    cambiarCaracter(cadena, sizeof(cadena));
    printf("=> La frase modificada es: %s", cadena);
    copiarPalabra(cadena, palabra, 0, sizeof(palabra));
    printf("=> La palabra copiada es: %s\n", palabra);
    printf("=> Hay %d vocales.\n", contarVocales(cadena));

    return 0;
}

