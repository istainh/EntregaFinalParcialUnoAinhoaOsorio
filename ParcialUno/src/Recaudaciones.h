#ifndef RECAUDACIONES_H_
#define RECAUDACIONES_H_

typedef struct
{
	int iDRecaudacion;
	int mes;
	int tipo;
	int estado;
	float importe;
	int iDContribuyente;
	int isEmpty;
}eRecaudacion;

#include "Biblioteca.h"
#include "Contribuyentes.h"

//INICIALIZAR ESTRUCTURA
int initRecaudaciones(eRecaudacion estructura[], int tamanio);

//PUNTO 4 AGREGAR RECAUDACION
int cargaDeDatosRecaudaciones(eRecaudacion estructura[], int tamanio, eContribuyente estructuraContri[], int tamanioContri, int* flagIdRecaudacion);

int buscarIsEmptyRecaudacion(eRecaudacion estructura[], int tamanio, int* posicion);

int agregarRecaudacion(eRecaudacion* estructura, int posicion, int iDContribuyente, int mes, int tipo, float importe, int id);

//IMPRIMIR
void imprimirRecaudaciones(eRecaudacion estructura[], int tamanio);

void imprimirRecaudacion(eRecaudacion* estructura, int posicion);

int buscarRecaudacionesConId(eRecaudacion estructura[], int tamanio, int iD, int* posicion);
int imprimirRecaudacionesDelContribuyente(eRecaudacion estructura[], int tamanio, int idContri);

int darBajaRecaudaciones(eRecaudacion estructura[], int tamanio, int id);

int cambiarEstadoRecaudacion(eRecaudacion estructura[], int tamanio, eContribuyente estrucContribuyente[], int tamContribuyente, int cambioEstado);

void imprimirListaContribuyentes(eRecaudacion estrucRecaudacion[], int tamRecaudacion, eContribuyente estrucContribuyente[], int tamContribuyente);

void imprimirRecaudacionesSaldadas(eRecaudacion estrucRecaudacion[], int tamRecaudacion, eContribuyente estrucContribuyente[], int tamContribuyente);

void imprimirRecaudacionSaldada(eRecaudacion* estrucRecaudacion, int posicionRecau, eContribuyente* estrucContribuyente, int posicionContri);



#endif /* RECAUDACIONES_H_ */
