#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>

void isEmptyInit(sEmployee myEmployees[], int length)
{
    int i;
    for(i=0; i<length; i++)
    {
        myEmployees[i].isEmpty = 1;
    }
}

int espacioLibre(sEmployee lista[], int length)
{
    int i;
    int espacioLibreReturn=-1;

    for(i=0;i<length;i++)
    {
        if(lista[i].isEmpty == 1)
        {
            espacioLibreReturn = i;
            break;
        }
    }
    return espacioLibreReturn;
}



void addEmployee(sEmployee myEmployees[], int length)
{
    int firstSpace = espacioLibre(myEmployees, length);
    int dni;
    int dniValidate;
    int age;
    int flag = 0;
    int flag2 = 0;

    if(firstSpace >= 0)
    {
       if(myEmployees[firstSpace].isEmpty == 1)
        {

                fflush(stdin);
                printf("Ingrese el nombre de la persona\n");
                scanf("%s", &myEmployees[firstSpace].employeeName);



            while(flag == 0)
            {
                printf("Ingrese el dni de la persona (1.000.000 - 99.999.999)\n");
                fflush(stdin);
                dni = intValidation(100000, 99999999);
                dniValidate = validateDni(myEmployees, length, dni);
                if(dni == -1 && dniValidate == -1)
                {
                    printf("El dato ingresado es erroneo, es repetido o esta fuera de rango(1.000.000 - 99.999.999)\n");
                }
                else
                {
                    myEmployees[firstSpace].employeeDNI = dni;
                    flag = 1;
                }
            }

             while(flag2 == 0)
            {
                printf("Ingrese la edad de la persona (1 - 100)\n");
                fflush(stdin);
                age = intValidation(1, 100);
                if(age == -1)
                {
                    printf("El dato ingresado es erroneo o esta fuera de rango(1 - 100)\n");
                }
                else
                {
                    myEmployees[firstSpace].employeeAge = age;
                    flag2 = 1;
                }
            }
            myEmployees[firstSpace].isEmpty = 0;
        }
    }


}

int buscarPorDni(sEmployee myEmployee[], int length)
{
    int i;
    int dniReturn =-1;
    int getDni;

    fflush(stdin);
    scanf("%d", &getDni);

    for(i=0;i<length;i++)
    {
        if(myEmployee[i].isEmpty == 0 && getDni == myEmployee[i].employeeDNI)
        {
            dniReturn = i;
        }
    }
    return dniReturn;
}

void modifyEmployee(sEmployee myEmployee[], int length, int charLength)
{
    int getDni, auxInt;
    char auxName[charLength];
    int option;

    printf("Ingrese el dni del empleado a modificar");
    getDni = buscarPorDni(myEmployee, length);
    if(myEmployee[getDni].isEmpty == 0)
    {
        printf("Los datos del empleado a modificar son: \n\n");
        printf("%s\t %d\t %d\n", myEmployee[getDni].employeeName, myEmployee[getDni].employeeAge, myEmployee[getDni].employeeDNI);
        printf("Ingrese opcion a modificar \n");
        printf(" 1. Nombre \n 2. Edad\n 3. Dni\n");
        fflush(stdin);
        scanf("%d", &option);
        switch(option)
        {
            case 1: printf("Ingrese el nombre por el cual desea modificar");
                    fflush(stdin);
                    scanf("%s", auxName);
                    strcpy(myEmployee[getDni].employeeName, auxName);
                break;
            case 2:printf("Ingrese la edad por la cual desea modificar");
                    fflush(stdin);
                    scanf("%d", &auxInt);
                    myEmployee[getDni].employeeAge = auxInt;
                break;
            case 3:printf("Ingrese el dni por el cual desea modificar");
                    fflush(stdin);
                    scanf("%d", &auxInt);
                    myEmployee[getDni].employeeDNI = auxInt;
                break;
                    default: printf("ingrese una opcion valida");
        }
    }
}

void showEmployees(sEmployee myEmployee[], int length)
{
    int i;
    printf("NOMBRE \t EDAD \t DNI \t\n");
    for(i=0; i<length; i++)
    {
        if(myEmployee[i].isEmpty == 0)
        {
            orderByName(myEmployee, length);
            printf("%s\t %d\t %d\n", myEmployee[i].employeeName, myEmployee[i].employeeAge, myEmployee[i].employeeDNI);
        }
    }
}

void eraseEmployee(sEmployee myEmployee[], int length)
{
    int getDni;
    printf("Ingrese el dni de la persona a borrar\n");
    showEmployees(myEmployee, length);
    getDni = buscarPorDni(myEmployee, length);

    if(getDni != -1)
    {
        myEmployee[getDni].isEmpty =1;
    }
    else
    {
        printf("La persona no se encuentra en la lista\n");
    }



}

int orderByName(sEmployee myEmployee[], int length)
{
    int i, j;
    sEmployee auxEmployee;
    int returnOrder = -1;

    if(myEmployee != NULL)
    {
        for(i=0; i<length-1; i++)
        {
            for(j=i+1; j<length; j++)
            {
                    if(myEmployee[i].isEmpty == 0 && strcmp(myEmployee[i].employeeName, myEmployee[j].employeeName) > 0)
                    {
                            auxEmployee = myEmployee[i];
                            myEmployee[i] = myEmployee[j];
                            myEmployee[j] = auxEmployee;
                            returnOrder = 0;
                    }
            }
        }
        return returnOrder;
    }
}

void graphicAges(sEmployee myEmployee[], int length)
{
    int counter18=0;
    int counter18To35=0;
    int counterAbove35=0;
    int i;
    int biggestNumber;
    int flag =0;
    for(i=0;i<length;i++)
    {
        if(myEmployee[i].employeeAge <= 18)
        {
            counter18++;

        }
        if(myEmployee[i].employeeAge > 18 && myEmployee[i].employeeAge<35)
        {
            counter18To35++;

        }
        if(myEmployee[i].employeeAge >=35)
        {
            counterAbove35++;

        }
    }
    if(counter18 >= counter18To35 && counter18 >= counterAbove35)
    {
        biggestNumber = counter18;
    }
    else
    {
        if(counter18To35 >= counter18 && counter18To35 >= counterAbove35)
        {
            biggestNumber = counter18To35;
        }
        else{
        biggestNumber = counterAbove35;
        }
    }

    for(i=biggestNumber; i>0; i--)
    {
        if(i<3)
        {
            printf("%02d|",i);
        }
        else
        {
            printf("%02d|",i);
        }
        if(i<= counter18)
        {
            printf("*");
        }
        if(i<= counter18To35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= counterAbove35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
          printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", counter18, counter18To35, counterAbove35);


}

int intValidation(int minRange, int maxRange)
{
    int intNumber;
    int returnValidated = -1;
    fflush(stdin);
    int scanfVar = scanf("%d", &intNumber);
    if(scanfVar == 1 && intNumber>minRange && intNumber<maxRange)
    {
        returnValidated = intNumber;
    }
    return returnValidated;
}



int validateDni(sEmployee myEmployee[], int length, int numberDni)
{
    int i;
    int returnDni = 0;

    for(i=0;i<length;i++)
    {
        if(myEmployee[i].employeeDNI == numberDni)
        {
            returnDni = -1;
        }
    }

    return returnDni;
}
