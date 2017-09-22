#include <stdio.h>
#include <stdlib.h>
#include "producto.h"

int main()
{
    sProducto arrayProductos[200];
    prod_initProducto(arrayProductos,200);
    printf("1 - CARGAR PRODUCTO\n");
    printf("2 - LISTAR PRODUCTOS\n");

    char opcion;
    prod_opcionMenu(&opcion, "\nINGRESE OPCION");

    switch(opcion)
    {
    case 1:
        prod_cargarProducto (arrayProductos, 0);
        prod_cargarProducto (arrayProductos, 1);
        break;
    case 2:
        prod_printProducto(arrayProductos,200);
        break;
    }


    //printf("indice libre: %d",prod_lugarLibre(arrayProductos, 200));



    printf("indice libre: %d",prod_lugarLibre(arrayProductos, 200));
    return 0;
}

/* realizar una fumcion que devuelva el indice de un item vacio (0)
realizar un programa con 1 menu de 2 opciones 1: cargar 1 producto 2: imprimir listar producto*/
