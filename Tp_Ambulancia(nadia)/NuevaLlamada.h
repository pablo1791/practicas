
#ifndef _NUEVALLAMADA_H_INCLUDED
#define _NUEVALLAMADA_H_INCLUDED

typedef struct{
    int idAsoc;
    unsigned char motivo;
    unsigned char estadoLlamada;
    int idAmbulancia;
    char estado[51];
    unsigned char flag;
    int tiempo;
    int contadorLlamadas;
    int contadorMotivos;
  }sLlamada;

#endif // _NUEVALLAMADA_H_INCLUDED

#define MOTIVO_INFARTO 0
#define MOTIVO_ACV 1
#define MOTIVO_GRIPE 2

#define ESTADO_LLAMADA_PENDIENTE 0
#define ESTADO_LLAMADA_CUMPLID0 1
#define ESTADO_LLAMADA_LIBRE 2

int llamada_nuevaLlamada (sLlamada* arrayLlamada, sAsociado* arrayAsociado, int longitudAsoc,int longitudLlamada, char mensajeError[]);
int llamada_initLlamada (sLlamada* arrayLlamada, int longitud);
int llamada_print(sLlamada* arrayLlamada, int longitud);
int llamada_buscarIndicePorID (sLlamada* arrayLlamada, int id, int longitud,char mensajeError[]);
int llamada_cumplida (sLlamada* arrayLlamada, int longitud, char mensaje[]);
int llamada_cumplida (sLlamada* arrayLlamada, int longitud, char mensaje[]);
int llamada_asocMasLlamadas(sLlamada* arrayllamada, int longitud, char mensajeError[]);
int llamada_printAsociadosMasLlamadas (sAsociado* arrayAsociado, sLlamada* arrayLlamada, int longitudAsoc, int longitudLlamada);




