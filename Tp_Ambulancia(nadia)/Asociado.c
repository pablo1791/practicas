#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Asociado.h"
#include "NuevaLlamada.h"
#include "validar.h"

//typedef struct{
//    char nombre [20];
//    char apellido [40];
//    char dni [10];
//    unsigned char edad;
//    int id;
//    unsigned char estado;
//}sAsociado;

int asoc_cargarAsociados (sAsociado* arrayAsociado, int index, int longitud)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];
    char bDni[11];
    char bEdad[4];
    int auxId;


    if(arrayAsociado != NULL && index >= 0 && index<=longitud)
    {
        if(val_getString(bNombre,"\nNombre: ","\nError:\n",3,51)==0)
        {
            if(val_getString(bApellido,"\nApellido: ","\nError:\n",3,51)==0)
            {
                if(val_getStringWithPoints(bDni,"\nDni: ","\nEl formato valido es xx.xxx.xxx",3,11)==0)
                {
                    if(val_getUnsignedInt(bEdad,"\nEdad: ","\nError:\n",3,4)==0)
                    {
                        auxId=asoc_buscaProxId(arrayAsociado,longitud);
                        if(auxId!=-1)
                        {
                            strncpy(arrayAsociado[index].nombre,bNombre,51);
                            strncpy(arrayAsociado[index].apellido,bApellido,51);
                            strncpy(arrayAsociado[index].dni,bDni,11);
                            arrayAsociado[index].edad=atoi(bEdad);
                            arrayAsociado[index].id=auxId;
                            arrayAsociado[index].estado=ID_OCUPADO;
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

int asoc_buscaProxId (sAsociado* arrayAsociado, int longitud)
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


int asoc_initAsociados (sAsociado* arrayAsociado, int longitud)
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

int asoc_buscarIndiceAsociadoPorID (sAsociado* arrayAsociado, int id, int longitud,char mensajeError[])
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
        if(retorno==-1)
        {
            printf("%s",mensajeError);
        }
    }


    return retorno;
}

//**********************************************************************************************************************************
int asoc_modificarAsociadoPorId (sAsociado* arrayAsociado,int longitud)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];
    int auxId;
    char bId[10];
    int idComparar,index;

    if(arrayAsociado != NULL && longitud >= 0)
    {
        val_getUnsignedInt(bId,"\nIngrese ID: ","\nID no valido ",3,10);
        idComparar=atoi(bId);
        index=asoc_buscarIndiceAsociadoPorID(arrayAsociado,idComparar,longitud,"El Id no existe");
        if(index!=-1)
        {
            if(val_getString(bNombre,"\nNombre: ","\nError:\n",3,51)==0)
            {
                if(val_getString(bApellido,"\nApellido: ","\nError:\n",3,51)==0)
                {
                    auxId=asoc_buscaProxId(arrayAsociado,longitud);
                    if(auxId!=-1)
                    {
                        strncpy(arrayAsociado[index].nombre,bNombre,51);
                        strncpy(arrayAsociado[index].apellido,bApellido,51);
                        retorno=0;
                    }

                }

            }
        }
    }
    return retorno;
}
//**********************************************************************************************************************************

int asoc_bajaAsociado (sAsociado* arrayAsociado,int longitud)
{
    int retorno = -1;
    char bId[10];
    int idComparar,index;

    if(arrayAsociado != NULL && longitud >= 0)
    {
        val_getUnsignedInt(bId,"\nIngrese ID a eliminar: ","\nID no valido ",3,10);
        idComparar=atoi(bId);
        index=asoc_buscarIndiceAsociadoPorID(arrayAsociado,idComparar,longitud,"El Id no existe");
        if(index!=-1)
        {
            arrayAsociado[index].estado=ID_LIBRE;
            retorno=0;
        }
    }
    return retorno;
}
