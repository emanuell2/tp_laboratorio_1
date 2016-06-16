#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "lib.h"
#include "validations.h"
#define LARGO 3

int main()
{
    sMovies moviesArray[LARGO];
    menuF(moviesArray, LARGO);
    return 0;
}
