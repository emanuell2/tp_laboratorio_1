#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "validations.h"
/** \brief Imprime un menu por pantalla
 *
 * \param Una estructura de tipo sMovies
 * \param  Un int para el largo
 * \return void
 *
 */

void menuF(sMovies movies[],int length)
{
    int option;
    int flag;
    initIsEmpty(movies, length);

    do
    {
        system("cls");
        printf("Ingrese una opcion\n\n");
        printf(" 1. Alta Pelicula \n 2. Modificar Datos de Pelicula \n 3. Dar de Baja Pelicula \n 4. Generar archivo con peliculas \n 5. Salir \n");
        fflush(stdin);
        scanf("%d", &option);
            switch(option)
        {
        case 1:
            if(addMovie(movies, length) == 0)
                printf("Agregado exitoso\n");
            else
                printf("Alguno de los parametros ingresados es erroneo o el espacio esta lleno. Borre una pelicula o intente reingresar\n");
            break;

        case 2:
            modifyMovie(movies, length);
            break;

        case 3:
            removeMovie(movies, length);
            break;
        case 4: fileGen(movies, "archivo.html", length);
            break;
        case 5:

        default:
            printf("Ingrese una opcion valida \n\n");
            break;
        }
        system("pause");
    }while(option != 5);

}
/** \brief Inicializa la variable is empty
 *
 * \param Una estructura de tipo sMovies
 * \param  Un int para el largo
 * \return void
 *
 */

void initIsEmpty(sMovies movies[], int length)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(movies != NULL && length >0)
        {
            movies[i].isEmpty = 1;
        }
    }
}
/** \brief busca el primer espacio libre en el array de peliculas
 *
 * \param Una estructura de tipo sMovies
 * \param  Un int para el largo
 * \return retorna el primer espacio libre o -1 si no fue exitoso
 *
 */

int firstFreeSpace(sMovies movies[], int length)
{
    int i;
    int freeReturn=-1;

    if(movies != NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(movies[i].isEmpty == 1)
            {
                freeReturn = i;
                break;
            }
        }
    }

    return freeReturn;
}
/** \brief retorna el id de un elemento de la estructura
 *
 * \param Una estructura de tipo sMovies
 * \param  Un int para el largo
 * \param Mensaje para el usuario
 * \return retorna el id si fue exitoso o -1 si no lo fue
 *
 *
 */

int getElementID(sMovies movies[], char message[], int length)
{
        int i;
        int returnELement = -1;
        int auxId;

        printf("%s", message);
        scanf("%d", &auxId);

        for(i=0;i<length;i++)
        {
            if(movies[i].isEmpty == 0 && movies != NULL && length>0 && auxId == movies[i].movieId)
            {
                returnELement = i;
            }
        }

    return returnELement;
}
/** \brief Guarda en una estructura en un archivo de tipo binario
 *
 * \param Una estructura de tipo sMovies
 * \return retorna 1 si la estrucutra es NULL o 0 si fue exitoso
 *
 */

int saveInFile(sMovies movies[])
{

	FILE *fp;

		fp=fopen("bin.dat","wb");
		if(movies == NULL)
		{
			return 1;
		}

	fwrite(movies,sizeof(sMovies),1,fp);

	fclose(fp);

	return 0;
}
/** \brief Carga un archivo de tipo binario
 *
 * \param Una estructura de tipo sMovies

 * \return retorna 1 si no encuentra el archivo o 0 si fue exitoso
 *
 */

