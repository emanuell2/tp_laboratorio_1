#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "validations.h"

/** \brief pide un string y lo valida
 *
 * \param cadena a ser validada
 * \param mensaje
    \param mensaje de error
    \param limite maximo de caracteres
    \param lmite minimo de caracteres
 * \return retorna un int 0 si fue exitosos 1 si no lo fue
 *
 */

int getStringw(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char cadenaIngresada[hiLimit];
    int validacionCadena;
    int returCadena = -1;

    while(returCadena == -1)
    {
        printf("%s", message);
        fflush(stdin);
        validacionCadena = scanf("%s", cadenaIngresada);

        if(validacionCadena)
        {
            if(strlen(cadenaIngresada) > lowLimit && strlen(cadenaIngresada)<hiLimit)
            {
               strcpy(input, cadenaIngresada);
                returCadena = 0;
            }
            else
            {
                printf("%s", eMessage);
            }
        }
    }

    return returCadena;

}
/** \brief pide un int y lo valida
 *
 * \param int a validar
 * \param mensaje
    \param mensaje de error
    \param limite minimo de numeros
    \param limite maximo de numeros
 * \return retorna un int0 si fue exitosos -1 si no lo fue
 *
 */

int getIntw(int input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int auxiliar;
    int resultadoScanf;
    int returnGet = -1;

    while(returnGet == -1)
    {
        printf("%s", message);
        fflush(stdin);
        resultadoScanf = scanf("%d", &auxiliar);

        if(resultadoScanf)
        {
           if(auxiliar > lowLimit && auxiliar < hiLimit)
           {
               input = auxiliar;
                returnGet = 0;
           }
           else
           {
               printf("%s", eMessage);
           }
        }
    }


    return returnGet;
}
