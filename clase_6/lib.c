#include <stdio.h>
#include <stdlib.h>

void imprimirCadena(char cadena[])
{
    int i=0;
    int flagEncontreFinal=0;
    while(flagEncontreFinal==0)
    {
        char c= cadena[i];
        if(c!=0)
        {
            printf("%c", c);
        }
        else
        {
            flagEncontreFinal=1;
        }
    }
}


//ORDENAMIENTOS
int ordenar(int a[], int len)
{
    int flagEncontroCambio, aux,i;
    do
    {
        flagEncontroCambio=0;
        for(i=0; i< len-1; i++)
        {
            if(a[i] > a[i+1])
            {
                flagEncontroCambio=1;
                aux=a[i];
                a[i]=a[i+1];
                a[i+1]=aux;
            }
        }
    }
    while(flagEncontroCambio == 1);
    return 0;
}


