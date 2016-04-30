#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define LARGO 6

int main()
{
    int option;
    sEmployee myEmployees[LARGO];
    isEmptyInit(myEmployees, LARGO);
    char auxName[50];


    do
    {
        system("cls");
        printf(" 1. Agregar\n 2. Borrar \n 3. Listar \n 4. Grafico de Edades \n 5. salir \n");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)
        {
        case 1: addEmployee(myEmployees, LARGO);
            break;
        case 2: //modifyEmployee(myEmployees, LARGO, 50);
                eraseEmployee(myEmployees, LARGO);
            break;
        case 3: showEmployees(myEmployees, LARGO);
            break;
        case 4: graphicAges(myEmployees, LARGO);
            break;
        case 5:
            break;
            default: printf("Ingrese una opcion valida \n");
        }

        system("pause");

    }while(option != 5);



    return 0;
}
