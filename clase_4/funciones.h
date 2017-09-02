#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define SUMA 0
#define RESTA 1
#define MULTIPLICACION 2
#define DIVISION 3

int calculadora(float* resultadoDivision, float* resultadoSuma, float* resultadoResta, float* resultadoMultiplica, float num1, float num2);
int calculadora2(float* resultado, float num1, float num2, char operacion);


//EN EL .H VAN los prototipos y los defines. (por lo tanto en el .c y main solo se llama al .h )
//si a una funcion la decalro con static es privada del archivo, por lo que no debo poner el prototipo en el .h pero si debo colocar el prototipo arriba en el mismo archivo


#endif //FUNCIONES_H_INCLUDED
