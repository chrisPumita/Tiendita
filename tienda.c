#include <stdio.h>
#include <stdlib.h> 
#include "ticket.h"
//#include "productos.h"
#define TAM_BAR 20
#define clear() printf("\033[H\033[J") 
// Para limpiar pantalla


int menu()
{
	Bool BanderaG1 = FALSE, BanderaG2; //Loops de menus
	Bool BanderaO1, BanderaO2; //Loops de opciones
	int opcion;
	clear();
	while(!BanderaG1)
	{
		char codigoBarra[TAM_BAR];
		opcion = 0;
		BanderaO1 = FALSE;
		while(!BanderaO1)
		{ //Se asegura de que la opción elegida este dentro del rango
			printf("\E[37;41;5;1;33m\t████████\n");
			printf("\E[37;41;5m\t  OTZO  \n");
			printf("\E[37;41;5;1;33m\t████████\E[00m\n");
			printf("   ->PUNTO DE VENTA\n");
			printf("\E[1;8m+------------+-------------+------------|---------+\n"); //Primer Menú
			printf("\E[1;8m|NUEVA VENTA:| ADMINISTRAR |  CONSULTA  |  SALIR  |\n");
			printf("\E[1;8m|     [1]    |     [2]     |     [3]    |   [0]   |\n");
			printf("\E[1;8m+------------+-------------+------------+---------|\n");
			printf("\E[0;34mElija una opcion: \E[00m");
			scanf ("%d", &opcion);
			if(opcion == 0 || opcion == 1||opcion == 2||opcion == 3)
			{
				BanderaO1 = TRUE; //Opcion dentro de rango
			}
			else
			{
				clear();
				printf("\nOpcion no valida, intente de nuevo\n\n"); //Opcion fuera de rango
			}
		}
		printf("\n");
		
		switch(opcion)
		{ //Opciones Primer Menú
			
			case 1:		//Nueva venta
				nuevaVenta();
				BanderaG2 = FALSE;
			
				break;
				
			case 2:
				//Entrar al menu de administracion
				BanderaG2 = FALSE;
				while(!BanderaG2)
				{
					BanderaO2 = FALSE;
					while(!BanderaO2)
					{ //Se asegura de que la opción elegida este dentro del rango
						//clear();
						printf("+---------------+----------+-----------+-------------------+\n"); //Segundo Menú
						printf("| Ver Almacen   | Agregar  | Modificar |  REGRESAR AL MENU |\n");
						printf("|      [1]      |    [2]   |    [3]    |         [4]       |\n");
						printf("+---------------+----------+-------+-----------------------+\n");
						printf("Elija una opcion: ");
						scanf("%d",&opcion);
						if(opcion >= 1 && opcion <=4)
						{
							BanderaO2 = TRUE; //Opcion dentro de rango
						}
						else
						{
							clear();
							printf("\nOpcion no valida, intente de nuevo\n\n"); //Opcion fuera de rango
						}

						switch(opcion)
						{
							case 1:
								clear();
								DesplegarStock();
								break;
							case 2:
									printf("Se asgnara ID: %d\n",buscaUltimo());
									agregaProducto(buscaUltimo());
									//Agrega nuevo producto
								break;
							case 3:
								//Pide el ID del producto a modificar
								DesplegarStock();
								modificarRegistro();
								break;
							case 4:
								clear();
								BanderaG2 = TRUE; //Termina el loop del segundo menú
								break;
							default:
								return 1;
								break;
						}
					}
				}
				break;
			case 3:
				//Consulta de costo por codigo de barra
				clear();
				printf("Ingrese Código de Barra: ->");
				scanf("%s",&codigoBarra);
				printf("Buscando el archivo...\n");
				sleep(1);
				int found = buscaProductoBarCode(codigoBarra);
				if (found!=0)
				{
					buscaProductoIndex(found);
				}
				else
				{
					printf("NO ENCONTRO EL ARHIVO\n");
				}
				BanderaG2 = TRUE; //Termina el loop del segundo menú
				break;
			case 4: 	//Salir
				printf("\nGracias por su visita, vuelva pronto\n\n");
				BanderaG1 = TRUE; //Termina el loop general
				return 0;
				break;
			default:
				return 1;
				break;
		}
	}
}

 
#if 1
int main()
{
	int aux;
	aux = menu();
	return aux;
}
#endif