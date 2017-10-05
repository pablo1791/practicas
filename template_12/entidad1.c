#include <stdio.h>
#include <stdlib.h>
#include "entidad1.h"
#include <string.h>


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int ent1_init(Entidad1* arrayEntidad1, int longitud)
{
    int i;
    for(i=0; i<longitud; i++)
    {
        arrayEntidad1[i].flagOcupado=0;
    }
    return 0;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
    static int ultimoValorAutoincrementable=-1; //si esta afuera la puede utilizar cualquier funcion de este .c
int ent1_generarProximoId(Entidad1* arrayEntidad1, int longitud)
{
    static int ultimoValorAutoincrementable=-1; //si esta adentro solo la usa esta funcion
    ultimoValorAutoincrementable++;
    return ultimoValorAutoincrementable;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
static int ent1_buscarPosicionLibre(Entidad1* arrayEntidad1, int longitud)
{
    //devuelve el primer index vacio del array, la voy a usar para el alta de entidad;
    return 0;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int ent_alta(Entidad1* arrayEntidad1, int longitud)
{
    int retorno = -1;
    //1 buscar posicion libre
    //2 generar id
    //3 pedir datos al usuario (validados)
    //4 cargar datos en item (indide) vacio
    int indexVacio = ent1_buscarPosicionLibre(arrayEntidad1, longitud);
    int idNuevo = ent1_generarProximoId(arrayEntidad1, longitud);
    // pido datos al usuario (depende del problema)
    char bufferAuxNombre[50];
    if(val_getString(bufferAuxNombre, "ingrese nombre", "nombre invalido", 3, 50)!=-1)
    {
        //campo bien cargado
        //cargo datos en el item
        arrayEntidad1[indexVacio].flagOcupado=1;
        arrayEntidad1[indexVacio].id=idNuevo;
        strncpy(arrayEntidad1[indexVacio].a, bufferAuxNombre, 50);
        retorno=0;
    }
    return retorno;
}
int ent1_buscarIndicePorId(Entidad1* arrayEntidad1, int longitud)
{

}

int ent1_modificar(Entidad1* arrayEntidad1, int longitud, int id)
{
    //1 busco la posicion donde esta el id
    //2 pedir datos nuevos
    //3 cargo en los campos

    //ent1_buscarIndicePorId();
}


int ent1_buscarIndicePorDni(Entidad1* arrayentidad1, int longitud, char dni)
{

}
