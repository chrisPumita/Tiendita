
#define TAM_TEXT 100
#define TAM_BARRA 20


#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

enum {FALSE = 0, TRUE = !0};
typedef unsigned int Bool;

/*--------- Estructura del NODO ------------*/
 struct Node_Type
 {
 	int indice;
 	char barra[TAM_BARRA];
 	char nombre[TAM_TEXT];
	int cantidad;
	double cUni;
	double cTotal;
	

 // datos
 	struct Node_Type* siguiente;
 // apuntador al siguiente nodo
 };
 typedef struct Node_Type Node;

 /*--------- Estructura del LA LISTA ------------*/

/*--------- Estructura de la lista Enlazada ------------*/
 struct LinkedList_Type
 {
	Node* first;
 // apuntador al primer nodo
 	Node* last;
 // apuntador al último nodo
 };
 typedef struct LinkedList_Type LinkedList;

/*--------- Estructura de la lista Enlazada ------------*/


//-----------------FUNCIONES PROVADAS--------------*/


 static Node* newNode (int indice, char* barra, char* nombre, int cantidad, double cUni, double cTotal)
 {
 	Node* n = (Node *)malloc (sizeof (Node));
 	if (n) {
 		//Creando el nodo en memoria
 		n-> indice = indice;
 		strcpy (n->barra, barra);
 		strcpy (n->nombre, nombre);
		n-> cantidad = cantidad;
		n-> cUni = cUni;
		n-> cTotal = cTotal;
		n->siguiente = NULL;
	 }
 	return n;
 }

 static void deleteNode (Node* n)
 {
	 if (n) {
		 free (n);
	 }
 }
/*--------- Estructura del nodo ------------*/
	/* Funciones de la Listas */

LinkedList* LinkedList_Create ();

void LinkedList_Destroy (LinkedList* this);

Bool LinkedList_Insert (LinkedList* this,int indice, char* barra, char* nombre, int cantidad, double cUni,double cTotal);

Bool LinkedList_FindIf (LinkedList* this, int val);
	
Node* LinkedList_Search(LinkedList* this, int val);

void GeneraVenta(LinkedList* this, int index);