int loadFromFile(sMovies movies[])
{
    int flag = 0;
	FILE *fp;

	fp=fopen("bin.dat", "rb");
	if(fp==NULL)
	{
		fp= fopen("bin.dat", "wb");
		if(fp==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	fread(movies,sizeof(sMovies),1,movies);
    }

	fclose(fp);
	return 0;
}
/** \brief agrega una pelicula a la estrucutra
 *
 * \param  Un int para el largo
 * \param Mensaje para el usuario
 * \return -1 si no fue exitosa la carga o 0 si lo fue
 *
 */

int addMovie(sMovies movies[], int length)
{
    int addReturn = -1;
    int aux;
    char stringNum;
    int freeSpace = firstFreeSpace(movies, length);
    FILE* archivoBin;
    archivoBin = fopen("archivoBin", "a");

        if(movies[freeSpace].isEmpty == 1 && movies != NULL && length > 0)
        {
            movies[freeSpace].movieId = freeSpace;
            fflush(stdin);
            getStringw(movies[freeSpace].movieTitle, "Ingrese el nombre de la pelicula\n", "Error el dato ingresado no posee el formato permitido o la cantidad minima de caracteres\n",1,50);


            fflush(stdin);
            getIntw(movies[freeSpace].mDuration, "Ingrese la duracion de la pelicula en minutos\n", "Error el Año ingresado no es correcto o esta fuera de los parametros\n", 1, 1000);

            fflush(stdin);
            getIntw(movies[freeSpace].mScore, "Ingrese el puntaje de la pelicula\n", "Dato invalido\n", 1, 100);

            fflush(stdin);
            getStringw(movies[freeSpace].genre, "Ingrese el genero de la pelicula\n", "Dato invalido \n", 1, 25);

            fflush(stdin);
            getStringw(movies[freeSpace].mDescription, "Ingrese un breve descripcion de la pelicula (Hasta 100 caracteres) \n", "Dato invalido \n", 1, 100);

            fflush(stdin);
            getStringw(movies[freeSpace].imageLink, "Ingrese un link de una imagen \n", "Dato Invalido", 1, 100);

            saveInFile(movies);
            movies[freeSpace].isEmpty = 0;
            addReturn = 0;

        }

    return addReturn;
}
/** \brief Borra una pelicula del array de estructuras
 *
 * \param  Un int para el largo
 * \param Mensaje para el usuario
 * \return -1 si no fue exitosa la carga o 0 si lo fue
 *
 */

int removeMovie(sMovies movies[], int length)
{
    int eraseId = getElementID(movies, "Ingrese el id de la pelicula que desea borrar\n", length);
    int returnRemove = -1;
    if(movies[eraseId].isEmpty == 0 && movies != NULL && length>0)
    {
        movies[eraseId].isEmpty = 1;
        printf("Pelicula removida con exito\n");
        returnRemove = 0;
    }
    else
    {
        printf("La pelicula que desea borrar no se encuentra en el listado\n");
    }

    return returnRemove;
}
/** \brief Modifica un parametro del array de estructuras
 *
 * \param  Un int para el largo
 * \param Mensaje para el usuario
 * \return -1 si no fue exitosa la carga o 0 si lo fue
 */

int modifyMovie(sMovies movies[], int length)
{
    int modifyId = getElementID(movies, "Ingrese el id de la pelicula que desea modificar\n", length);
    int modifyIdDirector;
    int returnModify = -1;
    int option;

    if(movies[modifyId].isEmpty == 0 && movies != NULL && length>0)
    {
        printf("Elija la opcion que desea modificar\n");
        printf("1. Nombre de pelicula \n 2. Duracion \n 3. Puntaje \n 4. Genero \n 5. Descripcion \n 6. Link de la imagen \n");
        listMovies(movies, modifyId, length);
        fflush(stdin);
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            getStringw(movies[modifyId].movieTitle, "Ingrese el nombre de la pelicula a modificar\n", "Error el dato ingresado no posee el formato permitido o la cantidad minima de caracteres\n",1,100);
            break;
        case 2:
            getIntw(movies[modifyId].mDuration, "Ingrese la duracion de la pelicula a modificar \n", "Error la duracion ingresada no es correcta o esta fuera de los parametros\n", 1, 1000);
            break;
        case 3:
            getIntw(movies[modifyId].mScore, "Ingrese el puntaje de la pelicula\n", "Dato invalido\n", 1, 100);
            break;
        case 4:
            getStringw(movies[modifyId].genre, "Ingrese el genero de la pelicula\n", "Dato invalido \n", 1, 25);
            break;
        case 5:
            getStringw(movies[modifyId].mDescription, "Ingrese un breve descripcion de la pelicula (Hasta 100 caracteres) \n", "Dato invalido \n", 1, 100);
            break;
        case 6:
            getStringw(movies[modifyId].imageLink, "Ingrese un link de una imagen \n", "Dato Invalido", 1, 100);
            break;
        default:
            printf("Ingrese una opcion valida");
        }
        returnModify = 0;
    }
    else
    {
        printf("El listado esta lleno o no hay ninguna pelicula cargada con ese id\n");
    }

    return returnModify;
}
/** \brief Lista las peliculas del array de estrucuturas
 *
* \param  Un int para el largo
 * \param Mensaje para el usuario
 * \param La variable id de la estructura
 * \return -1 si no fue exitosa la carga o 0 si lo fue
 *
 */

int listMovies(sMovies movies[] ,int id , int length)
{
    int returnList = -1;

            if(movies[id].isEmpty == 0 && movies != NULL && length>0)
            {
                printf("Titulo: %s \nDuracion: %d \nPuntaje: %d \nGenero: %s \nDescripcion: %s \nLink de Imagen: %s \n", movies[id].movieTitle, movies[id].mDuration, movies[id].mScore, movies[id].genre, movies[id].mDescription, movies[id].imageLink);
                returnList = 0;
            }

    return returnList;
}
/** \brief
 *
 * \param  Un int para el largo
 * \param Mensaje para el usuario
 * \param Una cadena para el nombre del archivo
 * \return 1 si no fue exitosa la carga o 0 si lo fue
 *
 */

int fileGen(sMovies movies[], char fileName[], int length)
{
    int i;

    FILE *htmlFile;

    htmlFile = fopen(fileName, "w");
    if(htmlFile==NULL)
    {
        return 1;
    }
    for(i=0;i<length;i++)
    {

            fprintf(htmlFile, "<article class='col-md-4 article-intro'> <a href='#'> <img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3> <ul> <li>Género:%s</li><li>Puntaje:%d</li> <li>Duración:%d</li> </ul><p>%s</p> </article>", movies[i].imageLink, movies[i].movieTitle, movies[i].genre, movies[i].mScore, movies[i].mDuration, movies[i].mDescription);

    }

    fclose(htmlFile);

    return 0;
}








