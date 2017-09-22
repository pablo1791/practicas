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
    int aux;

    if(arrayProducto != NULL && index >= 0)
    {
        aux=prod_obtenerId(arrayProducto, 200);
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {
            //printf("NOMBRE ok");
            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51)==0)
            {
                //printf("Float ok");
                strncpy(arrayProducto[index].nombre,bNombre,51);
                arrayProducto[index].precio = atof(bPrecio);
                arrayProducto[index].estado = PRODUCTO_OCUPADO;
                arrayProducto[index].id=aux;
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
                printf("ID: %d - Nombre:%s - Precio: %.2f",arrayProducto[i].id,arrayProducto[i].nombre,arrayProducto[i].precio);
            }
        }

    }
    return retorno;
}


int prod_buscarProductoLibre (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}



/*
int prod_obtenerId(sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;

    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_LIBRE)
            {
                retorno =  i;
                arrayProducto[i].id=i;
                break;
            }
        }

    }
    return retorno;
}
*/

int prod_obtenerId(sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    int idMax;

    if(arrayProducto != NULL && longitud > 0)
    {

        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].id == PRODUCTO_OCUPADO)
            {
                if(idMax==arrayProducto[i].id)
                    {
                        retorno=i;
                        break;
                    }

            }
        }
}

return retorno;
}




