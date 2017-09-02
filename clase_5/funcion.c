#include <stdio.h>
#include <stdlib.h>
int tomarNumero(char mensaje[], int* valorIngresado, int maximo, int minimo)
{
    int retorno=-1;
    printf(mensaje); //printf("%s", &mensaje) con esta opcion no van las llaves en el parametro
    // el %s va
    scanf("%d", valorIngresado);
    if(*valorIngresado<maximo && *valorIngresado>minimo)
    {
        retorno=0;
    }
    return retorno;
}
