#include "Recaudaciones.h"

//INICIALIZAR
int initRecaudaciones(eRecaudacion estructura[], int tamanio)
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

//PUNTO 4 AGREGAR RECAUDACION
int cargaDeDatosRecaudaciones(eRecaudacion estructura[], int tamanio, eContribuyente estructuraContri[], int tamanioContri, int* flagIdRecaudacion)
{
	int retorno=0;
	int posicion;
	int iDContribuyente;
	int mes;
	int tipo;
	float importe;
	int id;
	int flagAux=*flagIdRecaudacion;

	if(estructura!=NULL&&flagIdRecaudacion!=NULL&&tamanio>0)
	{
		utn_getNumero(&iDContribuyente, "Ingrese en ID del contribuyente para la recaudación:\n\n", "Error al ingresar el ID. Intentelo de nuevo:\n\n", 1000, 1050, 5);

		if(buscarContribuyente(estructuraContri, tamanioContri, iDContribuyente))
		{
			if(buscarIsEmptyRecaudacion(estructura, tamanio, &posicion))
			{
				if(utn_getNumero(&mes, "Ingrese el mes de la recaudación: (1) Enero - (12) Diciembre:\n", "Error al ingresar el mes. Intente de nuevo.\n", 1, 12, 5)&&
				   utn_getFloat(&importe, "Ingrese el importe de la recaudación:\n", "Error al ingresar el importe de la recaudación. Intente de nuevo.\n", 100.99, 10000.99, 5)&&
				   utn_getNumero(&tipo, "Ingrese un tipo de recaudación:\n [1]-ARBA\n [2]-IIBB\n [3]-GANANCIAS\n", "Ingrese una opción válida", 1, 3, 5)&&obtenerId(&flagAux, 100, &id))
				{
					if(agregarRecaudacion(estructura, posicion, iDContribuyente, mes, tipo, importe, id))
					{
						printf("Se cargó exitosamente la recaudación para el contribuyente #%d \n\n", iDContribuyente);
						printf(" ID CONTRIBUYENTE        MES       TIPO           IMPORTE       ID RECAUDACION    ESTADO  \n");
						printf("-----------------+------+---+----+------+---------+-------+-----+--------------+----------+------\n");
						imprimirRecaudacion(estructura, posicion);
						*flagIdRecaudacion=flagAux;
					}
				}
				else
				{
					printf("Hubo algún error en el ingreso de alguno de los datos.\n\n");
				}
			}
			else
			{
				printf("Intente dar de baja algún contribuyente para poder cargar.\n\n");
			}
		}
		else
		{
			printf("Ingresó mal el ID o no existe el ID del contribuyente.\n\n");
		}
	}
	return retorno;
}

int buscarIsEmptyRecaudacion(eRecaudacion estructura[], int tamanio, int* posicion)
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

int agregarRecaudacion(eRecaudacion* estructura, int posicion, int iDContribuyente, int mes, int tipo, float importe, int id)
{
	int retorno=0;

	if(estructura!=NULL&&posicion>0)
	{

		estructura[posicion].iDContribuyente=iDContribuyente;
		estructura[posicion].mes=mes;
		estructura[posicion].tipo=tipo;
		estructura[posicion].importe=importe;
		estructura[posicion].iDRecaudacion=id;
		estructura[posicion].estado=1;
		estructura[posicion].isEmpty=0;

		retorno=1;
	}
	return retorno;
}

void imprimirRecaudaciones(eRecaudacion estructura[], int tamanio)
{
	int i;

	printf(" ID CONTRIBUYENTE        MES       TIPO           IMPORTE       ID RECAUDACION    ESTADO  \n");
	printf("-----------------+------+---+----+------+---------+-------+-----+--------------+----------+------\n");
	for(i=0;i<tamanio;i++)
	{
		if(estructura[i].isEmpty==0)
		{
			imprimirRecaudacion(estructura, i);
		}
	}
}

