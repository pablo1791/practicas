#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "consola.h"


int main()
{
    printf("***********INGRESE DATOS***********\n\n");
    float rSuma,rResta,rMulti,rDivision,y,x;

    if(tomarNumero("ingrese 1er numero entre 0 y 99: \n", &x, MAXIMO, MINIMO)== -1)
    {
        printf("error de rango\n");
    }
    if(tomarNumero("ingrese 2do numero entre 0 y 99: \n", &y, MAXIMO, MINIMO)== -1)
    {
        printf("error de rango en el 2do numero\n");
    }






    /*printf("Ingrese el primer numero :\n");
    scanf("%f",&x);
    printf("Ingrese el segundo numero : \n");
    scanf("%f",&y);*/

    printf("\n\n************RESULTADO************\n\n");
    if(calculadora(&rDivision,&rSuma,&rResta,&rMulti,x,y)== -1)
    {
        printf("Error");
    }
    else
    {
        printf("La division es : %.2f",rDivision);
    }
    printf("\nLa suma es: %.2f", rSuma);
    printf("\nLa resta es: %.2f",rResta);
    printf("\nLa multiplicacion es %.2f", rMulti);


    //****************************************************
    printf("\n\n************RESULTADO************");
    calculadora2(&rDivision,x,y,DIVISION);
    printf("\n\nLa division es : %.2f",rDivision);

    calculadora2(&rMulti,x,y,MULTIPLICACION);
    printf("\nLa suma es : %.2f",rMulti);

    calculadora2(&rResta,x,y,RESTA);
    printf("\nLa resta es : %.2f",rResta);

    calculadora2(&rSuma,x,y,SUMA);
    printf("\nLa suma es : %.2f",rSuma);

    return 0;
}
