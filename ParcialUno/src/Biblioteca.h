#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#define TAM 30

//Prototipos Validaciones

//int

int getInt(int *pResultado);
int esNumero(char *cadena);
int validarEspacio(char *cadena, int longitud);

//float

int validarFloat(char *pNumero);
int getFloat(float *pResultado);

//string

int validarString(char pString[]);

//cuil

int validarCuil(char bufferStr[]);



//Obtener datos
//int
int utn_getNumero(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
//float
int utn_getFloat(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
//char
int utn_getCaracter(char* pCaracter, char* mensaje, char* mensajeError, char opcionUno, char opcionDos, int reintentos);
//string
int utn_getString(char* mensaje, char* mensajeError, char arrayString[], int reintentos);
//cuil
int getCuil(char cuil[], char* mensaje, char* mensajeError, int reintentos);


//Alta
int obtenerId(int* flagId, int baseId, int* finalId);



//Listar
void obtenerDescripcionPorInt(int opcion, char descripFinal[], char descripUno[], char descripDos[], char descripTres[]);



#endif /* BIBLIOTECA_H_ */
