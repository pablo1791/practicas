#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"

#define MAX_INPUT_BUFFER 4096


void myFgets(char* buffer, int limite,FILE* archivo)
{
    int i=0;
    fflush(stdin);
    fgets(buffer, limite,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}

//**************************************************************************************

int val_getString(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarString(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }


        }



    }
    return retorno;
}

//**************************************************************************************

int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarFloat(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

//**************************************************************************************

int val_validarString(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z'))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

//**************************************************************************************

int val_validarFloat(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.' && buffer[i] != '-' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}

//**************************************************************************************

int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarUnsignedInt(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

//**************************************************************************************

int val_validarUnsignedInt(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}

//**************************************************************************************

int val_getStringWithPoints(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarDni(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
//**************************************************************************************
int val_validarDni(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.')
        {
            retorno = -1;
            break;
        }
        else
        {
            if((buffer[i] == '.' && i==2) ||(buffer[i]== '.' && i==6))
            {
                flagPunto++;
            }
        }
        i++;
    }
    if(flagPunto!=2)
    {
        retorno = -1;
    }
    return retorno;
}
//**************************************************************************************

int val_getStringAge(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarEdad(buffer) == -1 || (atoi(buffer)<0 || atoi(buffer)>100))
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
//**************************************************************************************
int val_validarEdad(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}
