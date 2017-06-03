#include <stdio.h>
#include <time.h>
#include "ticket.h"
#define FILE_NAME "lista-de-precios.dat"

#define TAM_BARRA 20
#define clear() printf("\033[H\033[J") 
// Para limpiar pantalla

void muestraVenta(LinkedList* this)
{
	Node * it = LinkedList_Search(this,1);

		double totPago = 0.0;
		int noProductos = 0;
	//Comienza a generar el ticket de venta
		printf("\E[37;41;1;33m\t████████\n");
		printf("\E[37;41m\t  OCXO  \n");
		printf("\E[37;41;1;33m\t████████\E[00m\n");
		printf("\tVENTA DE MOSTRADOR\n");
		
		printf("| CODIGO   | CANT |    NOMBRE    |   $U   |  $TOTAL |\n");
		printf("+--------------------------+\n");
		while(it != NULL)
		{
			printf("%s",it->barra);
			printf(" %d  ",it->cantidad );
			printf("%s\t",it->nombre);
			printf("$%.2f\t",it->cUni);
			printf("$%.2f\n",it->cTotal);
			totPago += it->cTotal;
			noProductos += it->cantidad;
			it = it -> siguiente;
		}
		printf("+--------------------------+\n");
		printf("   Productos agregados: %d\n",noProductos);
		printf("\t\tTotal: $%.2f\n",totPago);	

}

void GeneraTicket(LinkedList* this)
{
	clear();
	//FECHA HORA
	time_t rawtime;
	time (&rawtime);
	Node * it = LinkedList_Search(this,1);
	//Devuelve la direccion del primer nodo
	double totPago = 0.0;
	int noProductos = 0;
//Comienza a generar el ticket de venta
	printf("\E[37;41;1;33m\t████████\n");
	printf("\E[37;41m\t  OCXO  \n");
	printf("\E[37;41;1;33m\t████████\E[00m\n");
	printf("TICKET DE VENTA\n");
	printf("%s\n",ctime (&rawtime));
	printf("Cant  Nombre\t$U\t$T\n");
	printf("+--------------------------+\n");
	while(it != NULL)
	{
		printf("  %d  ",it->cantidad );
		printf("%s\t",it->nombre);
		printf("$%.2f\t",it->cUni);
		printf("$%.2f\n",it->cTotal);
		totPago += it->cTotal;
		noProductos += it->cantidad;
		it = it -> siguiente;
	}
	printf("+--------------------------+\n");
	printf("   Productos adquiridos: %d\n",noProductos);
	printf("\t\tTotal: $%.2f\n",totPago);
}

void agregaProductoTicket(LinkedList* ticket){
	char codeBar[TAM_BARRA];
	printf("Escriba codigo de barra:\n--> ");
	scanf("%s",codeBar);

	printf("Buscando el archivo...\n");
	sleep(1);
	
	int n = buscaProductoBarCode(codeBar);
	//busca en los productos

	//Recupera datos
	FILE* arch=fopen(FILE_NAME,"r+b");

	//Posiciono el puntero del archivo
	fseek(arch,n*sizeof(Producto),SEEK_SET);

	//con el puntero posicionado, leo el registro
	Producto reg;
	fread(&reg,sizeof(Producto),1,arch);

	//recupera la informacion
	int cant = 1; //Esta cambiará
	
	LinkedList_Insert(ticket,n,reg.barCode,reg.nombre,cant, reg.cUni,cant*reg.cUni);

	fclose(arch);
}

int nuevaVenta()
{
	int v = 1;
	char codeBar[TAM_BARRA];
	LinkedList* ticket = LinkedList_Create ();
		clear();
	do
	{
		printf("NUEVA VENTA:\n");
		printf("+------------------+-----------------+----------------+\n"); //Segundo Menú
		printf("|  Quitar Producto | Proceder a Pago | Cancelar Venta |\n");
		printf("|        [1]       |      [2]        |      [3]       |\n");
		printf("+---------------+------------------+------------------+\n");
		printf("Esciba codigo de barra:\n-->");
		scanf("%s",codeBar);
		int tamCodigo = strlen(codeBar);

		//Seleccion de la opcion en el menu
		if (tamCodigo == 1)
		{
			/* Eligio opc que es de un caracter*/
			char i = codeBar[0];
			int opc = i - 0x30;
			printf("TAM %d\n",tamCodigo);
			switch (opc)
			{	
				case 1:
					printf("QUITAR PRODUCTO\n");
				break;
				case 2:
					printf("Proceder a pago\n");
					return 1;
				break;
				case 3:
					printf("Cancelar\n");
					return 0;
				break;
			}
		}
		else
		{
			/* Ingreso un codigo grande que hay que buscar y agregar*/
			int IDProducto = buscaProductoBarCode(codeBar);
			if(IDProducto!=0)
			{
				
				FILE* arch=fopen(FILE_NAME,"r+b");
				//Posiciono el puntero del archivo
				fseek(arch,IDProducto*sizeof(Producto),SEEK_SET);

				//con el puntero posicionado, leo el registro
				Producto reg;
				fread(&reg,sizeof(Producto),1,arch);
				int cant = 1;

					//muestro los datos de ese archivo
					/*
				printf("Detalles del producto:\n");
				printf("ID......: %d\n",reg.indice);
				printf("CODIGO..: %s\n",reg.barCode);
				printf("NOMBRE:.: %s\n",reg.nombre);
				printf("COSTO:..: $%.2f\n",reg.cUni);
				printf("STOCK:..: %d\n",reg.stock);
				printf("\n");
				//Obteniendo la informacion del archivo
					*/
	LinkedList_Insert(ticket,IDProducto,"4352",  "COCACOLA",2, 10.0, 20.0);
	IDProducto ++;
	LinkedList_Insert(ticket,IDProducto,"54353", "SABRITAS",1,  8.0,  8.0);
	IDProducto ++;
	LinkedList_Insert(ticket,IDProducto,"643634","PALETA",  5,  2.0,  10.0);
				Bool SUCCES = LinkedList_Insert(ticket,reg.indice,reg.barCode,reg.nombre,  cant,  reg.cUni,  reg.cUni);
				if (SUCCES)
				{
					int focus = 1;
					GeneraVentaLISTA(ticket,focus);
					LinkedList_Destroy(ticket);
				}
				else
				{
					printf("ERROR AL INGRESAR PRODUCTO\n");
				}
				//LinkedList_Insert(ticket,reg.indice,reg.barCode,reg.nombre,  cant,  reg.cUni,  reg.cUni*cant);
				fclose(arch);
				
			}
				
		}
		

	} while (v!=0);
	return 1;
}



#if 1
int main()
{
nuevaVenta();
	/*
	
	LinkedList* ticket = LinkedList_Create ();
	int IDProducto = 1;
	LinkedList_Insert(ticket,IDProducto,"4352",  "COCACOLA",2, 10.0, 20.0);
	IDProducto ++;
	LinkedList_Insert(ticket,IDProducto,"54353", "SABRITAS",1,  8.0,  8.0);
	IDProducto ++;
	LinkedList_Insert(ticket,IDProducto,"643634","PALETA",  5,  2.0,  10.0);
	IDProducto ++;
	int focus = 1;
	GeneraVentaLISTA(ticket,focus);
	//Liberando memoria
	LinkedList_Destroy(ticket);
	 */

	return 0;
	
}
#endif