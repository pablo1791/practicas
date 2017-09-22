#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define CANT 2

int main()
{
    int i;
   // char nombre[CANT][20];
    int edad[CANT][3];



    for(i=0; i<CANT; i++)
    {
        altaEdad("\ningrese edad: ", edad[i]);
        //altaEdad("\ningrese edad: ", edad[i]);
    }

    //printf("NOMBRE: \t EDAD\n");
    for(i=0; i<CANT; i++)
    {
        printf("%d", edad[i]);
    }




//    char aux[51];
//    //strcpy(aux, "--Hello world!\n");
//    //strncpy(aux, "--Hello world!88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888\n", 51); //limirto la copia a la dimension del array
//    //strcpy(aux, "--Hello world!88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888\n"); esta no esta limitada y desborda la memoria xq el array es de 51
//    aux[50]='\0';
//     strncpy(aux, "hola", 51);
//    printf("---> %s - el largo es: %d\n",aux, strlen(aux));
//    //printf(aux);
//    printf("%d\n",strcmp("A","B"));
//    printf("%d\n",strcmp("B","A"));
//    printf("%d\n",strcmp("A","A"));// tiene en cuenta las mayus y minusculas
//   //strcmpi()//tiene en no cuenta mayus y minus
//    char buffer2[40]= "hola";
//   char buffer[4];
//   fgets(buffer, 4, stdin);
//   //scanf("%s", buffer);
//    printf("%s\n", buffer);
//    printf("%s\n", buffer2);



    return 0;
}
