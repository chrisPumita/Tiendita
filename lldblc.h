
#define TAM_TEXT 100
#define TAM_BARRA 20


#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Bool.h"

/*--------- Estructura del NODO ------------*/
 struct Node_Type
 {
 	int indice;
 	char barra[TAM_BARRA];
 	char nombre[TAM_TEXT];
	int cantidad;
	float cUni;
	float cTotal;
	
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

/**
 * [newNode  description]
 * @param  indice   [description]
 * @param  barra    [description]
 * @param  nombre   [description]
 * @param  cantidad [description]
 * @param  cUni     [description]
 * @param  cTotal   [description]
 * @return          [description]
 */
 static Node* newNode (int indice, char* barra, char* nombre, int cantidad, float cUni, float cTotal)
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

/**
 * [deleteNode  description]
 * @param n [description]
 */
 static void deleteNode (Node* n)
 {
	 if (n) {
		 free (n);
	 }
 }
/*--------- Estructura del nodo ------------*/
	/* Funciones de la Listas */

/**
 * [LinkedList_Create  description]
 * @return [description]
 */
LinkedList* LinkedList_Create ();

/**
 * [LinkedList_Destroy  description]
 * @param this [description]
 */

/**
 * [LinkedList_Destroy  description]
 * @param this [description]
 */
void LinkedList_Destroy (LinkedList* this);

/**
 * [LinkedList_Insert  description]
 * @param  this     [description]
 * @param  indice   [description]
 * @param  barra    [description]
 * @param  nombre   [description]
 * @param  cantidad [description]
 * @param  cUni     [description]
 * @param  cTotal   [description]
 * @return          [description]
 */

/**
 * [LinkedList_Insert  description]
 * @param  this     [description]
 * @param  indice   [description]
 * @param  barra    [description]
 * @param  nombre   [description]
 * @param  cantidad [description]
 * @param  cUni     [description]
 * @param  cTotal   [description]
 * @return          [description]
 */
Bool LinkedList_Insert (LinkedList* this,int indice, char* barra, char* nombre, int cantidad, float cUni,float cTotal);

/**
 * [LinkedList_FindIf  description]
 * @param  this [description]
 * @param  val  [description]
 * @return      [description]
 */
Bool LinkedList_FindIf (LinkedList* this, int val);
	
/**
 * [LinkedList_Search description]
 * @param  this [description]
 * @param  val  [description]
 * @return      [description]
 */
Node* LinkedList_Search(LinkedList* this, int val);
