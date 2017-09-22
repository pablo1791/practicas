#ifndef _PRODUCTO_H_INCLUDED
#define _PRODUCTO_H_INCLUDED
typedef struct{
    int id;
    char nombre[51];
    char apellido[51];
    char dni[15];
    unsigned char edad;
    unsigned char estado;
}sAsociado;
#endif // _PRODUCTO_H_INCLUDED

#define ID_LIBRE 0
#define ID_OCUPADO 1


int aso_cargarAsociado (sAsociado* arrayAsociado, int indice, int longitud);
int aso_buscaProxId (sAsociado* arrayAsociado, int longitud);
int aso_initArray (sAsociado* arrayAsociado, int longitud);
int aso_printAsociado (sAsociado* arrayAsociado, int longitud);
int aso_buscarIndicePorID (sAsociado* arrayAsociado, int id, int longitud,char mensajeError[]);
int aso_modificarProductoXid (sAsociado* arrayAsociado,int longitud);
int aso_bajaAsociado (sAsociado* arrayAsociado,int longitud);

