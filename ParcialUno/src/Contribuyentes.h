
#ifndef CONTRIBUYENTES_H_
#define CONTRIBUYENTES_H_

#define STR_LEN 20

typedef struct
{
	int iDContribuyente;
	char nombre[STR_LEN];
	char apellido[STR_LEN];
	char cuil[STR_LEN];
	int isEmpty;
}eContribuyente;

#include "Biblioteca.h"
#include "Recaudaciones.h"

/**
 * \brief Iniciar de manera lógica el array de estructura de tipo eContribuyente asignando un 1.
 * \param estructura Es la estructura declarada en el main a inicializar.
 * \param tamanio El tamaño de la estructura.
 * \return Un -1 si ocurrió un error y 0 si cumplió su función.
 */
int initContribuyentes(eContribuyente estructura[], int tamanio);

/**
 * \brief Carga los datos a cada campo en una posición del array de estructura de tipo eContribuyente.
 * \param estructura Es la estructura de tipo e Contribuyente declarada en el main a inicializar.
 * \param tamanio El tamaño de la estructura.
 * \param flagId Puntero donde se va contando la cantidad de ID que se van generando con la funcion obtenerId.
 * \return Un 0 si ocurrió un error y un 1 si cumplió con su función.
 */
int cargaDeDatosContribuyente(eContribuyente estructura[], int tamanio, int* flagId);

/**
 * \brief Asigna todos los valores obtenidos en la funcion cargaDeDatosContribuyente a cada campo de la estructura.
 * \param estructura Es de tipo eContribuyente.
 * \param posicion Espacio libre donde se podrá asignar los valores a los campos.
 * \param nombre varible de tipo cadena de caracteres con el nombre del contribuyente.
 * \param apellido varible de tipo cadena de caracteres con el apellido del contribuyente.
 * \param cuil varible de tipo cadena de caracteres con el CUIL del contribuyente.
 * \param iD variable de tipo entero con el valor obtenido en la funcion obtenerId.
 * \return Un 0 si ocurrió un error y un 1 si cumplió con su función.
 */
int agregarContribuyente(eContribuyente* estructura, int posicion, char nombre[], char apellido[], char cuil[], int iD);

/**
 * \brief Da de baja de manera lógica a un espacio de la estructura eContribuyente  de 0 a el campo isEmpty.
 * \param estructura Estructura a la que se va a dar de baja.
 * \param tamanio El tamañio de la estructura para recorrerla.
 * \param estructuraRecau Estructura de tipo eRecaudacion
 * \param tamanioRecau
 * \return
 */
int darDeBaja(eContribuyente estructura[], int tamanio, eRecaudacion estructuraRecau[], int tamanioRecau);

//Imprimir
void imprimirContribuyentes(eContribuyente estructura[], int tamanio);

void imprimirContribuyente(eContribuyente* estructura, int posicion);


//Busqueda
int buscarContribuyenteConId(eContribuyente estructura[], int tamanio, int iD, int* posicion);
int buscarContribuyente(eContribuyente estructura[], int tamanio, int iD);
void revizarIsEmpty(eContribuyente estructura[], int tamanio, int* flag);
int buscarIsEmpty(eContribuyente estructura[], int tamanio, int* posicion);

//Modificar
void menuModificadorContribuyente(eContribuyente estructura[], int tamanio);











#endif /* CONTRIBUYENTES_H_ */
