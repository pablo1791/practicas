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

    if(arrayProducto != NULL && index >= 0 && index<=len)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {
            //printf("NOMBRE ok");
            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51)==0)
            {
                //printf("Float ok");
                idAux=prod_buscaProxId(arrayProducto,len);
                if(idAux!=-1)
                {
                    strncpy(arrayProducto[index].nombre,bNombre,51);
                    arrayProducto[index].precio = atof(bPrecio);
                    arrayProducto[index].estado = PRODUCTO_OCUPADO;
                    arrayProducto[index].id=idAux;
                    retorno=0;
                }

            }
        }

    }
    return retorno;
}

//**********************************************************************************************************************************

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

//**********************************************************************************************************************************

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
                printf("\nID: %d - Nombre: %s - Precio: %.2f",arrayProducto[i].id,arrayProducto[i].nombre,arrayProducto[i].precio);
            }
        }
    }
    return retorno;
}

//**********************************************************************************************************************************

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

//**********************************************************************************************************************************

int prod_buscaProxId (sProducto* arrayProducto, int longitud)
{
    int i,idMax=-1;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                if(idMax<arrayProducto[i].id)
                {
                    idMax=arrayProducto[i].id;
                }
            }
        }

    }
    return idMax+1;
}
//**********************************************************************************************************************************
int prod_buscarIndicePorID (sProducto* arrayProducto, int id, int longitud,char mensajeError[])
{
    int i;
    int retorno=-1;
    if(arrayProducto != NULL && longitud > 0 && id >=0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                if(id=arrayProducto[i].id)
                {
                    retorno=i;
                    break;
                }


            }

        }
    printf("%s",mensajeError);
    }

    return retorno;
}
//**********************************************************************************************************************************
int prod_modificarProducto(sProducto* arrayProducto, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bPrecio[51];

    if(arrayProducto != NULL && index >= 0 && index>=0)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {
            //printf("NOMBRE ok");
            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51)==0)
            {
                //printf("Float ok");
                strncpy(arrayProducto[index].nombre,bNombre,51);
                arrayProducto[index].precio = atof(bPrecio);
                retorno=0;
            }

        }
    }
    return retorno;
}


//**********************************************************************************************************************************

int prod_modificarProductoXid (sProducto* arrayProducto,int longitud)
{
    int retorno = -1;
    char bNombre[51];
    char bPrecio[51];
    char bId[10];
    int idComparar,index;

    if(arrayProducto != NULL && longitud >= 0)
    {
        val_getUnsignedInt(bId,"Ingrese ID","ID no valido,",3,10);
        idComparar=atoi(bId);
        index=prod_buscarIndicePorID(arrayProducto,idComparar,longitud,"El Id no existe");
        if(index!=-1)
        {
            if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
            {
                //printf("NOMBRE ok");
                if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51)==0)
                {
                    //printf("Float ok");
                    strncpy(arrayProducto[index].nombre,bNombre,51);
                    arrayProducto[index].precio = atof(bPrecio);
                    retorno=0;
                }

            }
        }

    }
    return retorno;
}

