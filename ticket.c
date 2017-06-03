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
		printf("\n");
		printf("\E[37;41;1;33m\t████████████\E[00m\n");
		printf("\E[37;41m\t    OTZO    \E[00m\tVENTA DE MOSTRADOR\n");
		printf("\E[37;41;1;33m\t████████████\E[00m\n");
		printf("\n");
		
		printf("| CODIGO   |  CANT  |     NOMBRE     |   $U   |  $TOTAL |\n");
		printf("+-------------------------------------------------------------+\n");
		while(it != NULL)
		{
			printf("%s\t\t",it->barra);
			printf("%d     ",it->cantidad );
			printf("%s\t\t",it->nombre);
			printf("$%.2f\t",it->cUni);
			printf("$%.2f\n",it->cTotal);
			totPago += it->cTotal;
			noProductos += it->cantidad;
			it = it -> siguiente;
		}
		printf("+-------------------------------------------------------------+\n");
		printf("    Productos agregados: %d",noProductos);
		printf("\t\tTotal: $%.2f\n",totPago);	

}

void GeneraTicket(LinkedList* this, float pago)
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
	printf("\E[37;41m\t  OTZO  \E[00m\n");
	printf("\E[37;41;1;33m\t████████\E[00m\n");
	printf("\n");
	printf(" Av. de seven eleven\n");
	printf("   RFC AD010120QGMS\n");
	printf("    TICKET DE VENTA\n");
	printf("%s\n",ctime (&rawtime));
	printf("Cant  Nombre\t$U\t$T\n");
	printf("+-----------------------------+\n");
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
	printf("+-----------------------------+\n");
	printf("Productos adquiridos: %d\n",noProductos);
	//float cambio(float precio, float pago)
	printf("\t  Total:...$%.2f\n",totPago);
	printf("\tSu Pago:...$%.2f\n",pago);
	//float cambio(float precio, float pago)
	printf("\t Cambio:...$%.2f\n",cambio(totPago,pago));
	printf("\n");
	printf("    GRACIAS POR SU COMPRA\n");
	printf("     -------o0o-------\n\n\n");
}

Bool agregaProductoTicket(LinkedList* ticket, char codigoBarra[]){
	
	int n = buscaProductoBarCode(codigoBarra);
	//busca en los productos

	//Recupera datos
	FILE* arch=fopen(FILE_NAME,"r+b");

	//Posiciono el puntero del archivo
	fseek(arch,n*sizeof(Producto),SEEK_SET);

	//con el puntero posicionado, leo el registro
	Producto reg;
	fread(&reg,sizeof(Producto),1,arch);
	fclose(arch);

	//recupera la informacion
	int cant = 1; //Esta cambiará
	
	/*Buscar el producto en la lista si lo encunetra */
	Bool nodoFound = LinkedList_FindIf(ticket,n);
	if (nodoFound)
	{
		Node* nodo = LinkedList_Search(ticket,n);
		nodo->cantidad++;
		nodo->cTotal = nodo->cUni*nodo->cantidad;
		return TRUE;
	}else
	{
		Bool value = LinkedList_Insert(ticket,n,reg.barCode,reg.nombre,cant, reg.cUni,cant*reg.cUni);
		return TRUE;
	}

}

float cambio(float total, float pago)
{ 	
	return pago-total;
}

int nuevaVenta()
{
	int v = 1;
	char codeBar[TAM_BARRA];
	LinkedList* ticket = LinkedList_Create ();
	clear();
	do
	{
		printf("\n\n");
		printf("NUEVA VENTA:\n");
		printf("+------------------+-----------------+----------------+\n"); //Segundo Menú
		printf("|  Quitar Producto | Proceder a Pago | Cancelar Venta |\n");
		printf("|        [1]       |      [2]        |      [3]       |\n");
		printf("+---------------+------------------+------------------+\n");
		printf("Escriba la opcion o el código de barra del producto que se quiere agregar:\n-->");
		scanf("%s",codeBar);
		int tamCodigo = strlen(codeBar);
		clear();
		//Seleccion de la opcion en el menu
		if (tamCodigo == 1)
		{
			/* Eligio opc que es de un caracter*/
			char i = codeBar[0];
			int opc = i - 0x30;
			//Lo convierto a entero
			switch (opc)
			{	
				case 1:
					printf("QUITAR PRODUCTO\n");
					//f(x) remueve Nodo
					LinkedList_Remove(ticket);
					muestraVenta(ticket);
				break;
				case 2:
					clear();
					printf("Proceder a pago\nIngrese cantidad su pago:\n-->");
					float tuPago;
					scanf("%f",&tuPago);

					//Pedir la cantidad de pago 
					//Ejemplo si son 59 y paga con billete de 100
					//Mostrar el ticket
					//GeneraTicket(LinkedList* this, float pago, float vuelto)

					GeneraTicket(ticket,tuPago);
					return 1;
				break;
				case 3:
				//Se regresa al menú principal
					return 0;
				break;
			}
		}
		else
		{
			/* Ingreso un codigo grande que hay que buscar y agregar*/
			int IDProducto = buscaProductoBarCode(codeBar);
			if(IDProducto>0)
			{
        		//printf("Producto encontrado:\n");
				FILE* arch=fopen(FILE_NAME,"r+b");
				//Posiciono el puntero del archivo
				fseek(arch,IDProducto*sizeof(Producto),SEEK_SET);

				//con el puntero posicionado, leo el registro
				Producto reg;
				fread(&reg,sizeof(Producto),1,arch);
				int cant = 1;

				//Obteniendo la informacion del archivo
				 
				Bool SUCCES = agregaProductoTicket(ticket,codeBar);
				fclose(arch);
				//Bool SUCCES = LinkedList_Insert(ticket,IDProducto,reg.barCode,reg.nombre,  cant,  reg.cUni,  reg.cUni);
				if (SUCCES)
				{
					muestraVenta(ticket);
				}
				else
				{
					printf("ERROR AL INGRESAR PRODUCTO\n");
				}
				//LinkedList_Insert(ticket,reg.indice,reg.barCode,reg.nombre,  cant,  reg.cUni,  reg.cUni*cant);
			}
			else
			{
				printf("NO EXISTE PRODUCTO\n");
				muestraVenta(ticket);
			}
				
		}		

	} while (v!=0);
	LinkedList_Destroy(ticket);
	return 1;
}



#if 0
int main()
{
nuevaVenta();
	return 0;
	
}
#endif