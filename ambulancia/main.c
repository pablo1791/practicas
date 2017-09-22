#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include "validar.h"
#include "llamada.h"

#define CANT 4
#define AMBULANCIAS 3


int main()
{
    /***************************************/

    /***************************************/


    sAsociado arrayAsociado[CANT];
    sLlamada arrayLlamada[CANT];

    char bufferInt[40];
    aso_initArray(arrayAsociado, CANT);


    do
    {
        val_getUnsignedInt(bufferInt, "1-ALTA ASOCIADO\n2-MODIFICAR\n3-BAJA ASOCIADO\n4-NUEVA LLAMADA\n5-ASIGNAR\n6-INFORMAR\n7-SALIR\n","ERROR\n", 3, 40);
        switch(atoi(bufferInt))
        {
        case 1:
            aso_cargarAsociado(arrayAsociado, aso_buscaProxId(arrayAsociado, CANT), CANT);
            break;
        case 2:
            aso_modificarProductoXid(arrayAsociado, CANT);
            break;
        case 3:
            aso_bajaAsociado(arrayAsociado, CANT);
            break;
        case 4:
            llamada_nuevaLlamada(arrayLlamada, arrayAsociado, CANT, CANT, "OPCION INVALIDA");
            break;
        case 5:
            llamada_asignarAmbulancia(arrayLlamada, CANT, arrayAsociado, AMBULANCIAS, "id no encontrado\n", "no hay ambulancia disponible\n");
            break;
        case 6:

            break;
        case 7:
              aso_printAsociado(arrayAsociado, CANT);
            break;

        }

    }
    while( atoi(bufferInt) != 8);





    return 0;
}
