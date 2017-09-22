#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "validar.h"

int prod_cargarProducto (sProducto* arrayProducto, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bPrecio[51];

    if(arrayProducto != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {
            //printf("NOMBRE ok");
            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51)==0)
            {
                //printf("Float ok");
                strncpy(arrayProducto[index].nombre,bNombre,51);
                arrayProducto[index].precio = atof(bPrecio);
                arrayProducto[index].estado = PRODUCTO_OCUPADO;
            }
        }

    }
    return retorno;
}

int prod_initProducto (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayProducto[i].estado = PRODUCTO_LIBRE;
        }

    }
    return retorno;
}

int prod_printProducto (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                printf("ID: %d - Nombre:%s - Precio: %.2f",i,arrayProducto[i].nombre,arrayProducto[i].precio);
            }
        }

    }
    return retorno;
}


int prod_lugarLibre(sProducto* arrayProducto, int longitud)
{

    int i, retorno;
    for(i=0; i<longitud; i++)
    {
        if(arrayProducto[i].estado == PRODUCTO_LIBRE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int prod_opcionMenu(char* opcion, char* msj)
{
    int retorno;
    char bOpcion [50];
    myFgets(bOpcion, 50, stdin);
    strncpy(opcion, bOpcion, 50);
    retorno= atoi(opcion);
    return retorno;
}

