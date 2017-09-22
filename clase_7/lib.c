#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int altaEdad(char mensaje[], int* string)  //int altaNombre(char* mensaje, char* string)
{
    char buffer[4096];
    int retorno=-1;    //valor invalido
    printf(mensaje);
    fgets(buffer, 4096, stdin);
    buffer[4095]='\0';
    if(validarInt(*buffer)==0)
    {
        *string=atoi(buffer);
        retorno=0;
    }
    return retorno;
}
int alta(char mensaje[], char string[])
{
    printf(mensaje);
    fgets(string, 20, stdin);
    return 0;
}

int validarInt(char* buffer)
{
    int retorno=0, i=0;
    while(buffer[i]!= '\0')
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


