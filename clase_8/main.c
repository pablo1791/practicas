#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct persona
{
    char nombre[20];
    char apellido[20];
    char dni[20];
    int edad;
};
/*
typedef struct
{
    char nombre[20];
    char apellido[20];
    char dni[20];
    int edad;
}sPersona;
*/

int main()
{
    struct persona aux;   //sPersona aux;
    strncpy(aux.nombre, "pablo", 19);
    aux.nombre[19]='\0';
    strncpy(aux.apellido, "campos", 19);
    aux.apellido[19]='\0';
    strncpy(aux.dni, "30.167.180", 19);
    aux.dni[19]='\0';
    aux.edad=26;

    printf("nombre: %s\n",aux.nombre);
    printf("apellido: %s\n",aux.apellido);
    printf("dni: %s\n",aux.dni);
    printf("edad: %d\n",aux.edad);


    return 0;
}
