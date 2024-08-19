#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, x;
    x=3;
    p=&x;
    printf("Valor de x = %i\n", x);
    printf("Valor del puntero p (direccion de memoria de x, se indica imprimeindo solo p) = %i\n", p);
    printf("Valor (contenido) de p(sera el mismo que de x y se muestra con *p) = %i\n", *p);
    printf("Si se modivica el contenido de x se modifica el de p\n");

    x=99;
    printf("Nuevo valor de x = %i\n", x);
    printf("Valor del puntero p (direccion de memoria de x) = %i\n", p);
    printf("Valor (contenido) de p(sera el mismo que de x y se muestra con *p) = %i\n", *p);
}
