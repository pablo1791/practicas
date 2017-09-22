#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "validar.h"

int prod_cargarProducto (sProducto* arrayProducto, int index, int len)
{
    int retorno = -1;
    char bNombre[51];
    char bPrecio[51];
    int idAux;

    if(arrayProducto != NULL && index >= 0)
    {
        idAux = prod_buscarProximoId(arrayProducto,len);

        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {
            //printf("NOMBRE ok");
            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51)==0)
            {
                //printf("Float ok");
                strncpy(arrayProducto[index].nombre,bNombre,51);
                arrayProducto[index].precio = atof(bPrecio);
                arrayProducto[index].estado = PRODUCTO_OCUPADO;
                arrayProducto[index].idProducto = idAux;
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
                printf("\nID: %d - Nombre:%s - Precio: %.2f",arrayProducto[i].idProducto,arrayProducto[i].nombre,arrayProducto[i].precio);
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



int prod_buscarProximoId (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    int idMax = -1;

    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                if(idMax < arrayProducto[i].idProducto)
                {
                    idMax = arrayProducto[i].idProducto;
                }
            }
        }
        retorno = idMax +1;
    }
    return retorno;
}



static int pro_buscarIndicePorId (sProducto* arrayProducto, int longitud, int id, char* msj)
{
    int retorno = -1;
    int i;

    if(arrayProducto != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                if(id == arrayProducto[i].idProducto)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    printf(msj);
    return retorno;
}



int prod_modificarProducto (sProducto* arrayProducto, int index)
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
                retorno = 0;
            }
        }

    }
    return retorno;
}


int prod_editarProducto (sProducto* arrayProducto, int longitud)
{
    int i;
    int retorno = -1;
    char bNombre[51];
    char bPrecio[51];
    int idAmodificar;
    char bufferInt[20];

    val_getUnsignedInt(bufferInt, "id a modif", "id no existe", 2, 20);
    idAmodificar=atoi(bufferInt);
    i=pro_buscarIndicePorId(arrayProducto, 200, idAmodificar, "id no existe");
    if(i != -1)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {
            //printf("NOMBRE ok");
            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51)==0)
            {
                //printf("Float ok");
                strncpy(arrayProducto[i].nombre,bNombre,51);
                arrayProducto[i].precio = atof(bPrecio);
                retorno=0;
            }
        }
    }
    return retorno;
}






