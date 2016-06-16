#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "validations.h"


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