void imprimirRecaudacion(eRecaudacion* estructura, int posicion)
{
	char tipo[20];
	char estado[20];
	int opcionUno;
	int opcionDos;

	opcionUno=estructura[posicion].tipo;
	opcionDos=estructura[posicion].estado;

	obtenerDescripcionPorInt(opcionUno, tipo, "ARBA", "IIBB", "GANANCIAS");
	obtenerDescripcionPorInt(opcionDos, estado, "PENDIENTE", "REFINANCIADO", "SALDADO");

	printf("%10d       %10d        %-10s       %-10.2f       %5d       %-20s\n", estructura[posicion].iDContribuyente, estructura[posicion].mes, tipo, estructura[posicion].importe, estructura[posicion].iDRecaudacion, estado);

}

int buscarRecaudacionesConId(eRecaudacion estructura[], int tamanio, int iD, int* posicion)
{
	int retorno=0;
	int i;

	for(i=0;i<tamanio;i++)
		{
			if(estructura[i].isEmpty==0)
			{
				if(estructura[i].iDRecaudacion==iD)
				{
					*posicion=i;
					retorno=1;
				}
			}
		}
	return retorno;
}

int imprimirRecaudacionesDelContribuyente(eRecaudacion estructura[], int tamanio, int idContri)
{
	int retorno=0;
	int i;
	int flag=0;

	for(i=0;i<tamanio;i++)
	{
		if(estructura[i].isEmpty==0)
		{
			if(estructura[i].iDContribuyente==idContri)
			{
				if(flag==0)
				{
					printf(" ID CONTRIBUYENTE        MES       TIPO           IMPORTE       ID RECAUDACION    ESTADO  \n");
					printf("-----------------+------+---+----+------+---------+-------+-----+--------------+----------+------\n");
				}

				imprimirRecaudacion(estructura, i);
				flag++;
				retorno=1;
			}
		}
	}

	if(flag==0)
	{
		printf("\nEste contribuyente no posee recaudaciones.\n\n");
	}

	return retorno;
}

int darBajaRecaudaciones(eRecaudacion estructura[], int tamanio, int id)
{
	int retorno=0;
	int i;

	for(i=0;i<tamanio;i++)
	{
		if(estructura[i].isEmpty==0)
		{
			if(estructura[i].iDContribuyente==id)
			{
				estructura[i].isEmpty=1;
				retorno=1;
			}
		}
	}
	return retorno;
}


int cambiarEstadoRecaudacion(eRecaudacion estructura[], int tamanio, eContribuyente estrucContribuyente[], int tamContribuyente, int cambioEstado)
{
	int retorno=0;
	int id;
	int posicion;
	int posicionContri;
	char salir;
	int idContribuyente;
	char opcion;
	char estado[TAM];

	if(estructura!=NULL&&estrucContribuyente!=NULL&&tamanio>0&&tamContribuyente>0)
	{
		do
		{
			if(utn_getNumero(&id, "Ingrese el ID de la recaudación que desea cambiar el estado:\n\n", "Error al ingresar el ID. Intente de nuevo:\n\n", 100, 150, 5))
			{
				if(buscarRecaudacionesConId(estructura, tamanio, id, &posicion))
				{
					idContribuyente=estructura[posicion].iDContribuyente;
					buscarContribuyenteConId(estrucContribuyente, tamContribuyente, idContribuyente, &posicionContri);

					printf(" ID             APELLIDO           NOMBRE               CUIL    \n");
					printf("---------+-------------------+------------------+-----------------\n");
					imprimirContribuyente(estrucContribuyente, posicionContri);

					printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

					if(imprimirRecaudacionesDelContribuyente(estructura, tamanio, idContribuyente))
					{
						printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
					}

					printf("¿Quiere cambiar el estado de esta recaudación?: [s]-sí [n]-no\n\n");
					fflush(stdin);
					scanf("%c", &opcion);

					if(opcion=='s'&&cambioEstado==2)
					{
						estructura[posicion].estado=2;
						obtenerDescripcionPorInt(2, estado, "PENDIENTE", "REFINANCIADO", "SALDADO");
						printf("La recaudación #%d se encuentra en estado '%s'.\n\n", id, estado);
					}
					if(opcion=='s'&&cambioEstado==3)
					{
						estructura[posicion].estado=3;
						obtenerDescripcionPorInt(3, estado, "PENDIENTE", "REFINANCIADO", "SALDADO");
						printf("La recaudación #%d se encuentra en estado '%s'.\n\n", id, estado);
					}
				}
				else
				{
					printf("No existe el ID de la recaudación ingresada.\n ¿Desea intentar de nuevo?: [s]-sí [n]-no\n\n");
					fflush(stdin);
					scanf("%c", &salir);
				}
			}
		}while(salir=='n');
	}
	return retorno;
}

