#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "llamada.h"
#include "validar.h"

int llamada_nuevaLlamada(sLlamada* arrayLlamada, sAsociado* arrayAsociado,int longitud, int longitudAsociado, char msj[])
{

    int retorno = -1;
    char buffer[10];
    int idComparar,index, contIntentos=0, flag=0;

    if((arrayLlamada != NULL && longitud >= 0) || (arrayAsociado != NULL && longitud >= 0))
    {
        val_getUnsignedInt(buffer,"\nIngrese ID: ","\nID no valido,",3,10);
        idComparar=atoi(buffer);
        index=aso_buscarIndicePorID(arrayAsociado,idComparar,longitud,"\nEl Id no existe\n");
        if(index!=-1)
        {
            do
            {
                val_getUnsignedInt(buffer,"\nINGRESE MOTIVO DE LLAMADA\n1-INFARTO\n2-ACV\n3-GRIPE\n", "ERROR ", 3, 10);
                switch(atoi(buffer))
                {
                case 1:
                    arrayLlamada[idComparar].motivo=MOTIVO_INFARTO;
                    arrayLlamada[idComparar].estadoLlamada=ESTADO_LLAMADA_PENDIENTE;
                    arrayLlamada[idComparar].idAsociado=arrayAsociado[index].id;
                    flag=1;
                    break;
                case 2:
                    arrayLlamada[idComparar].motivo=MOTIVO_ACV;
                    arrayLlamada[idComparar].estadoLlamada=ESTADO_LLAMADA_PENDIENTE;
                    arrayLlamada[idComparar].idAsociado=arrayAsociado[index].id;
                    flag=1;
                    break;
                case 3:
                    arrayLlamada[idComparar].motivo=MOTIVO_GRIPE;
                    arrayLlamada[idComparar].estadoLlamada=ESTADO_LLAMADA_PENDIENTE;
                    arrayLlamada[idComparar].idAsociado=arrayAsociado[index].id;
                    flag=1;
                    break;
                }
                contIntentos ++;
            }
            while(flag == 0);

            retorno=0;
            arrayLlamada[idComparar].estadoLlamada=ESTADO_LLAMADA_PENDIENTE;
            arrayLlamada[idComparar].idAsociado=arrayAsociado[index].id;

        }

    }
    return retorno;
}

//**********************************************************************************************************************************

int llamada_asignarAmbulancia (sLlamada* arrayLlamada, int longitud, sAsociado* arrayAsociado, int longAsociado, char* msj,  char* msjAmbulancia)
{
    int retorno=-1, i;
    char bId[10];
    int idIngresado;
    char btiempo[100];

    idIngresado=val_getUnsignedInt(bId, "ingrese id: \n", "error\n", 3, 10);

    if(arrayLlamada[idIngresado].estadoLlamada==ESTADO_LLAMADA_PENDIENTE)
    {
        for(i=0; i<AMBULANCIAS; i++)
        {
            if(i<AMBULANCIAS)
            {
                arrayLlamada[idIngresado].idAmbulancia=i+1;
                val_getUnsignedInt(btiempo, "ingrese tiempo en minutos\n", "solo numeros\n", 3, 100);
                arrayLlamada[idIngresado].tiempo=atoi(btiempo);
                retorno = 0;
            }
            else
                printf(msjAmbulancia);
        }
        arrayLlamada[idIngresado].estadoLlamada=ESTADO_LLAMADA_CUMPLIDO;
    }
    else
        printf(msj);

    return retorno;
}
