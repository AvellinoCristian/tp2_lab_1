#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;


/**
 * inicializa los estados en -1 como valor logico
 * @param lista el array se pasa como parametro.
 * @param indices del array
 */

 void inicializarEstado(ePersona lista[],int tam);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param indices del array
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[],int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param indices del array
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni,int tam);

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief recibe una cadena, y valida que solo tenga letras
* \param char cadena[] cadena para analizar
* \return Si solo son letras [0] si no [-1]
*/
int esSoloLetras(char cadena[]);

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief recibe una cadena, y valida que solo tenga numeros
* \param char cadena[] cadena para analizar
* \return Si solo son numeros [0] si no [-1]
*/
int esSoloNumeros(char cadena[]);

/**
* \brief recibe el array a personas,su tamanio, y 3 punteros a enteros contadores de edades.
* \param ePersona estructura de personas
* \param int tamanio de array de personas
* \param int* puntero a edades menores a 18
* \param int* puntero a edades entre 19 y 35 inclusive
* \param int* puntero a edados mayores de 35
* \return  [0] si el alta fue correcta [-1] si no ( los punteros no escriben el main )
*/
int altaPersona(ePersona[],int,int*,int*,int*);
/**
* \brief recibe los usuarios, los ordena y los muestra por pantalla
* \param ePersona array de personas
* \param int tamanio de array
*/
void ordenarUsuarios (ePersona[],int);
/**
* \brief baja logica de usuario por dni
* \param ePersona estructura de personas
* \param int tamanio de array de personas
* \return  si [0] si no [-1]
*/
int bajaPersona(ePersona[],int);
/**
* \brief obtiene los 3 contadores de edades de la alta y los grafica
* \param int menores a 18
* \param int entre 19 y 35
* \param int mayores a 35
*/
void graficoDeEdades (int,int,int);


#endif // FUNCIONES_H_INCLUDED
