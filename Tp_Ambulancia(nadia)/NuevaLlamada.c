#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Asociado.h"
#include "NuevaLlamada.h"
#include "validar.h"

int llamada_initLlamada (sLlamada* arrayLlamada, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayLlamada != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayLlamada[i].estadoLlamada = ESTADO_LLAMADA_LIBRE;
            arrayLlamada[i].contadorLlamadas=0;
            arrayLlamada[i].contadorMotivos=0;
            arrayLlamada[i].tiempo=0;
            retorno=0;
        }

    }
    return retorno;
}
////**********************************************************************************************************************************
int llamada_nuevaLlamada (sLlamada* arrayLlamada, sAsociado* arrayAsociado, int longitudAsoc,int longitudLlamada, char mensajeError[])
{
    int retorno = -1;
    char buffer[10];
    int idComparar,index,contIntentos=0;
    int flagMotivo=0;

    if((arrayLlamada != NULL && arrayAsociado!=NULL) && (longitudAsoc >= 0 && longitudLlamada>=0))
    {
        val_getUnsignedInt(buffer,"\nIngrese ID: ","\nID no valido ",3,10);
        idComparar=atoi(buffer);
        index=asoc_buscarIndiceAsociadoPorID(arrayAsociado,idComparar,longitudAsoc,"El Id no existe");
        if(index!=-1 && arrayLlamada[index].estadoLlamada!=ESTADO_LLAMADA_PENDIENTE)
        {
            do
            {
                val_getUnsignedInt(buffer,"Seleccione motivo de la llamada: \n1-INFARTO\n2-ACV\n3-GRIPE\n","Opcion erronea \n",3,10);
                switch(atoi(buffer))
                {
                case 1:
                    arrayLlamada[index].motivo=MOTIVO_INFARTO;
                    arrayLlamada[index].contadorMotivos++;
                    flagMotivo=1;
                    break;
                case 2:
                    arrayLlamada[index].motivo=MOTIVO_ACV;
                    arrayLlamada[index].contadorMotivos++;
                    flagMotivo=1;
                    break;
                case 3:
                    arrayLlamada[index].motivo=MOTIVO_GRIPE;
                    arrayLlamada[index].contadorMotivos++;
                    flagMotivo=1;
                    break;
                }
                contIntentos++;
            }
            while(flagMotivo==0 && contIntentos<3);
            if(flagMotivo==1)
            {
                arrayLlamada[index].idAsoc=arrayAsociado[index].id; // preguntar Mauricio
                arrayLlamada[index].estadoLlamada=ESTADO_LLAMADA_PENDIENTE;
                arrayLlamada[index].contadorLlamadas++;
                retorno=0;
            }
        }
        else
            printf("%s",mensajeError);

    }
    return retorno;
}

////**********************************************************************************************************************************

int llamada_print(sLlamada* arrayLlamada, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayLlamada != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayLlamada[i].estado == ESTADO_LLAMADA_PENDIENTE)
            {
                printf("\nID: %d \nMotivo de la llamada: %d",arrayLlamada[i].idAsoc,arrayLlamada[i].motivo);
            }
        }

    }
    return retorno;
}
////**********************************************************************************************************************************

int llamada_buscarIndicePorID (sLlamada* arrayLlamada, int id, int longitud,char mensajeError[])
{
    int i;
    int retorno=-1;
    if(arrayLlamada != NULL && longitud > 0 && id >=0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(id==arrayLlamada[i].idAsoc)
            {
                retorno=i;
                break;
            }
        }
        if(retorno==-1)
            printf("%s",mensajeError);
    }

    return retorno;
}
////**********************************************************************************************************************************
int llamada_cumplida (sLlamada* arrayLlamada, int longitud, char mensaje[])
{
    int retorno=-1;
    char buffer[10];
    int index;
    int id;
    int idAmbulancia;

    val_getUnsignedInt(buffer,"Ingrese ID: ","Id no valido",3,10);
    id=(atoi(buffer));
    index=llamada_buscarIndicePorID(arrayLlamada,id,longitud,"No existe el ID ingresado");
    if(index!=-1 && arrayLlamada[index].estadoLlamada==ESTADO_LLAMADA_PENDIENTE)
    {
        val_getUnsignedInt(buffer,"\nIngrese el ID de la ambulancia: ", "\nFormato ID invalido",3,10);
        idAmbulancia=(atoi(buffer));
        if(val_getUnsignedInt(buffer,"\nIngrese el tiempo insumido en minutos: ", "\nFormato de tiempo invalido",3,10)==0)

        {
            arrayLlamada[index].idAmbulancia=idAmbulancia;
            arrayLlamada[index].tiempo=atoi(buffer);
            arrayLlamada[index].estadoLlamada=ESTADO_LLAMADA_CUMPLID0;
            retorno=0;
        }
    }
     else
        printf("%s",mensaje);
    return retorno;
}
////**********************************************************************************************************************************
int llamada_asocMasLlamadas(sLlamada* arrayllamada, int longitud, char mensajeError[])
{
    int i, maximo, retorno=-1;
    maximo=0;
    for(i=0; i<longitud; i++)
    {
        if(maximo<arrayllamada[i].contadorLlamadas)
        {
            maximo=arrayllamada[i].contadorLlamadas;
            retorno=arrayllamada[i].idAsoc;
        }
    }
    if (retorno==-1)
        printf("%s",mensajeError);
    return retorno;
}
////**********************************************************************************************************************************

int llamada_printAsociadosMasLlamadas (sAsociado* arrayAsociado, sLlamada* arrayLlamada, int longitudAsoc, int longitudLlamada)
{
    int retorno = -1;
    int id,index;
    if(arrayAsociado != NULL && longitudAsoc > 0)
    {
        id=llamada_asocMasLlamadas(arrayLlamada,longitudLlamada,"Sin llamadas");
        index=asoc_buscarIndiceAsociadoPorID(arrayAsociado,id,longitudAsoc,"Error");
        if(index!=-1)
        {
            printf("El asociado con mayor cantidad de llamadas es: \nNombre: %s\nApellido: %s\nCantidad de llamadas: %d\n",arrayAsociado[index].nombre,arrayAsociado[index].apellido,arrayLlamada[index].contadorLlamadas);
        }
    }
    return retorno;
}
