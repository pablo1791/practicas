#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED

typedef struct{
    char nombre [20];
    char apellido [40];
    char dni [10];
    unsigned char edad;
    int id;
    unsigned char estado;
}sAsociado;

#endif // ASOCIADO_H_INCLUDED
#define ID_LIBRE 0
#define ID_OCUPADO 1

int asoc_cargarAsociados (sAsociado* arrayAsociado, int index, int longitud);
int asoc_buscaProxId (sAsociado* arrayAsociado, int longitud);
int asoc_initAsociados (sAsociado* arrayAsociado, int longitud);

int asoc_buscarIndiceAsociadoPorID (sAsociado* arrayAsociado, int id, int longitud,char mensajeError[]);
int asoc_modificarAsociadoPorId (sAsociado* arrayAsociado,int longitud);
int asoc_bajaAsociado (sAsociado* arrayAsociado,int longitud);
//int asoc_printAsociados (sAsociado* arrayAsociado, sLlamada* arrayLlamada, int longitudAsoc, int longitudLlamada);
