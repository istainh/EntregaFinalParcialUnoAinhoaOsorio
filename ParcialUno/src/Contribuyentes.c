#include "Contribuyentes.h"

//FUNCIONES EN EL MAIN
//Inicializar
int initContribuyentes(eContribuyente estructura[], int tamanio)
{
	int retorno=-1;
	int i;

	if(estructura!=NULL)
	{
		for(i=0;i<tamanio;i++)
		{
			estructura[i].isEmpty=1;
			retorno=0;
		}
	}
	return retorno;
}

//PUNTO 1 ALTA CONTRIBUYENTE
int cargaDeDatosContribuyente(eContribuyente estructura[], int tamanio, int* flagId)
{
	int retorno=0;
	int posicion;
	char nombre[STR_LEN];
	char apellido[STR_LEN];
	char cuil[STR_LEN];
	int id;
	int flagAux=*flagId;

	if(estructura!=NULL&&flagId!=NULL&&tamanio>0)
	{
		if(buscarIsEmpty(estructura, tamanio, &posicion))
		{
			if(utn_getString("Ingrese el nombre del contribuyente:\n\n", "Error al ingresar el nombre del contribuyente. Intentelo de nuevo:\n\n", nombre, 2)&&
			   utn_getString("Ingrese el apellido del contribuyente:\n\n", "Error al ingresar el apellido del contribuyente. Intentelo de nuevo:\n\n", apellido, 2)&&
			   getCuil(cuil, "Ingrese el CUIL del contribuyente:\n\n", "Error al ingresar el CUIL. Intente de nuevo:\n\n", 5)&&obtenerId(&flagAux, 1000, &id))
			{
				if(agregarContribuyente(estructura, posicion, nombre, apellido, cuil, id))
				{
					printf("Se cargó exitosamente el contribuyente #%d\n\n", id);
					imprimirContribuyente(estructura, posicion);
					*flagId=flagAux;
					retorno=1;
				}
			}
			else
			{
				printf("Hubo algún error en el ingreso de alguno de los datos.\n");
			}
		}
		else
		{
			printf("Intente dar de baja algún contribuyente para poder cargar.\n");
		}
	}
	return retorno;
}
int buscarIsEmpty(eContribuyente estructura[], int tamanio, int* posicion)
{
	int i;
	int retorno=0;

	if(estructura!=NULL&&tamanio>0)
	{
		for(i=0;i<tamanio;i++)
		{
			if(estructura[i].isEmpty==1)
			{
				*posicion=i;
				retorno=1;
			}
		}
	}
	return retorno;
}
int agregarContribuyente(eContribuyente* estructura, int posicion, char nombre[], char apellido[], char cuil[], int iD)
{
	int retorno=0;

	if(estructura!=NULL&&nombre!=NULL&&apellido!=NULL&&cuil!=NULL&&posicion>0)
	{
		strcpy(estructura[posicion].nombre, nombre);
		strcpy(estructura[posicion].apellido, apellido);
		strcpy(estructura[posicion].cuil, cuil);
		estructura[posicion].iDContribuyente=iD;
		estructura[posicion].isEmpty=0;

		retorno=1;
	}
	return retorno;
}

//PUNTO 2 MODIFICAR DATOS CONTRIBUYENTE
void menuModificadorContribuyente(eContribuyente estructura[], int tamanio)
{
	int opcion;
	char salir;
	int menu;
	char modificar;
	int posicion;
	char nombre[TAM];
	char apellido[TAM];
	char cuil[TAM];
	int id;

	if(estructura!=NULL&&tamanio>0)
	{
		do
		{
			utn_getNumero(&id, "Ingrese en ID del contribuyente que desee modificar:\n\n", "Error al ingresar el ID. Intentelo de nuevo:\n", 1000, 1050, 5);

			if(buscarContribuyenteConId(estructura, tamanio, id, &posicion))
			{
				printf(" ID             APELLIDO           NOMBRE               CUIL    \n");
				printf("---------+-------------------+------------------+-----------------\n");
				imprimirContribuyente(estructura, posicion);

				printf("¿Desea modificar este ID? [s]-si [n]-no\n\n");
				fflush(stdin);
				scanf("%c", &modificar);

				if(modificar=='s')
				{
					menu=utn_getNumero(&opcion,"MODIFICAR DATOS CONTRIBUYENTE:\n\n Seleccione una opción:\n [1]-Nombre del contribuyente.\n [2]-Apellido del contribuyente.\n [3]-CUIL del contribuyente.\n [4]-Salir.\n", "No ingresó una opción válida, vuelva a intentarlo.\n\n", 1, 4, 5);
					if(menu)
					{
						switch (opcion)
						{
							case 1:
								if(utn_getString("Ingrese el nombre del contribuyente:\n","Error al ingresar el nombre del contribuyente. Intentelo de nuevo: \n", nombre, 2))
								{
									strcpy(estructura[posicion].nombre, nombre);
									printf("Se realizó el cambio del nombre del contribuyente #%d \n\n", id);
								}
								else
								{
									printf("Error al escribir el cambio de nombre del contribuyente. \n\n");
								}
								break;

							case 2:
								if(utn_getString("Ingrese el apellido del contribuyente:\n","Error al ingresar el apellido del contribuyente. Intentelo de nuevo: \n", apellido, 2))
								{
									strcpy(estructura[posicion].apellido, apellido);
									printf("Se realizó el cambio del apellido del contribuyente #%d \n\n", id);
								}
								else
								{
									printf("Error al escribir el cambio de apellido del contribuyente. \n\n");
								}
								break;

							case 3:
								if(getCuil(cuil, "Ingrese el CUIL del contribuyente:\n", "Error al ingresar el CUIL. Intente de nuevo:\n", 5))
								{
									strcpy(estructura[posicion].cuil, cuil);
									printf("Se realizó el cambio del CUIL del contribuyente #%d \n\n", id);
								}
								else
								{
									printf("Error al escribir el cambio de CUIL del contribuyente. \n\n");
								}
								break;

							case 4:
								printf("¿Desea salir? [s]-si [n]-no\n\n");
								fflush(stdin);
								scanf("%c", &salir);
								if (salir=='s')
								{
									printf("Salió del modificador de datos del contribuyente.\n");
								}
								break;
							}

							printf("¿Desea salir? [s]-si [n]-no\n\n");
							fflush(stdin);
							scanf("%c", &salir);
							if (salir=='s')
							{
								printf("Salió del modificador de datos del contribuyente.\n");
								break;
							}
						}
						else
						{
							printf("Error al seleccionar en el menu. Intente más tarde.\n");
							salir='s';
						}
					}
				}
			else
			{
				printf("No exite el ID ingresado.\n\n");
			}
		}while(salir=='n'||opcion!=4);
	}
}

