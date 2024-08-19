#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CANT_PRODUCTOS 9

// Lote de control:
/*
Lampara Faros LED
LAMP01
25.50
100
Filtro de Aceite
FILT02
15.75
750
Bateria 12V
BATE03
120.00
30
Pastillas de Freno
PAST04
35.00
50
Amortiguador
AMOR05
80.00
20
Aceite 5W-30
ACEI06
18.50
150
Limpiaparabrisas
ESCO07
10.00
60
Correa
CORR08
25.00
40
Rodamientos 16
ROD10
130.50
15
*/

typedef struct
{
    char nombre[45];
    char codigo[15];
    float precioUnitario;
    int stock;
    int cantVendida;
} Producto;

// Funcion cargar arreglo de productos
void cargarProductos(Producto productos[CANT_PRODUCTOS])
{
    for (int i = 0; i < CANT_PRODUCTOS; i++)
    {
        printf("==>CARGANDO %d de %d <==\n", (i + 1), CANT_PRODUCTOS);

        printf("Ingrese el nombre del Producto: \n");
        gets(productos[i].nombre);
        getchar();

        printf("Ingrese el codigo del Producto: \n");
        gets(productos[i].codigo);
        getchar();

        printf("Ingrese el Precio unitario del producto: \n");
        scanf("%f", &productos[i].precioUnitario);
        getchar();

        printf("Ingrese el stock del producto: \n");
        scanf("%d", &productos[i].stock);
        getchar();

        productos[i].cantVendida = 0;
    }
    printf("==Fin de la carga==\n");
}

// Funcion para validar Stock suficiente para la venta
int validarStock(Producto productos[CANT_PRODUCTOS], char nombreProducto[20], int cant)
{
    int productoConStock = 0;
    int encontrado = 0;
    int indice = 0;

    while (!encontrado && indice < CANT_PRODUCTOS)
    {
        if (strcmp(productos[indice].nombre, nombreProducto) == 0)
        {
            encontrado = 1;
            if (productos[indice].stock >= cant)
            {
                productoConStock = 1;
            }
            else
            {
                printf("***ERROR: Stock insuficiente.*** \n");
            }
        }
        else
        {
            indice++;
        }
    }

    if (!encontrado)
    {
        printf("***ERROR: Producto no encontrado.***\n");
    }

    return productoConStock;
}

// Funcion para procesar una venta
void realizarVenta(char nombreProducto[20], int cantidad, Producto productos[CANT_PRODUCTOS])
{
    int indice = 0;
    int encontrado = 0;

    while (!encontrado && indice < CANT_PRODUCTOS)
    {
        if (strcmp(toupper(nombreProducto), toupper(productos[indice].nombre)) == 0)
        {
            productos[indice].cantVendida += cantidad;
            productos[indice].stock -= cantidad;
            printf("\tTransaccion realizada con exito!\n");
            encontrado = 1;
        } else {
            indice++;
        }
    }
}


// Funcion para ingresar ventas
void procesarVenta(Producto productos[CANT_PRODUCTOS])
{
    char nombreProducto[20];
    int cantAVender;
    printf("==>Ingrese el nombre del Producto: \n");
    gets(nombreProducto);
    getchar();

    while (strcasecmp(nombreProducto, "FIN") != 0)
    {
        printf("==>Ingrese la cantidad a vender: \n");
        scanf("%d", &cantAVender);
        getchar();

        if (validarStock(productos, nombreProducto, cantAVender))
        {
            realizarVenta(nombreProducto, cantAVender, productos);
        }
        else
        {
            printf("***ERROR: No se pudo realizar la transacci�n.***\n");
        }

        printf("==>Ingrese el nombre del Producto, para finalizar ingrese FIN: \n");
        gets(nombreProducto);
        getchar();
    }
}

// Mostrar productos con stock nulo
void mostrarStockNulo(Producto productos[CANT_PRODUCTOS])
{
    int bandera = 0;
    printf("==>Productos con stock nulo:<==\n");
    for (int i = 0; i < CANT_PRODUCTOS; i++)
    {
        if (productos[i].stock == 0)
        {
            printf("\t > Prod.: %s\n", productos[i].nombre);
            bandera = 1;
        }
    }
    if (!bandera)
    {
        printf("\tNo hay articulos sin Stock.\n");
    }
}

// Mostrar stock de producto por codigo de producto
void mostrarStockPorCodigo(Producto productos[CANT_PRODUCTOS])
{
    char codigoProducto[10];
    int indice = 0;
    int encontrado = 0;

    printf("==>Ingrese el codigo del producto: \n");
    gets(codigoProducto);

    while (!encontrado && indice < CANT_PRODUCTOS)
    {
        printf("codigos: %s\n", productos[indice].codigo);
        if (strcmp(codigoProducto, productos[indice].codigo) == 0)
        {
            printf("\t >Stock: %d\n", productos[indice].stock);
            encontrado = 1;
        }
        indice++;
    }

    if (!encontrado)
    {
        printf("***ERROR: Codigo no encontrado.***\n");
    }
}

// Mostrar recaudacion total de ventas
float recaudacionTotal(Producto productos[CANT_PRODUCTOS])
{
    float ventaTotalPorPeriodo = 0;
    for (int i = 0; i < CANT_PRODUCTOS; i++)
    {
        if (productos[i].cantVendida > 0)
        {
            ventaTotalPorPeriodo += (productos[i].precioUnitario * productos[i].cantVendida);
        }
    }
    return ventaTotalPorPeriodo;
}

int main()
{
    Producto productos[CANT_PRODUCTOS];
    int opcion;
    int continuar = 1;

    while (continuar)
    {
        printf("====================\n");
        printf("== Menu Principal ==\n");
        printf("1. Cargar productos\n");
        printf("2. Procesar venta\n");
        printf("3. Mostrar productos con stock nulo\n");
        printf("4. Mostrar stock por codigo de producto\n");
        printf("5. Mostrar recaudacion total\n");
        printf("\n");
        printf("0. Salir\n");
        printf("====================\n");
        printf("Seleccione una opcion: \n");
        scanf("%d", &opcion);
        getchar();
        printf("====================\n");
        switch (opcion)
        {
        case 1:
            cargarProductos(productos);
            break;
        case 2:
            procesarVenta(productos);
            break;
        case 3:
            mostrarStockNulo(productos);
            break;
        case 4:
            mostrarStockPorCodigo(productos);
            break;
        case 5:
            printf("Recaudacion total: %.2f\n", recaudacionTotal(productos));
            break;
        case 0:
            printf("Saliendo del programa...\n");
            continuar = 0;
            break;
        default:
            printf("Opcion invalida. Por favor, intente de nuevo.\n");
            break;
        }
    }

    return 0;
}
