#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
#define CANT 2

 //&array[0]==array (ambos hacen referencia a la primer posicion de memoria/primer subindice)

int main()
{
    int i=0;
    int edad[CANT];
    int salario[CANT];
    for(i=0; i<CANT; i++)
    {
        if(tomarNumero("INGRESE EDAD ", &edad[i], 100, 0) == -1)
        {
            printf("error de edad");
        }
        if(tomarNumero("INGRESE SALARIO ", &salario[i], 1000, 10) == -1)
        {
            printf("error de salario");
        }
//        printf("INGRESE EDAD DEL %d\247 EMPLEADO: \n", i+1); // si hago \247 desp de la mascara marca "º" pero tengo que poner i+1
//        scanf("%d", &edad[i]);
//        printf("INGRESE SALARIO: \n");
//        scanf("%d", &salario[i]);
    }
    printf("\nLISTA DE EMPLEADOS\n");
    for(i=0; i<CANT; i++)
    {
        printf("EDAD %d\t\tSALARIO %d\n", edad[i], salario[i]);
    }
    return 0;
}


