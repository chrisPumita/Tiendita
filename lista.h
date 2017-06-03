
#define TAM_TEXT 100
#define TAM_BARRA 20


#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Bool.h"

/*--------- Estructura del NODO ------------*/
/**
* [Es el nodo que contiene la información del producto]
* @indice    [Es el número del producto con respecto a los demás]
* @barra     [Es el número que se lee del código de barras]
* @nombre    [Nombre del producto]
* @cantidad  [Cantidad en inventario del producto]
* @cUni      [Costo unitario del producto seleccionado]
* @cTotal    [Costo total]
* @siguiente [Es la dirección del siguiente nodo]
**/
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
 
 /**
 * [Contiene los apuntadores a los nodos contiguos]
 * @first [Es la dirección del primer nodo]
 * @last  [Es la dirección del último nodo]
 **/
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
 * [Crea un nuevo nodo y le agrega la información]
 * @param  indice   [Es el número del producto con respecto a los demás]
 * @param  barra    [Es el número que se lee del código de barras]
 * @param  nombre   [Nombre del producto]
 * @param  cantidad [Cantidad en inventario del producto]
 * @param  cUni     [Costo unitario del producto seleccionado]
 * @param  cTotal   [Costo total]
 * @return          [Regresa la dirección del nodo]
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
 * [Borra el nodo]
 * @param n [Es la dirección del nodo a borrar]
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
 * [Crea una lista enlazada]
 * @return [Regresa la dirección de la lista enlazada creada]
 */
LinkedList* LinkedList_Create ();

/**
 * [Destruye la lista enlazada]
 * @param this [Es la dirección de la lista enlazada a destruir]
 */
void LinkedList_Destroy (LinkedList* this);

/**
 * [LinkedList_Remove Remueve el ultimo elemento de la lista]
 * @param this [Es la direcion de la lista]
 */
 void LinkedList_Remove(LinkedList* this);
/**
 * [Inserta un nodo en la lista enlazada]
 * @param  this     [Es la dirección de la lista enlazada]
 * @param  indice   [Es el número del producto con respecto a los demás]
 * @param  barra    [Es el número que se lee del código de barras]
 * @param  nombre   [Nombre del producto]
 * @param  cantidad [Cantidad en inventario del producto]
 * @param  cUni     [Costo unitario del producto seleccionado]
 * @param  cTotal   [Costo total]
 * @return          [Determina si la operación fue exitosa]
 */
Bool LinkedList_Insert (LinkedList* this,int indice, char* barra, char* nombre, int cantidad, float cUni,float cTotal);

/**
 * [Busca en la lista enlazada un valor]
 * @param  this [Es la dirección de la lista enlazada a manejar]
 * @param  val  [Es el valor que se busca en la lista enlazada]
 * @return      [Determina si se encontró o no el valor]
 */
Bool LinkedList_FindIf (LinkedList* this, int val);
	
/**
 * [Busca en la lista enlazada un valor y regresa su dirección]
 * @param  this [Es la dirección de la lista enlazada a manejar]
 * @param  val  [Es el valor que se busca en la lista enlazada]
 * @return      [Regresa la dirección del nodo en el cual se encuentra val]
 */
Node* LinkedList_Search(LinkedList* this, int val);
