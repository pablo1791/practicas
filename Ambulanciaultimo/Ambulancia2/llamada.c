#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "llamada.h"
#include "validar.h"


int llamada_initArray (sLlamada* arrayLlamada, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayLlamada != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayLlamada[i].estadoLlamada = ESTADO_SIN_USO;
            arrayLlamada[i].tiempo = 0;
            arrayLlamada[i].idAsociado = -1;
            arrayLlamada[i].motivo = -1;
        }
        retorno = 0;
    }
    return retorno;
}

static int idLlamadaAutoincrementable = -1;

int llamada_generarProximoIndice (void)
{
    idLlamadaAutoincrementable++;
    return idLlamadaAutoincrementable;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int llamada_buscarLlamadasPendientes (sPersona* arrayPersona, sLlamada* arrayLlamada, int lontidudPersona, int lontigudLlamada, int id)
{
    int retorno = 0;
    int i;

    for(i=0; i<lontidudPersona; i++)
    {
        if(id == arrayPersona[i].id)
        {
            for(i=0; i<lontigudLlamada; i++)
            {
                if(arrayLlamada[i].estadoLlamada == ESTADO_PENDIENTE && arrayLlamada[i].idAsociado == id)
                {
                    retorno = -1;
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int llamada_nuevaLlamada (sLlamada* arrayLlamada,sPersona* arrayPersona,int longitudPersona, int longitudLlamada, char* mensajeError, char* mensajeError2)
{
    int retorno = -1;
    int idAux, indice;
    int flagMotivo = 0;
    char buffer[10];
    int indicePersona;
    int contadorIntentos = 0;
    int i;

    if((arrayLlamada != NULL && arrayPersona != NULL) && (longitudLlamada >= 0 && longitudPersona  >= 0))
    {
        for(i=0; i<longitudLlamada; i++)
        {
            if(arrayLlamada[i].estadoLlamada == ESTADO_SIN_USO)
            {
                indice = i;
                break;
            }
        }
        val_getUnsignedInt(buffer,"\nIngrese su Id: ", "\nIngrese solo numeros",3,10);

        idAux = atoi(buffer);
        indicePersona = persona_buscarIndicePorId(arrayPersona,longitudPersona,idAux, "\nNo se encontro el id");

        if(indicePersona != -1)
        {
            if(llamada_buscarLlamadasPendientes(arrayPersona, arrayLlamada,longitudPersona,longitudLlamada,idAux)== -1)
            {
                printf("%s", mensajeError2);
            }
            else
            {
                for(i=0; i<longitudLlamada; i++)
                {
                    do
                    {
                        val_getUnsignedInt(buffer,"\n1-Infarto.\n2- ACV.\n3- Gripe.\n\nIngrese un motivo: ","\nError, ingrese un numero",3,10);
                        switch(atoi(buffer))
                        {
                        case 1:
                            arrayLlamada[indice].motivo = MOTIVO_INFARTO;
                            flagMotivo = 1;
                            break;
                        case 2:
                            arrayLlamada[indice].motivo = MOTIVO_ACV;
                            flagMotivo = 1;
                            break;
                        case 3:
                            arrayLlamada[indice].motivo = MOTIVO_GRIPE;
                            flagMotivo = 1;
                            break;
                        }
                        contadorIntentos ++;
                    }
                    while (flagMotivo == 0 && contadorIntentos < 3);

                    if(flagMotivo == 1)
                    {
                        arrayLlamada[indice].idAsociado = arrayPersona[indicePersona].id;
                        arrayLlamada[indice].estadoLlamada = ESTADO_PENDIENTE;
                        arrayLlamada[indice].idLlamada = llamada_generarProximoIndice();
                        retorno = 0;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}


int llamada_finLlamada (sPersona* arrayPersona,sLlamada* arrayLlamada,int longitudPersona, int longitudLlamada, char* mensaje)
{
    int retorno = -1;
    char idAux[10];
    char tiempo[100];
    int idAmbulancia;
    int id, i;
    int indice;

    val_getUnsignedInt(idAux,"Ingrese su id: ","Ingrese un id valido",2,10);
    id = atoi(idAux);

    indice = persona_buscarIndicePorId(arrayPersona,longitudPersona,id,"El id no existe");

    if(indice != -1 )
    {
        if(llamada_buscarLlamadasPendientes(arrayPersona, arrayLlamada,longitudPersona,longitudLlamada,id)== 0)
        {
            printf("%s", mensaje);
        }
        else
        {
            for(i=0; i<longitudLlamada; i++)
            {
                if(arrayLlamada[i].estadoLlamada == ESTADO_PENDIENTE && arrayLlamada[i].idAsociado == id)
                {
                    val_getUnsignedInt(idAux, "Ingrese el Id de la ambulancia que lo atendio: ","Error, solo puede ingresar numeros: ",3,10);
                    idAmbulancia = atoi(idAux);

                    if(val_getUnsignedInt(tiempo, "Ingrese el tiempo que llevo la consulta (en minutos): ", "Error, solo se permiten numeros: ",3,10)== 0)
                    {
                        arrayLlamada[i].idAmbulancia = idAmbulancia;
                        arrayLlamada[i].tiempo = atoi(tiempo);
                        arrayLlamada[i].estadoLlamada = ESTADO_CUMPLIDO;
                        retorno = 0;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int llamada_buscarIndicePorId (sLlamada* arrayLlamada, int longitud, int id, char* mensaje)
{
    int retorno = -1;
    int i;

    if(arrayLlamada != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayLlamada[i].idAsociado == id)
            {
                retorno = i;
                break;
            }
        }
        if(retorno == -1)
        {
            printf("%s", mensaje);
        }
    }
    return retorno;
}


int llamada_buscarMayorCantLlamadas (sLlamada* arrayLlamada, sPersona* arrayPersona, int longitudPersona, int longitudLlamada, char* mensajeError)
{
    int retorno = -1;
    int llamadasArray[longitudLlamada];
    int idLlamada[longitudLlamada];
    int posicionPersona, posicionLlamada;
    int i, id, max = 0;

    for(i= 0; i<longitudLlamada; i++)
    {
        llamadasArray[i] = 0;
        idLlamada[i] = -1;
    }

    if((arrayLlamada != NULL && arrayPersona != NULL) && (longitudLlamada > 0 && longitudPersona > 0))
    {
        for(posicionPersona=0; posicionPersona<longitudPersona; posicionPersona++)
        {
            if(arrayPersona[posicionPersona].estado == PERSONA_OCUPADO)
            {
                for(i=0; i<longitudLlamada; i++)
                {
                    if(idLlamada[i] == -1)
                    {
                        idLlamada[i] = arrayPersona[posicionPersona].id;
                        for(posicionLlamada=0; posicionLlamada<longitudLlamada; posicionLlamada++)
                        {
                            if(arrayLlamada[posicionLlamada].idAsociado == arrayPersona[posicionPersona].id && arrayLlamada[posicionLlamada].estadoLlamada == ESTADO_CUMPLIDO)
                            {
                                llamadasArray[i]++;
                            }
                        }
                        break;
                    }
                }
            }
        }
        for(i=0; i<longitudLlamada; i++)
        {
            if(llamadasArray[i] > max)
            {
                max = llamadasArray[i];
                id = idLlamada[i];
            }
        }
        retorno = id;
    }

    if(retorno == -1)
    {
        printf("%s", mensajeError);
    }
    return retorno;
}




/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int llamada_buscarMayorMotivo (sLlamada* arrayLlamada, int longitud, char* mensajeError)
{
    int retorno = -1;
    int i, maximoMotivo;
    int arrayMotivos[3];

    for(i= 0; i<3; i++)
    {
        arrayMotivos[i] = 0;
    }

    for(i= 0; i<longitud; i++)
    {
        if(arrayLlamada[i].estadoLlamada == ESTADO_CUMPLIDO)
        {
            if(arrayLlamada[i].motivo == MOTIVO_INFARTO)
            {
                arrayMotivos[MOTIVO_INFARTO]++;
            }
            else if(arrayLlamada[i].motivo == MOTIVO_ACV)
            {
                arrayMotivos[MOTIVO_ACV]++;
            }
            else if(arrayLlamada[i].motivo == MOTIVO_GRIPE)
            {
                arrayMotivos[MOTIVO_GRIPE]++;
            }
        }
    }
    maximoMotivo = arrayMotivos[0];

    for(i= 0; i<3; i++)
    {
        if(arrayMotivos[i] >= maximoMotivo)
        {
            maximoMotivo = arrayMotivos[i];
            retorno = i;
        }
//        else
//        {
//            if (arrayMotivos[MOTIVO_INFARTO] == arrayMotivos[MOTIVO_ACV])
//                retorno = 3;
//            else if(arrayMotivos[MOTIVO_ACV] == arrayMotivos[MOTIVO_GRIPE])
//                retorno = 4;
//            else if(arrayMotivos[MOTIVO_INFARTO] == arrayMotivos[MOTIVO_GRIPE])
//                retorno = 5;
//            else if (arrayMotivos[MOTIVO_INFARTO] == arrayMotivos[MOTIVO_GRIPE] && arrayMotivos[MOTIVO_INFARTO] == arrayMotivos[MOTIVO_ACV])
//                retorno = 6;
//        }
    }


    if(retorno == -1)
    {
        printf("%s", mensajeError);
    }
    return retorno;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int llamada_obtenerCantidadMotivo (sLlamada* arrayLlamada, int longitud,int mayorMotivo)
{
    int retorno = -1;
    int i, cantidadMotivo = 0;
    int arrayMotivos[3];

    for(i= 0; i<3; i++)
    {
        arrayMotivos[i] = 0;
    }

    for(i= 0; i<longitud; i++)
    {
        if(arrayLlamada[i].estadoLlamada == ESTADO_CUMPLIDO)
        {
            if(arrayLlamada[i].motivo == MOTIVO_INFARTO )
            {
                arrayMotivos[MOTIVO_INFARTO]++;
            }
            else if(arrayLlamada[i].motivo == MOTIVO_ACV  )
            {
                arrayMotivos[MOTIVO_ACV]++;
            }
            else if(arrayLlamada[i].motivo == MOTIVO_GRIPE )
            {
                arrayMotivos[MOTIVO_GRIPE]++;
            }
        }
    }

    for(i= 0; i<3; i++)
    {
        if(arrayMotivos[i] >= cantidadMotivo)
        {
            cantidadMotivo = arrayMotivos[i];
            retorno = cantidadMotivo;
        }
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int llamada_printPersona (sPersona* arrayPersona, sLlamada* arrayLlamada, int longitudPersona, int longitudLlamada)
{
    int retorno = -1;
    int idAux,i,posicion;
    int cantidadMotivo;
    int motivo;
    int motivoMasDemora;

    if((arrayLlamada != NULL && arrayPersona != NULL) && (longitudLlamada > 0 && longitudPersona > 0))
    {
        idAux = llamada_buscarMayorCantLlamadas(arrayLlamada,arrayPersona,longitudPersona,longitudLlamada,"Sin llamadas");

        motivo = llamada_buscarMayorMotivo(arrayLlamada,longitudLlamada,"No hubo llamadas");

        cantidadMotivo = llamada_obtenerCantidadMotivo(arrayLlamada,longitudLlamada,motivo);

        motivoMasDemora = llamada_calcularPromediodeMotivos(arrayLlamada,longitudLlamada);

        for(posicion=0; posicion<longitudPersona; posicion++)
        {
            if(arrayPersona[posicion].estado == PERSONA_OCUPADO)
            {
                for(i=0; i<longitudLlamada; i++)
                {
                    if(arrayPersona[posicion].id == arrayLlamada[i].idAsociado && arrayLlamada[i].estadoLlamada == ESTADO_CUMPLIDO)
                    {
                        printf("\n\nPosicion: %d", posicion);
                        printf("\nId: %d", arrayPersona[posicion].id);
                        printf("\nNombre: %s", arrayPersona[posicion].nombre);
                        printf("\nApellido: %s", arrayPersona[posicion].apellido);
                        printf("\nPosicion llamada: %d", arrayLlamada[i].idLlamada);
                        printf("\nEstado de llamada: %d", arrayLlamada[i].estadoLlamada);
                        printf("\nMotivo: %d", arrayLlamada[i].motivo);
                    }
                }
            }
        }

        printf("\n\nEl id con mas cantidad de llamadas es: %d", idAux);
        printf("\nEl asociado con mas llamados es: %s %s", arrayPersona[idAux].nombre, arrayPersona[idAux].apellido);

        if(motivo == MOTIVO_INFARTO || motivo == MOTIVO_ACV || motivo == MOTIVO_GRIPE)
            printf("\nEl mayor motivo consultado fue el %d con %d llamadas ",motivo,cantidadMotivo);

        printf("\nEl motivo que en promedio demora mas en atender es: %d", motivoMasDemora);
    }
    return retorno;
}


int llamada_calcularPromediodeMotivos (sLlamada* arrayLlamada, int longitudLlamada)
{
    int retorno = 0;
    int i;
    int arrayMotivos[3];
    float arrayTiempoMotivos[3];
    float promedioMotivos[3];
    float maxPromedio = 0;


    for(i= 0; i<3; i++)
    {
        arrayMotivos[i] = 0;
        arrayTiempoMotivos[i] = 0;
    }

    for(i= 0; i<longitudLlamada; i++)
    {
        if(arrayLlamada[i].estadoLlamada == ESTADO_CUMPLIDO)
        {
            if(arrayLlamada[i].motivo == MOTIVO_INFARTO )
            {
                arrayMotivos[MOTIVO_INFARTO]++;
                arrayTiempoMotivos[MOTIVO_INFARTO] = arrayTiempoMotivos[MOTIVO_INFARTO] + arrayLlamada[i].tiempo;
            }
            else if(arrayLlamada[i].motivo == MOTIVO_ACV  )
            {
                arrayMotivos[MOTIVO_ACV]++;
                arrayTiempoMotivos[MOTIVO_ACV] = arrayTiempoMotivos[MOTIVO_INFARTO] + arrayLlamada[i].tiempo;
            }
            else if(arrayLlamada[i].motivo == MOTIVO_GRIPE )
            {
                arrayMotivos[MOTIVO_GRIPE]++;
                arrayTiempoMotivos[MOTIVO_GRIPE] = arrayTiempoMotivos[MOTIVO_INFARTO] + arrayLlamada[i].tiempo;
            }
        }
    }
    for(i= 0; i<3; i++)
    {
        promedioMotivos[i] = arrayTiempoMotivos[i] / arrayMotivos[i];
    }

    for(i= 0; i<3; i++)
    {
        if(promedioMotivos[i] > maxPromedio)
        {
            maxPromedio = promedioMotivos[i];
            retorno = i;
        }
    }

    return retorno;
}














