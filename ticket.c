#include <stdio.h>
#include <time.h>  
#include "lldblc.h"
#include "productos.h"
#define TAM_BARRA 20
#define clear() printf("\033[H\033[J") 
// Para limpiar pantalla

void GeneraTicket(LinkedList* this, int index)
{
	index = 1;
	clear();

	//FECHA HORA
	time_t rawtime;
	time (&rawtime);
	Node * it = LinkedList_Search(this,index);
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

	void agregaProducto(){
		char codeBar[TAM_BARRA];
		printf("Escriba codigo de barra:\n--> ");
		scanf("%s",codeBar);

		//busca en los productos
	}



int main()
{

	LinkedList* ticket = LinkedList_Create ();
	int IDProducto = 1;
	LinkedList_Insert(ticket,IDProducto,"4352",  "COCACOLA",2, 10.0, 20.0);
	IDProducto ++;
	LinkedList_Insert(ticket,IDProducto,"54353", "SABRITAS",1,  8.0,  8.0);
	IDProducto ++;
	LinkedList_Insert(ticket,IDProducto,"643634","PALETA",  5,  2.0,  10.0);
	IDProducto ++;
	int focus = 1;
	GeneraTicket(ticket,focus);
	//Liberando memoria
	LinkedList_Destroy(ticket);
	return 0;
	
}
