#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include "validar.h"


int main()
{

    sProducto arrayProductos[200];
    char bufferInt[40];
    char bufferId[10];
    int id;
    prod_initProducto(arrayProductos,200);

    do
    {
        val_getUnsignedInt(bufferInt,"\n1-Alta\n2-Listar\n3-Buscar por ID\n4-Editar Producto\n8-Salir\n","\nSolo 1 y 2\n",2,40);
        switch(atoi(bufferInt))
        {
            case 1:
                prod_cargarProducto (arrayProductos, prod_buscarProductoLibre(arrayProductos,200),200);
                break;
            case 2:
                prod_printProducto(arrayProductos,200);
                break;
            case 3:
                val_getUnsignedInt(bufferId,"\nIngrese un ID: ","Valor invalido",3,10);
                id=atoi(bufferId);
                prod_buscarIndicePorID(arrayProductos,id,200,"El ID no existe");
                break;
            case 4:
                prod_modificarProductoXid(arrayProductos,200);
                break;
        }

    }while( atoi(bufferInt) != 8);





    return 0;
}
