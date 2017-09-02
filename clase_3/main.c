#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"


int main()
{
    float num1, num2;
    float resulDiv, resulMult, resulSuma, resulResta;

    printf("ingrese num1: \n");
    scanf("%f", &num1);
    printf("ingrese num2: \n");
    scanf("%f", &num2);

   if(division(num1, num2, &resulDiv, &resulMult, &resulSuma, &resulResta))
   {
       printf("ERROR. No se puede dividir por 0\n");
       printf("la multiplicacion es: %.2f\n", resulMult);
       printf("la suma es: %.2f\n", resulSuma);
       printf("la resta es: %.2f", resulResta);
   }else
   {
       printf("la division es: %.2f\n", resulDiv);
       printf("la multiplicacion es: %.2f\n", resulMult);
       printf("la suma es: %.2f\n", resulSuma);
       printf("la resta es: %.2f", resulResta);
   }


    return 0;
}


