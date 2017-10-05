#include <stdio.h>
#include <stdlib.h>
#include "Asociado.h"
#include "NuevaLlamada.h"
#include "validar.h"
#define CANTIDAD 3

int main()
{
    sAsociado arrayAsociado[CANTIDAD];
    sLlamada arrayLlamada [CANTIDAD];
    char buffer [10];

    asoc_initAsociados(arrayAsociado,CANTIDAD);
    llamada_initLlamada(arrayLlamada,CANTIDAD);

    do
    {
        val_getUnsignedInt(buffer,"\nIngrese una opcion: \n1. Alta\n2. Modificar\n3. Baja\n4. Nueva llamada\n5. Asignar\n6. Informar\n7. Salir\n","La opcion ingresada no es valida",3,10);
        switch(atoi(buffer))
        {
        case 1:
            asoc_cargarAsociados(arrayAsociado,asoc_buscaProxId(arrayAsociado,CANTIDAD),CANTIDAD);
            break;
        case 2:
            asoc_modificarAsociadoPorId(arrayAsociado,CANTIDAD);
            break;
        case 3:
           asoc_bajaAsociado(arrayAsociado,CANTIDAD);
            break;
        case 4:
            llamada_nuevaLlamada(arrayLlamada,arrayAsociado,CANTIDAD,CANTIDAD,"El asociado posee posee una llamada pendiente");
            break;
        case 5:
            llamada_cumplida(arrayLlamada,CANTIDAD,"El id no posee llamadas pendientes");
            break;
        case 6:
            llamada_printAsociadosMasLlamadas(arrayAsociado,arrayLlamada,CANTIDAD,CANTIDAD);
            break;
        case 7:
            break;
        }

    }while(atoi(buffer)!=7);
    return 0;
}
