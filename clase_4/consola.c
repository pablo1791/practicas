#include <stdio.h>
#include <stdlib.h>
#include "consola.h"
int tomarNumero(char mensaje[], float* valorIngresado, float maximo, float minimo)
{
    int retorno=-1;
    printf(mensaje); //printf("%s", &mensaje) con esta opcion no van las llaves en el parametro
    // el %s va
    scanf("%f", valorIngresado);
    if(*valorIngresado<maximo && *valorIngresado>minimo)
    {
        retorno=0;
    }
    return retorno;
}


/* probar esta opcion con auxiliar
int retorno=-1;
float aux;
   printf("%s", mensaje); //printf("%s", &mensaje) con esta opcion no va las llaves en el parametro
           // el %s va
   scanf("%f", aux);
   if(*aux<maximo && *aux>minimo)
   {
        *valorIngresado=aux;
        retorno=0;
   }
   return retorno;
*/
