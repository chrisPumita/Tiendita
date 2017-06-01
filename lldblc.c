#include <stdio.h>
#include "lldblc.h"

 	/* Funciones de la Listas */
 LinkedList* LinkedList_Create ()
 {
 	LinkedList* n = (LinkedList *)malloc (sizeof (LinkedList));
	 if (n) 
	 {
		 n->first = NULL;
		 n->last = NULL;
	 }
	 return n;
 }

 void LinkedList_Destroy (LinkedList* this)
 {
	 // devuelve los nodos existentes antes de destruir al objeto lista
	 while (this->first != NULL) 
	 {
		 Node* tmp = this->first->siguiente;
		 deleteNode (this->first);
		 this->first = tmp;
	 }
	 free (this);
 // devuelve la memoria asignada a la lista
 }


 Bool LinkedList_Insert (LinkedList* this,int indice, char* barra, char* nombre, int cantidad, double cUni, double cTotal)
 {

	 Node* n = newNode (indice, barra, nombre, cantidad, cUni, cTotal);
	 if (!n) { return FALSE; }
	 // si es NULL devuelve FALSE
	 // ya hay nodos en la lista, es decir, la lista NO está vacía
	 if (this->first != NULL) 
	 {
		 this->last->siguiente = n;
		 this->last = n;
	 }
	 // la lista está vacía
	 else 
	 {
	 	this->first = n;
	 	this->last = n;
	 }
	 return TRUE;
 }


 Bool LinkedList_FindIf (LinkedList* this, int val)
 {
	 Node* it = this->first;
	 while (it != NULL) 
	 {
		 if (it->indice == val) { return TRUE; }
		 it = it->siguiente;
	 }
	 return FALSE;
 }

Node* LinkedList_Search(LinkedList* this, int val)
{
 	Node * it = this -> first;
 	//Devuelve la direccion del primer nodo
 	while(it != NULL)
 	{
 		if (it->indice == val)
 		{
 			//Encontró el valor buscado
 			return it;
 		}
 		it = it -> siguiente;
 		//Se pasa al siguiente nodo
 	}
 	return NULL; // NO Encontro el elemento, por lo tanto es NULL;
 }

void GeneraVenta(LinkedList* this, int index)
{

	index = 1;
	Node * it = LinkedList_Search(this,index);
	//Devuelve la direccion del primer nodo
	double totPago = 0.0;
	int noProductos = 0;
	//Comienza a generar el ticket de venta
	printf("TICKET DE VENTA\n");
	printf("31 de Mayo de 2017\n");
	printf("Codigo\tNombre\tCant\t$U\t$T\n");
	printf("+--------------------------+\n");
	while(it != NULL)
	{
		printf("%d  ",it->indice);
		printf("%s ",it->barra);
		printf("%s\t",it->nombre);
		printf("%d  ",it->cantidad );
		printf("$%.2f\t",it->cUni);
		printf("$%.2f\n",it->cTotal);
		totPago += it->cTotal;
		noProductos += it->cantidad;
		it = it -> siguiente;
	}
	printf("+--------------------------+\n");
	printf("\tProductos adquiridos: %d\n",noProductos);
	printf("\t\tTotal: $%.2f\n",totPago);
}