void imprimirListaContribuyentes(eRecaudacion estrucRecaudacion[], int tamRecaudacion, eContribuyente estrucContribuyente[], int tamContribuyente)
{
	int i;
	int idContri;
	int flagEncabezado=0;

	if(estrucRecaudacion!=NULL&&estrucContribuyente!=NULL&&tamRecaudacion>0&&tamContribuyente>0)
	{
		for(i=0;i<tamContribuyente;i++)
		{
			if(estrucContribuyente[i].isEmpty==0)
			{
				if(flagEncabezado==0)
				{
					printf("\n                   DATOS Y RECAUDACIONES DE LOS CONTRIBUYENTES                      \n\n");
					flagEncabezado=1;
				}

				printf(" ID             APELLIDO           NOMBRE               CUIL    \n");
				printf("---------+-------------------+------------------+-----------------\n");
				imprimirContribuyente(estrucContribuyente, i);

				idContri=estrucContribuyente[i].iDContribuyente;
				imprimirRecaudacionesDelContribuyente(estrucRecaudacion, tamRecaudacion, idContri);

				printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

			}
		}
	}
}

void imprimirRecaudacionesSaldadas(eRecaudacion estrucRecaudacion[], int tamRecaudacion, eContribuyente estrucContribuyente[], int tamContribuyente)
{
	int i;
	int idContri;
	int posicionContri;
	int flagEncabezado=0;

	if(estrucRecaudacion!=NULL&&estrucContribuyente!=NULL&&tamRecaudacion>0&&tamContribuyente>0)
	{
		for(i=0;i<tamRecaudacion;i++)
		{
			if(estrucRecaudacion[i].isEmpty==0)
			{
				idContri=estrucRecaudacion[i].iDContribuyente;
				buscarContribuyenteConId(estrucContribuyente, tamContribuyente, idContri, &posicionContri);

				if(estrucRecaudacion[i].estado==3)
				{
					if(flagEncabezado==0)
					{
						printf("\n                                          LISTA RECAUDACIONES SALDADAS                                                      \n\n");
						printf(" ID CONTRIBUYENTE        MES       TIPO           IMPORTE       ID RECAUDACION   ESTADO              CUIL           NOMBRE           APELLIDO\n");
						printf("-----------------+------+---+----+------+--------+-------+-----+---------------+---------+-------+------------+----+-------+--------+--------+------\n");
						flagEncabezado=1;
					}

					imprimirRecaudacionSaldada(estrucRecaudacion, i, estrucContribuyente, posicionContri);
				}
			}
		}
	}
}

void imprimirRecaudacionSaldada(eRecaudacion* estrucRecaudacion, int posicionRecau, eContribuyente* estrucContribuyente, int posicionContri)
{
	char tipo[20];
	char estado[20];
	int opcionUno;
	int opcionDos;

	opcionUno=estrucRecaudacion[posicionRecau].tipo;
	opcionDos=estrucRecaudacion[posicionRecau].estado;

	obtenerDescripcionPorInt(opcionUno, tipo, "ARBA", "IIBB", "GANANCIAS");
	obtenerDescripcionPorInt(opcionDos, estado, "PENDIENTE", "REFINANCIADO", "SALDADO");

	printf("%10d       %10d        %-10s       %-10.2f       %-5d       %-10s      %-10s      %-10s        %-10s\n",
	estrucRecaudacion[posicionRecau].iDContribuyente, estrucRecaudacion[posicionRecau].mes, tipo, estrucRecaudacion[posicionRecau].importe, estrucRecaudacion[posicionRecau].iDRecaudacion,
	estado, estrucContribuyente[posicionContri].cuil, estrucContribuyente[posicionContri].nombre, estrucContribuyente[posicionContri].apellido);
}


















