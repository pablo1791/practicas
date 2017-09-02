#include <stdio.h>
#include <stdlib.h>
#include"Lib.h"
#define CANT_EMPLEADOS 2


int salarioMaximo(float sueldo[], int qtyMaxima, float promedio);
int main()
{
    int edad[CANT_EMPLEADOS];
    float salario[CANT_EMPLEADOS];

   obtenerDatos ( edad, salario, CANT_EMPLEADOS);
   mostrarDatos(edad, salario, CANT_EMPLEADOS);


            return 0;
}
//hacer promedio y maximo de edad
