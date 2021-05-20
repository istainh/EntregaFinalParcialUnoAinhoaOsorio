#include "Biblioteca.h"
//Validaciones

//Numeros enteros

int getInt(int *pResultado)
{
	char buffer[TAM];
	char auxBuffer[TAM];
	int retorno=0;

	if(pResultado!=NULL)
	{
		scanf("%s", auxBuffer);
		strncpy(buffer, auxBuffer, TAM);

		if(esNumero(buffer)==1&&validarEspacio(buffer,sizeof(buffer))==0)
		{
			*pResultado = atoi(buffer);
			retorno=1;
		}
	}
	return retorno;
}

//Validar si el int es un int

int esNumero(char *cadena)
{
	int i=0;
	int retorno=1;

	if (cadena!=NULL&&strlen(cadena)>0)
	{
		while (cadena[i]!='\0')
		{
			if(i==0&&(cadena[i]=='-'||cadena[i]=='+'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i]>'9')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

//Validar si hay un \n y quitarlo

int validarEspacio(char *cadena, int longitud)
{
	if (cadena!=NULL&&longitud>0)
	{
		fflush(stdin);
		if (cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]='\0';
		}
		return 0;
	}
	return -1;
}

//validar float

int validarFloat(char *pNumero)
{
	int contaSigno=0;
	int retorno=1;
	int i;

	if(strlen(pNumero)>0)
	{
		for(i=0;i<strlen(pNumero);i++)
		{
			if(pNumero[i]=='.'||pNumero[i]==',')
			{
				contaSigno++;
			}
			else
			{
				if(isdigit(pNumero[i])==0)
				{
					if(i==0)
					{
						if(pNumero[0]!='-')
						{
							retorno=0;
							break;
						}
					}
					else
					{
						retorno=0;
						break;
					}
				}
			}
		}
		if(contaSigno>1)
		{
			retorno=0;
		}
	}
	else
	{
		retorno = 0;
	}
	return retorno;
}

int getFloat(float *pResultado)
{
	char buffer[TAM];
	char auxBuffer[TAM];
	int retorno=0;

	if(pResultado!=NULL)
	{
		scanf("%s", auxBuffer);
		strncpy(buffer, auxBuffer, TAM);

		if(validarFloat(buffer)==1&&validarEspacio(buffer,sizeof(buffer))==0)
		{
			*pResultado=atof(buffer);
			retorno=1;
		}
	}
	return retorno;
}

//Validar caracteres

int validarString(char pString[])
{
	int retorno=1;
	int i=0;

	if (strlen(pString)>0)
	{
		for (i=0;i<strlen(pString);i++)
		{
			if (isalpha(pString[i])==0)
			{
				retorno=0;
				break;
			}
		}
	}
	else
	{
		retorno=0;
	}

	return retorno;
}


//Obtener datos
//int
int utn_getNumero(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=0;
	int numero;

	if (pNumero!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			if(getInt(&numero)==1)
			{
				if (numero>=minimo && numero<=maximo)
				{
					*pNumero=numero;
					retorno=1;
					break;
				}
				else
				{
					printf("%s", mensajeError);
					reintentos--;
				}
			}
		}while(reintentos>=0);
	}
	return retorno;
}

//float

int utn_getFloat(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno=0;
	float numero;

	if (pNumero!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			if(getFloat(&numero)==1)
			{
				if (numero>=minimo && numero<=maximo)
				{
					*pNumero=numero;
					retorno=1;
					break;
				}
				else
				{
					printf("%s", mensajeError);
					reintentos--;
				}
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getCaracter(char* pCaracter, char* mensaje, char* mensajeError, char opcionUno, char opcionDos, int reintentos)
{
	int retorno=1;
	char caracter;

	if(pCaracter!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &caracter);

			if(caracter==opcionUno||caracter==opcionDos)
			{
				*pCaracter=caracter;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos>=0);
	}
	return retorno;
}//Se tiene que editar los parametros de esta funcion dependiendo de la cantidad de opciones de caracteres que necesito.
//RECUERDA TAMBIEN CAMBIARLO EN EL PROTOTIPO .H

int utn_getString(char* mensaje, char* mensajeError, char arrayString[], int reintentos)
{
	int retorno=0;

	if(mensaje!=NULL&&arrayString!=NULL&&mensajeError!=NULL)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			gets(arrayString);

			if(validarString(arrayString)==1)
			{
				retorno=1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

//Alta

int obtenerId(int* flagId, int baseId, int* finalId)
{
	int retorno=0;

	if(flagId!=NULL&&finalId!=NULL)
	{
		if(flagId==0)
		{
			(*flagId)++;
			*finalId=900+(*flagId);
		}
		else
		{
			(*flagId)++;
			*finalId=baseId+(*flagId);
			retorno=1;
		}
	}
	else
	{
		printf("Error en la carga de ID.\n");
	}

	return retorno;
}

//Listar

void obtenerDescripcionPorInt(int opcion, char descripFinal[], char descripUno[], char descripDos[], char descripTres[])
{

	if(descripFinal!=NULL&&descripUno!=NULL&&descripDos!=NULL&&descripTres!=NULL)
	{
		switch (opcion)
		{
			case 1:
				strcpy(descripFinal, descripUno);
				break;

			case 2:
				strcpy(descripFinal, descripDos);
				break;

			case 3:
				strcpy(descripFinal, descripTres);
				break;
		}
	}
	else
	{
		printf("Error al mostrar descripción. Un dato es nulo. \n");
	}
}

int getCuil(char cuil[], char* mensaje, char* mensajeError, int reintentos)
{
	int retorno=0;
	char bufferCuil[14];

	if(mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0&&cuil!=NULL)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			gets(bufferCuil);

			if(validarCuil(bufferCuil))
			{
				strcpy(cuil, bufferCuil);
				retorno=1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int validarCuil(char bufferStr[])
{
	int retorno=1;
	int i;

	if(strlen(bufferStr)==11||strlen(bufferStr)==13)
	{
		 for(i=0;bufferStr[i]!='\0';i++)
		{
			if((bufferStr[i]<'0'||bufferStr[i]>'9')&&(bufferStr[i]!='-'))
			{
				retorno=0;
			}
		}
	}
	else
	{
		retorno=0;
	}

	return retorno;
}


