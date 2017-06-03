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
		printf("\E[37;41m\t    OCXO    \E[00m\tVENTA DE MOSTRADOR\n");
		printf("\E[37;41;1;33m\t████████████\E[00m\n");
		printf("\n");
		
		printf("| CODIGO   |  CANT  |     NOMBRE     |   $U   |  $TOTAL |\n");
		printf("+--------------------------+\n");
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
		printf("+--------------------------+\n");
		printf("   Productos agregados: %d\n",noProductos);
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
	printf("RFC AD010120QGMS\n");
	printf("\tTICKET DE VENTA\n");
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
	//float cambio(float precio, float pago)
	printf("\t\t  Total:...$%.2f\n",totPago);
	printf("\t\tSu Pago:...$%.2f\n",pago);
	printf("\t\t Cambio:...$%.2f\n",cambio(totPago,pago));
	printf("\n");
	printf("GRACIAS POR SU COMPRA\n");
	printf("      -------o0o-------\n");
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

float cambio(float precio, float pago)
{ 	
	/*
	float pago, cambio; 
	Bool banpag = FALSE;  
	while(!banpag)
	{ 	 	
	printf("\nEl total a pagar es %f.2", precio); 	
	printf("\nIngrese el pago: "); 	
	scanf("%f",pago); 	 	
	if(total <= pago){ 		
	cambio = cambio(total, pago); 		
	banpag = TRUE; 	} 	
	else{ 		clear(); 		
	printf("\nEl pago es menor al total, intente de nuevo:"); 	
	} 
	} 
	printf("\nLa transaccion fue exitosa\n");
	 */
	return pago - precio; 
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
		printf("Escriba código de barra:\n-->");
		scanf("%s",codeBar);
		int tamCodigo = strlen(codeBar);

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
				break;
				case 2:
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
			if(IDProducto!=0)
			{
				
				FILE* arch=fopen(FILE_NAME,"r+b");
				//Posiciono el puntero del archivo
				fseek(arch,IDProducto*sizeof(Producto),SEEK_SET);

				//con el puntero posicionado, leo el registro
				Producto reg;
				fread(&reg,sizeof(Producto),1,arch);
				int cant = 1;

				//Obteniendo la informacion del archivo
				 
				Bool SUCCES = TRUE;
				//Bool SUCCES = 
				LinkedList_Insert(ticket,IDProducto,reg.barCode,reg.nombre,  cant,  reg.cUni,  reg.cUni);
				if (SUCCES)
				{
					muestraVenta(ticket);
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