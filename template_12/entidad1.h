#ifndef ENTIDAD1_H_INCLUDED
#define ENTIDAD1_H_INCLUDED
typedef struct
{
    int id;
    int flagOcupado; //1 ocupado 0 vacio
    char a;
    int b;
} Entidad1;


#endif // ENTIDAD1_H_INCLUDED
 int ent1_init(Entidad1* arrayEntidad1, int longitud);
// int ent1_generarProximoId(Entidad1* arrayEntidad1, int longitud); no van xq son internas (con static)
// int ent1_buscarPosicionLibre(Entidad1* arrayEntidad1, int longitud);
 int ent_alta(Entidad1* arrayEntidad1, int longitud);
 int ent1_modificar(Entidad1* arrayEntidad1, int longitud, int id);
