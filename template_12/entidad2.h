#ifndef ENTIDAD2_H_INCLUDED
#define ENTIDAD2_H_INCLUDED

typedef struct
{
    int id;
    int idEntidad1;
    int flagOcupado; //1 ocupado 0 vacio
    char a;
    int b;
} Entidad2;


#endif // ENTIDAD2_H_INCLUDED
int ent2_init(Entidad2* arrayEntidad2, int longitud);
int ent2_generarProximoId(Entidad2* arrayEntidad2, int longitud);
int ent2_buscarPosicionLibre(Entidad2* arrayEntidad2, int longitud);
