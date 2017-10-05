#include <stdio.h>
#include <stdlib.h>
#include "entidad2.h"
#include "entidad1.h"
#include "informes.h"

void imprimirTodo(Entidad1* arrayEntidad1, int longitudEnt1, Entidad2* arrayEntidad2, int longitudEnt2)
{
    int index2;
    for(index2=0; i<longitudEnt2; i++)
    {
        if(arrayEntidad2[index2].flagOcupado==1)
        {
            int idEnt1 = arrayEntidad2[index2].idEntidad1;
            int index = ent1_buscarIndicePorId(arrayEntidad1, longitudEnt1, idEnt1);



        printf("%d\t %s\t %d\t %s\n", arrayEntidad1[index].id, arrayEntidad1[index].a, arrayEntidad2[index2].b, arrayEntidad1[index2].a);
        }
    }

}
