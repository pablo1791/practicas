/** \brief divide
 *
 * \param
 * \param
 * \return (0) ok - (-1) Error
 *
 */

/*int division(float a, float b, float* aux)
{
    int retorno=-1;
    if(b!=0)
    {
        *aux=a/b;
        retorno=0;
    }

        return retorno;
}*/

int division(float a, float b, float* dividir, float* multiplicar, float* sumar, float* resta)
{
    int retorno=-1;
    if(b!=0)
    {
        *dividir=a/b;
        retorno=0;
    }

    *multiplicar=a*b;
    *sumar=a+b;
    *resta=a-b;
        return retorno;
}
