/*
Una tienda de ropa comercializa 50 productos diferentes. Por cada producto se conoce: código (número entero que
varía entre 1 y 50), precio de costo y stock.
La tienda hace compras a 22 proveedores, de los cuales se conoce: Nombre y Número de Proveedor (es un número
entre 1000 y 1022).
Se pide redactar un algoritmo en C que, usando estructuras de datos óptimas y subprogramas eficientes, permita:
        a) Almacenar en estructuras de datos adecuadas la información de los Productos y de los Proveedores.
        b) Procesar las compras realizadas a los Proveedores, sabiendo que por cada compra se conoce el Número de
        Proveedor, Código de Producto y Cantidad de unidades compradas. Con la información de cada compra se debe
        actualizar el stock del producto y contar para cada proveedor la compra realizada.
        c) Informar cuánto dinero hay invertido en cada producto.
        d) Generar una nueva estructura de datos que contenga todos los datos de aquellos Proveedores a quienes se les haya
        realizado más de 10 compras.
        e) Mostrar la estructura de datos generada en el inciso d) ordenada alfabéticamente por Nombre de proveedor.
        f) Ingresar por teclado un Nombre de proveedor e informar su Número y cantidad de compras realizadas. Nota: Utilizar
        la estructura de datos generada en el inciso d).
*/




#include <stdio.h>
#include <stdlib.h>

#define CANT_PROD 50
#define CANT_PROVEEDORES 23


typedef struct {
    int codigo;
    float precioCosto;
    int stock;
} Producto;

typedef struct {
    char nombre[20];
    int nroProveedor;
    int cantidadCompras;
} Proveedor;


//Cargar en arreglo proveedores:
void cargarProveedores(Proveedor proveedores[CANT_PROVEEDORES]){
    int i;
    printf("==Inicio de la carga==");
    for(i = 0; i < CANT_PROVEEDORES; i++){
        printf("==Prooveedor %d de %d ==", (i+1), CANT_PROVEEDORES);
        printf("\t==>Ingrese el Nombre del proveedor: \n");
        gets(proveedores[i].nombre);
        getchar();

        printf("\t==>Ingrese el Codigo del Proveedor: \n");
        scanf("%i", &proveedores[i].nroProveedor);
        getchar();

        proveedores[i].cantidadCompras=0;
    }
    printf("==Fin de la carga==");
    return;
}

//Cargar el arreglo de Productos:
void cargarProductos(Producto productos[CANT_PROD]){
    int i;
    printf("==Inicio de la carga==");
    for(i = 0; i < CANT_PROD; i++){
        printf("==Producto %d de %d ==", (i+1), CANT_PROD);
        printf("\t==>Ingrese el Codigo del producto: \n");
        scanf("%i", &productos[i].codigo);
        getchar();

        printf("\t==>Ingrese el Precio de Costo del producto: \n");
        scanf("%f", &productos[i].precioCosto);
        getchar();

        printf("\t==>Ingrese el Stock del producto: \n");
        scanf("%i", &productos[i].stock);
        getchar();
    }
    printf("==Fin de la carga==");
    return;
}

//Verificar proveedor existente:
int verificarProveedor(Proveedor proveedores[CANT_PROVEEDORES], int codProveedor, int *indiceProveedor){
    int bandera = 0;
    int posicion = 0;
    while(!bandera && posicion < CANT_PROVEEDORES){
        if(proveedores[posicion].nroProveedor == codProveedor){
            bandera = 1;
            *indiceProveedor = posicion;
        } else {
            posicion++;
        }
    }
    if(!bandera && posicion == CANT_PROVEEDORES){
        printf("ERROR: No se encontro un proveedor con el codigo: %i\n", codProveedor);
    }
    return bandera;
}

//Verificar producto existente;
int verificarProducto(Producto productos[CANT_PROD], int codigoProducto, int *indiceProducto){
    int bandera = 0;
    int posicion = 0;

    while(!bandera && posicion < CANT_PROD){
        if(productos[posicion].codigo == codigoProducto){
            bandera = 1;
            *indiceProducto = posicion;
        } else {
            posicion++;
        }
    }
    if(!bandera && posicion == CANT_PROD){
        printf("ERROR: No se encontro un producto con el codigo: %i\n", codigoProducto);
    }
    return bandera;
}

//Realizar compra:
void realizarCompra(Producto productos[CANT_PROD], Proveedor proveedores[CANT_PROVEEDORES], int codigoProducto, int codigoProveedor){
    int indiceProveedor, indiceProducto;
    int existeProveedor = verificarProveedor(proveedores, codigoProveedor, &indiceProveedor);
    int existeProducto;
    int cantidad;

    if(existeProveedor){
        existeProducto = verificarProducto(productos, codigoProducto, &indiceProducto);
        if(existeProducto){
            printf("Ingrese la cantidad del producto cod.: %i comprado: \n", codigoProducto);
            scanf("%d", &cantidad);
            getchar();
            productos[indiceProducto].stock += cantidad;
            proveedores[indiceProveedor].cantidadCompras += 1;
        }
    }

}

//Mostrar dinero invertido en cada producto:
void dineroInvertido(Producto productos[CANT_PROD]){
    int i;
    printf("==Mostrar dinero invertido por producto: ==\n");
    for(i = 0; i < CANT_PROD; i++){
        printf(">>Producto cod.: %i \n dineroInvertido: $%f\n", productos[i].codigo, (productos[i].precioCosto * productos[i].stock));
    }
}

// Filtrar proveedores con más de 10 compras:
int filtrarProveedoresMasDe10Compras(Proveedor proveedores[CANT_PROVEEDORES], Proveedor proveedoresFiltrados[CANT_PROVEEDORES]) {
    int j = 0;
    for (int i = 0; i < CANT_PROVEEDORES; i++) {
        if (proveedores[i].cantidadCompras > 10) {
            proveedoresFiltrados[j++] = proveedores[i];
        }
    }
    return j;
}

// Ordenar proveedores alfabéticamente por nombre y mostrarlos:
void ordenarProveedoresAlfabeticamenteYMostrarlos(Proveedor proveedoresFiltrados[], int n) {
    Proveedor temp;
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(proveedoresFiltrados[i].nombre, proveedoresFiltrados[j].nombre) > 0) {
                temp = proveedoresFiltrados[i];
                proveedoresFiltrados[i] = proveedoresFiltrados[j];
                proveedoresFiltrados[j] = temp;
            }
        }
    }
    for(k = 0; k < n; k++){
        printf("======%i======", (k+1));
        printf(">>Proveedor: %s \n Nro.: %i \n Cantidad de compras: %i \n",
               proveedoresFiltrados[k].nombre, proveedoresFiltrados[k].nroProveedor, proveedoresFiltrados[k].cantidadCompras);
        printf("============");
    }
}



int main()
{
    Producto productos[CANT_PROD];
    Proveedor proveedores[CANT_PROVEEDORES];
    Proveedor proveedoresFiltrados[CANT_PROVEEDORES];
    int cantProveedoresMas10Compras;

    cargarProductos(productos);
    cargarProveedores(proveedores);
    dineroInvertido(productos);
    cantProveedoresMas10Compras = filtrarProveedoresMasDe10Compras(proveedores, proveedoresFiltrados);
    ordenarProveedoresAlfabeticamenteYMostrarlos(proveedoresFiltrados, cantProveedoresMas10Compras);


    printf("Hello world!\n");
    return 0;
}
