#include <stdio.h>
#include <stdlib.h>
#include <math.h> //Llamado a la libreria math para el uso del fmod
#include "operacionesMatematicas.h" //Llamado a la libreria creada operacionesMatematicas.h

int main()
{
    //Declaracion de variables
    char decisionOperacion;//Variable que almacena el dato de la eleccion
    float ingresoPrimero;//Variable que almacena el dato del primer numero
    float ingresoSegundo;//Variable que almacena el dato del primer numero
    int flag, flag2, loopFlag;//Variables que almacenan flags
    flag = 1;//flag utilizado para validar si el usuario ingreso el primer numero
    flag2 = 1;//Flag utilizado para validar el ingreso del segundo numero
    loopFlag = 1;//Flag para validar condicion de corte de do while

    do
    {
       system("cls");//limpia la consola

         printf(" Elija la opcion: \n");

         if(flag == 1 && flag2 == 1)
         {
            printf("1. Para ingresar el primer operando. \n");
            printf("2. Para ingresar el segundo operando \n");
            printf("3. Para realizar una suma. \n");
            printf("4. Para realizar una resta. \n");
            printf("5. Para realizar una multiplicacion. \n");
            printf("6. Para realizar una division. \n");
            printf("7. Para realizar el factorial\n");
            printf("8. Para el resultado de todas las operaciones. \n");
            printf("9. Para salir \n \n");

        }

         if(flag == 0 && flag2 == 1)
         {
            printf("1. El primer operando es %.2f \n", ingresoPrimero);
            printf("2. Para ingresar el segundo operando \n");
            printf("3. Para realizar una suma. \n");
            printf("4. Para realizar una resta. \n");
            printf("5. Para realizar una multiplicacion. \n");
            printf("6. Para realizar una division. \n");
            printf("7. Para realizar el factorial\n");
            printf("8. Para el resultado de todas las operaciones. \n");
            printf("9. Para salir \n \n");

         }
         if (flag2 == 0 && flag ==1)
         {

            printf("1. Para ingresar el primer operando. \n");
            printf("2. El segundo operando es %.2f  \n", ingresoSegundo);
            printf("3. Para realizar una suma. \n");
            printf("4. Para realizar una resta. \n");
            printf("5. Para realizar una multiplicacion. \n");
            printf("6. Para realizar una division. \n");
            printf("7. Para realizar el factorial\n");
            printf("8. Para el resultado de todas las operaciones. \n");
            printf("9. Para salir \n \n");
         }

        if(flag == 0 && flag2 == 0)
        {
            printf("1. El primer operando es %.2f \n", ingresoPrimero);
            printf("2. El segundo operando es %.2f  \n", ingresoSegundo);
            printf("3. Para realizar una suma. \n");
            printf("4. Para realizar una resta. \n");
            printf("5. Para realizar una multiplicacion. \n");
            printf("6. Para realizar una division. \n");
            printf("7. Para realizar el factorial\n");
            printf("8. Para el resultado de todas las operaciones. \n");
            printf("9. Para salir \n \n");
        }

        decisionOperacion = getch()-'0';//Asigna el numero pasado a decisionOperacion

        switch(decisionOperacion)//Utiliza este numero en la decision del switch
        {

            case 1: printf("Ingrese el operando deseado ");
                    scanf("%f", &ingresoPrimero);//ingreso del primer numero
                    if(flag)//Verifica si el numero fue ingresado
                    {
                        flag=0;
                    }
                break;
            case 2: printf("Ingrese el operando deseado ");
                    scanf("%f", &ingresoSegundo);//Ingreso de lsegundo numero
                    if(flag2)//Verifica si el numero fue ingresado
                    {
                        flag2=0;
                    }
                break;
            case 3: if(flag == 0 && flag2 == 0)//Verifica que ambos numeros fueron ingresados
                    {
                        printf("El resultado de la suma es:  %.2f \n", sumarNumeros(ingresoPrimero, ingresoSegundo));//llama a la funcion sumarNumeros
                    }else
                        {
                            printf("Aun te falta ingresar un operando !!!");
                        }
                break;
            case 4: if(flag == 0 && flag2 == 0)//Verifica que ambos numeros fueron ingresados
                    {
                        printf("El resultado de la resta es:  %.2f \n", restarNumeros(ingresoPrimero, ingresoSegundo));//llama a la funcion restarNumeros
                    }else
                        {
                            printf("Aun te falta ingresar un operando !!!");
                        }
                break;
            case 5: if(flag == 0 && flag2 == 0)//Verifica que ambos numeros fueron ingresados
                    {
                        printf("El resultado de la miltiplicacion es:  %.2f \n", multiplicarNumeros(ingresoPrimero, ingresoSegundo));//llama a la funcion multiplicarNumeros
                    }else
                        {
                            printf("Aun te falta ingresar un operando !!!");
                        }
                break;
            case 6: if(flag == 0 && flag2 == 0 && ingresoSegundo != 0)//Verifica que ambos numeros fueron ingresados
                    {
                        printf("El resultado de la division es:  %.2f \n", dividirNumeros(ingresoPrimero, ingresoSegundo)); //LLama a la funcion dividirNumeros
                    }
                    else
                    {   if(ingresoSegundo == 0)//valida la division por 0
                        {
                            printf("No se puede dividir por 0!!!");
                        }
                        else
                        {
                            printf("Te esta faltando un operando!!!");
                        }

                    }
                break;
            case 7: if(flag == 0 && ingresoPrimero < 32)//Valida que no se ingrese un numero que el compilador no pueda resolver.
                    {
                        if(fmod(ingresoPrimero, 1)== 0) //Valida que el numero no sea un decimal
                        {
                            printf("El factorial de %.2f es %d \n", ingresoPrimero, funcionFactorial(ingresoPrimero));//Llama a la funcion factorial para el primer numero
                        }
                        else
                        {
                            printf("No podes hacer factorial de un decimal \n");
                        }

                    }
                    else
                    {
                        printf("La computadora no puede calcular un factorial tan alto \n");
                    }
                    if(flag2 == 0 && ingresoSegundo < 32)//Valida que no se ingrese un numero que el compilador no pueda resolver.
                    {
                        if(fmod(ingresoSegundo, 1)== 0)//Valida que el numero no sea un decimal
                        {
                            printf("El factorial de %.2f es %d \n", ingresoSegundo, funcionFactorial(ingresoSegundo));//Llama a la funcion factorial para el segundo numero
                        }
                        else
                        {
                            printf("No podes hacer factorial de un decimal \n");
                        }

                    }
                    else
                    {
                        printf("La computadora no puede calcular un factorial tan alto \n");
                    }
                break;
            case 8: if(flag == 0 && flag2 == 0)//Verifica que ambos numeros fueron ingresados
                    {
                        //LLama a todas las funciones de operacionesMatematicas
                        printf("El resultado de la suma es:  %.2f \n", sumarNumeros(ingresoPrimero, ingresoSegundo));
                        printf("El resultado de la resta es:  %.2f \n", restarNumeros(ingresoPrimero, ingresoSegundo));
                        printf("El resultado de la multiplicacion es:  %.2f \n", multiplicarNumeros(ingresoPrimero, ingresoSegundo));
                        printf("El resultado de la division es:  %.2f \n", dividirNumeros(ingresoPrimero, ingresoSegundo));
                        printf("El factorial de %.2f es %d \n", ingresoPrimero, funcionFactorial(ingresoPrimero));
                        printf("El factorial de %.2f es %d \n", ingresoSegundo, funcionFactorial(ingresoSegundo));
                    }
                    else
                        {
                            printf("Aun te falta ingresar un operando !!! \n");
                        }
                break;
            case 9: loopFlag = 0; //modifica el flag para salir del bucle
                break;
            default: printf("Ingrese una opcion valida \n");



        }
     system("pause");//Pausa para poder revisar los resultados pedidos

    }while(loopFlag);

return 0;




}


