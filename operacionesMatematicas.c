#include <stdio.h>
#include <conio.h>

float sumarNumeros (float sumaNumero1, float sumaNumero2)//Implementacion de la funcion sumarNumeros
{
    float resultadoSuma;

    resultadoSuma = sumaNumero1+sumaNumero2;

    return resultadoSuma;
}

float restarNumeros (float restaNumero1, float restaNumero2)//Implementacion de la funcion restarNumeros
{
    float resultadoResta;

    resultadoResta = restaNumero1-restaNumero2;

    return resultadoResta;
}

float multiplicarNumeros(float multipNumero1, float multipNumero2)//Implementacion de la funcion multiplicarNumeros
{
    float resultadoMultiplicacion;

    resultadoMultiplicacion = multipNumero1*multipNumero2;

    return resultadoMultiplicacion;
}

float dividirNumeros(float divNumero1, float divNumero2)//Implementacion de la funcion dividirNumeros
{
    float resultadoDivision;

    if(divNumero2 == 0)
    {
        return 0;
    }
    else
    {
        resultadoDivision = divNumero1/divNumero2;
    }

    return resultadoDivision;

}

int funcionFactorial(int numeroFactorial)//Implementacion de la funcion factorial
{
    int resultadoFactorial;

      if(numeroFactorial == 1)
    {

        return 1;
    }
    else
    {
        resultadoFactorial = numeroFactorial*funcionFactorial(numeroFactorial-1);

        return resultadoFactorial;
    }

}




















