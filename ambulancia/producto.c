#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "validar.h"


/*
    int id;
    char nombre[51];
    char apellido[51];
    char dni[51];
    unsigned char edad;
    unsigned char estado;
    */
int aso_cargarAsociado (sAsociado* arrayAsociado, int indice, int longitud)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];
    char bDni[15];
    char bEdad[4];
    int auxId;

    if(arrayAsociado != NULL && indice >= 0 && indice<=longitud)
    {
        if(val_getString(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {
            if(val_getString(bApellido,"\nAPELLIDO?","\nError:\n",3,51)==0)
            {
                if(val_getStringDni(bDni,"\nDNI?","\nError:\n",3,15)==0)

                {
                    if(val_getUnsignedInt(bEdad,"\nEDAD?","\nError:\n",3,4)==0)
                    {
                        auxId=aso_buscaProxId(arrayAsociado,longitud);
                        if(auxId!=-1)
                        {
                            strncpy(arrayAsociado[indice].nombre, bNombre, 51);
                            strncpy(arrayAsociado[indice].apellido, bApellido, 51);
                            strncpy(arrayAsociado[indice].dni,bDni, 15);
                            arrayAsociado[indice].edad = atoi(bEdad);
                            arrayAsociado[indice].id=auxId;
                            arrayAsociado[indice].estado= ID_OCUPADO;

                            retorno=0;
                        }
                    }

                }
            }
        }
    }
    return retorno;
}

//**********************************************************************************************************************************

int aso_initArray (sAsociado* arrayAsociado, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAsociado != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayAsociado[i].estado = ID_LIBRE;
        }

    }
    return retorno;
}


//**********************************************************************************************************************************

int aso_printAsociado (sAsociado* arrayAsociado, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAsociado != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociado[i].estado == ID_OCUPADO)
            {
                printf("\nID: %d  \nNombre: %s  \nApellido: %s  \nDNI: %s  \nEdad: %d\n",arrayAsociado[i].id,arrayAsociado[i].nombre,arrayAsociado[i].apellido, arrayAsociado[i].dni, arrayAsociado[i].edad);
            }
        }
    }
    return retorno;
}

//**********************************************************************************************************************************
/*
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
*/

//**********************************************************************************************************************************

int aso_buscaProxId (sAsociado* arrayAsociado, int longitud)
{
    int i,idMax=-1;
    if(arrayAsociado != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociado[i].estado == ID_OCUPADO)
            {
                if(idMax<arrayAsociado[i].id)
                {
                    idMax=arrayAsociado[i].id;
                }
            }
        }

    }
    return idMax+1;
}
//**********************************************************************************************************************************

int aso_buscarIndicePorID(sAsociado* arrayAsociado, int id, int longitud,char mensajeError[])
{
    int i;
    int retorno=-1;
    if(arrayAsociado != NULL && longitud > 0 && id >=0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociado[i].estado == ID_OCUPADO)
            {
                if(id==arrayAsociado[i].id)
                {
                    retorno=i;
                    break;
                }
            }
        }
        if(retorno == -1)
            printf(mensajeError);
    }

    return retorno;
}



//**********************************************************************************************************************************


int aso_modificarProductoXid (sAsociado* arrayAsociado,int longitud)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];
    char bId[10];
    int idComparar,index;

    if(arrayAsociado != NULL && longitud >= 0)
    {
        val_getUnsignedInt(bId,"\nIngrese ID: ","\nID no valido,",3,10);
        idComparar=atoi(bId);
        index=aso_buscarIndicePorID(arrayAsociado,idComparar,longitud,"\nEl Id no existe");
        if(index!=-1)
        {
            if(val_getString(bNombre,"\nNOMBRE: ","\nError:\n",3,51)==0)
            {
                if(val_getString(bApellido,"\nAPELLIDO: ","\nError:\n",3,51)==0)
                {
                    strncpy(arrayAsociado[index].nombre,bNombre,51);
                    strncpy(arrayAsociado[index].apellido, bApellido, 51);
                    retorno=0;
                }

            }
        }

    }
    return retorno;
}

//**********************************************************************************************************************************

int aso_bajaAsociado (sAsociado* arrayAsociado,int longitud)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];
    char bId[10];
    int idComparar,index;

    if(arrayAsociado != NULL && longitud >= 0)
    {
        val_getUnsignedInt(bId,"\nIngrese ID: ","\nID no valido,",3,10);
        idComparar=atoi(bId);
        index=aso_buscarIndicePorID(arrayAsociado,idComparar,longitud,"\nEl Id no existe");
        if(index!=-1)
        {
            arrayAsociado[index].estado=ID_LIBRE;
            retorno=0;
        }

    }
    return retorno;
}
