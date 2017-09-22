#ifndef _PRODUCTO
#define _PRODUCTO
typedef struct{
    char nombre[51];
    char desc[51];
    float precio;
    int id;
    unsigned char estado;
}sProducto;
#endif // _PRODUCTO

#define PRODUCTO_LIBRE 0
#define PRODUCTO_OCUPADO 1


int prod_cargarProducto (sProducto* arrayProducto, int index, int len);
int prod_printProducto (sProducto* arrayProducto, int longitud);
int prod_initProducto (sProducto* arrayProducto, int longitud);
int prod_buscarProductoLibre (sProducto* arrayProducto, int longitud);
int prod_buscaProxId (sProducto* arrayProducto, int longitud);
int prod_buscarIndicePorID (sProducto* arrayProducto, int id, int longitud,char mensajeError[]);
int prod_modificarProducto(sProducto* arrayProducto, int index);
int prod_modificarProductoXid (sProducto* arrayProducto,int longitud);
