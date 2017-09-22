#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED
typedef struct
{
    int idAsociado;
    int idAmbulancia;
    unsigned char motivo;
    unsigned char estadoLlamada;
    int idLlamada;
    int tiempo;
    //contador de llamadas (cont de c/motivo); tiempoInsumido; idLLamada
} sLlamada;


#endif // LLAMADA_H_INCLUDED

#define MOTIVO_INFARTO 0
#define MOTIVO_ACV 1
#define MOTIVO_GRIPE 2

#define ESTADO_LLAMADA_PENDIENTE 0
#define ESTADO_LLAMADA_CUMPLIDO 1

#define AMBULANCIAS 3


int llamada_nuevaLlamada(sLlamada* arrayLlamada, sAsociado* arrayAsociado,int longitud, int longitudAsociado, char msj[]);
int llamada_asignarAmbulancia (sLlamada* arrayLlamada, int longitud, sAsociado* arrayAsociado, int longAsociado, char* msj,  char* msjAmbulancia);