//PUNTO 3 BAJA CONTRIBUYENTE
int darDeBaja(eContribuyente estructura[], int tamanio, eRecaudacion estructuraRecau[], int tamanioRecau)
{
	int retorno=0;
	int id;
	int posicion;
	char darBaja;

	utn_getNumero(&id, "Ingrese en ID del contribuyente que desee dar de baja:\n\n", "Error al ingresar el ID. Intentelo de nuevo:\n\n", 1000, 1050, 5);

	if(buscarContribuyenteConId(estructura, tamanio, id, &posicion))
	{
		printf(" ID             APELLIDO           NOMBRE               CUIL    \n");
		printf("---------+-------------------+------------------+-----------------\n");
		imprimirContribuyente(estructura, posicion);

		printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");


		if(imprimirRecaudacionesDelContribuyente(estructuraRecau, tamanioRecau, id))
		{
			printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
		}

		printf("¿Desea dar de baja este contribuyente? [s]-si [n]-no\n\n");
		fflush(stdin);
		scanf("%c", &darBaja);

		if(darBaja=='s')
		{
			darBajaRecaudaciones(estructuraRecau, tamanioRecau, id);
			estructura[posicion].isEmpty=1;
			printf("Se dio de baja al contribuyente #%d.\n\n", id);
			retorno=1;
		}
		else
		{
			printf("No dio de baja al ID #%d.\n\n", id);
		}

	}
	return retorno;
}

int buscarContribuyenteConId(eContribuyente estructura[], int tamanio, int iD, int* posicion)
{
	int retorno=0;
	int i;

	for(i=0;i<tamanio;i++)
		{
			if(estructura[i].isEmpty==0)
			{
				if(estructura[i].iDContribuyente==iD)
				{
					*posicion=i;
					retorno=1;
				}
			}
		}
	return retorno;
}
int buscarContribuyente(eContribuyente estructura[], int tamanio, int iD)
{
	int retorno=0;
	int i;

	for(i=0;i<tamanio;i++)
		{
			if(estructura[i].isEmpty==0)
			{
				if(estructura[i].iDContribuyente==iD)
				{
					retorno=1;
				}
			}
		}
	return retorno;
}
void revizarIsEmpty(eContribuyente estructura[], int tamanio, int* flag)
{
	int i;
	int contaIsEmpty=0;

	for(i=0;i<tamanio;i++)
	{
		if(estructura[i].isEmpty==1)
		{
			contaIsEmpty++;
		}
	}

	if(contaIsEmpty==tamanio)
	{
		*flag=0;
	}
}








//Imprimir en pantalla

void imprimirContribuyentes(eContribuyente estructura[], int tamanio)
{
	int i;

	printf(" ID             APELLIDO           NOMBRE               CUIL    \n");
	printf("---------+-------------------+------------------+-----------------\n");
	for(i=0;i<tamanio;i++)
	{
		if(estructura[i].isEmpty==0)
		{
			imprimirContribuyente(estructura, i);
		}
	}
}
void imprimirContribuyente(eContribuyente* estructura, int posicion)
{
	printf("%-10d       %-10s        %-10s       %-10s\n\n", estructura[posicion].iDContribuyente, estructura[posicion].apellido, estructura[posicion].nombre, estructura[posicion].cuil);
}



