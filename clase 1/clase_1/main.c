#include <stdio.h>
#include <stdlib.h>
#define CANT 4

int main()
{
    int num;
    int contPOS=0;
    int contNEG=0;
    int i;
    int acumPOS=0;
    int acumNEG=0;
    float promPOS;
    float promNEG;


    for(i=0; i<CANT; i++)
    {

        system("cls");

        printf("ingrese numero: \n");
        scanf("%d", &num);
        if(num >0)
        {
            contPOS++;
            acumPOS=num+acumPOS;
        }
        else
        {
            contNEG++;
            acumNEG=acumNEG +num;
        }
    }
    if(contPOS != 0)
    {
        promPOS=(float)acumPOS/contPOS;
    }
    if(contNEG != 0)
    {
        promNEG=(float)acumNEG/contNEG;
    }


    printf("CANT POSITIVOS: %d \nCANT NEGATIVOS: %d", contPOS, contNEG);
    printf("\nPROM POS: %.2f \nPROM NEG: %.2f", promPOS, promNEG);
    return 0;
}
