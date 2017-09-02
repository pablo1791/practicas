#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int max, min, aux, prom;
    int acum=0;

    printf("ingrese un numero: ");
    scanf("%d", &aux);
    max=aux;
    min=aux;
    acum=aux;
    for(i=0; i<4; i++)
    {
       printf("ingrese otro num: ");
       scanf("%d", &aux);
       if(aux > max)
       {
           max=aux;
       }
       if(aux < min)
       {
           min=aux;
       }
    }
    acum=acum+aux;
    prom=acum/5;

    printf("el numero maximo es: %d\n", max);
    printf("el numero minimo es: %d\n", min);
    printf("el numero promedio es: %d\n", prom);
    return 0;
}

