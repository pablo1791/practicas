#include <stdio.h>
#include <stdlib.h>
#include "entidad2.h"
#include "entidad1.h"

#define LONG_ENTIDAD1 50
#define LONG_ENTIDAD2 50
int main()
{
    Entidad1 listaEntidades1[LONG_ENTIDAD1];
    Entidad2 listaEntidades2[LONG_ENTIDAD2];

    ent1_init(listaEntidades1, LONG_ENTIDAD1);
    ent2_init(listaEntidades2, LONG_ENTIDAD2);

    return 0;
}
