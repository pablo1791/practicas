#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

//strlen devuelve la cantidad de caracteres que tiene el array. no cuenta el \0
//fgets(cadena, 16, stdin)  le pasamos la cadena donde escribo, el tamaño y stdin
//atoi convierte un char a entero
//atof convierte un char a flotante

int main()
{
    //imprimirCadena("");
    int num[5], i;
    for(i=0; i<5; i++)
    {
        printf("valor: ");
        scanf("%d", &num[i]);
    }
    ordenar(num, 5);
    for(i=0; i<5; i++)
    {
        printf("%d\n", num[i]);
    }

    return 0;
}

//insertion pero con for
//for(i=0; i<cant; i++)
//{
//    aux=a[i];
//    for(j=i-1; j >=0; j--)
//    {
//        if(aux<a[j])
//        {
//            a[j+1]=a[j];
//        }
//        else
//        {
//            a[j+1]=aux;
//            break;
//        }
//    }
//}







