#include "Informes.h"
#include "Biblioteca.h"
#include "Recaudaciones.h"
#include "Contribuyentes.h"

#define CANTIDAD 50

int main(void) {
	setbuf(stdout, NULL);

	eContribuyente contribuyente[CANTIDAD];
	eRecaudacion recaudacion[CANTIDAD];

	initContribuyentes(contribuyente, CANTIDAD);
	initRecaudaciones(recaudacion, CANTIDAD);

	int opcion;
	char salir;
	int menu;
	int flagCarga=0;
	int flagId=0;
	int flagIdRecaudacion=0;

	do
	{
		menu=utn_getNumero(&opcion,"MEN� DE OPCIONES:\n\n [1] Alta Contribuyentes\n [2] Modificar contribuyente\n [3] Baja Contribuyentes\n [4] Agregar recaudaci�n a contribuyente.\n [5] Refinanciar recaudaci�n.\n [6] Saldar recaudaci�n.\n [7] Listar todos los contribuyentes.\n [8] Listar recaudaciones saldadas.\n [9] Salir del programa.\n", "No ingres� una opci�n v�lida. Vuelve a intentarlo.\n", 1, 9, 10);

		if(menu)
		{
			switch (opcion)
			{
				case 1:
					if(cargaDeDatosContribuyente(contribuyente, CANTIDAD, &flagId))
					{
						flagCarga=1;
					}
				break;

				case 2:
					 if(flagCarga==0)
					 {
						 printf("Todav�a no se han a�adido contribuyentes. Ingrese a la opci�n 1 del men� para cargar un nuevo contribuyente.\n\n");
					 }
					 else
					 {
						 menuModificadorContribuyente(contribuyente, CANTIDAD);
					 }
					 break;

				case 3:
					 if(flagCarga==0)
					 {
						 printf("Todav�a no se han a�adido contribuyentes. Ingrese a la opci�n 1 del men� para cargar un nuevo contribuyente.\n\n");
					 }
					 else
					 {
						 if(darDeBaja(contribuyente, CANTIDAD, recaudacion, CANTIDAD))
						 {
							 revizarIsEmpty(contribuyente, CANTIDAD, &flagCarga);
						 }
					 }
					 break;

				case 4:
					if(flagCarga==0)
					{
						 printf("Todav�a no se han a�adido contribuyentes. Ingrese a la opci�n 1 del men� para cargar un nuevo contribuyente.\n\n");
					}
					else
					{
						cargaDeDatosRecaudaciones(recaudacion, CANTIDAD, contribuyente, CANTIDAD, &flagIdRecaudacion);
					}

					 break;

				case 5:
					if(flagCarga==0)
					{
						 printf("Todav�a no se han a�adido contribuyentes. Ingrese a la opci�n 1 del men� para cargar un nuevo contribuyente.\n\n");
					}
					else
					{
						cambiarEstadoRecaudacion(recaudacion, CANTIDAD, contribuyente, CANTIDAD, 2);
					}
					break;

				case 6:
					if(flagCarga==0)
					{
						 printf("Todav�a no se han a�adido contribuyentes. Ingrese a la opci�n 1 del men� para cargar un nuevo contribuyente.\n\n");
					}
					else
					{
						cambiarEstadoRecaudacion(recaudacion, CANTIDAD, contribuyente, CANTIDAD, 3);
					}
					break;

				case 7:
					if(flagCarga==0)
					{
						 printf("Todav�a no se han a�adido contribuyentes. Ingrese a la opci�n 1 del men� para cargar un nuevo contribuyente.\n\n");
					}
					else
					{
						imprimirListaContribuyentes(recaudacion, CANTIDAD, contribuyente, CANTIDAD);
					}
					break;

				case 8:
					if(flagCarga==0)
					{
						 printf("Todav�a no se han a�adido contribuyentes. Ingrese a la opci�n 1 del men� para cargar un nuevo contribuyente.\n\n");
					}
					else
					{
						imprimirRecaudacionesSaldadas(recaudacion, CANTIDAD, contribuyente, CANTIDAD);
					}
					break;

				case 9:
					printf("�Desea salir? s-si o n-no:\n");
					fflush(stdin);
					scanf("%c", &salir);
					if (salir=='s')
					{
						printf("Termin� el programa.\n");
					}
				break;
			}
		}
		else
		{
			printf("Error al seleccionar en el menu. Intente m�s tarde.\n");
			salir='s';
		}

	}while(salir=='n'||opcion!=9);

	return EXIT_SUCCESS;
}




