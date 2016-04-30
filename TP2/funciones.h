#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char employeeName[50];
    int employeeDNI;
    int employeeAge;
    int isEmpty;

}sEmployee;

/** \brief Inicializa la variable isEmpty de la estructura sEmployee en 1
 *
 * \param myEmployee array de sEmpleado
 * \param int largo del array
 * \return void
 *
 */
void isEmptyInit(sEmployee[], int);

/** \brief Agrega un sEmployee al array de sEmployee
 *
 * \param myEmployee array de sEmpleado
 * \param int largo del array
 * \return void
 *
 */

void addEmployee(sEmployee[], int);

/** \brief Modifica una o mas variables de una posicion del array de sEmployee
 *
 * \param myEmployee array de sEmpleado
 * \param int largo del array
 * \return void
 *
 */

void modifyEmployee(sEmployee[], int, int);

/** \brief Muestra el contenido del array de sEmployee
 *
 * \param myEmployee array de sEmpleado
 * \param int largo del array
 * \return void
 *
 */

void showEmployees(sEmployee[], int);

/** \brief Desindexa mediante la variable is empty una posicion del array de sEmployee
 *
 * \param myEmployee array de sEmpleado
 * \param int largo del array
 * \return void
 *
 */

void eraseEmployee(sEmployee[], int);

/** \brief
 *
 * \param myEmployee array de sEmpleado
 * \param int largo del array
 * \return void
 *
 */

int intValidation(int, int);

/** \brief Ordena alfabeticamente usando como criterio la variable nombre el array de sEmployee
 *
 * \param myEmployee array de sEmpleado
 * \param int largo del array
 * \return void
 *
 */

int orderByName(sEmployee[], int);

void graphicAges(sEmployee[], int);

int validateDni(sEmployee[], int, int);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int espacioLibre(sEmployee myEmployee[], int length);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(sEmployee lista[], int length);


#endif // FUNCIONES_H_INCLUDED
