#include <stdio.h>
#include <string.h>
#include "Bool.h"
#define TAM_MAX 50
#define TAM_BAR 20

/**
 * 
 */
 struct Producto_Type
 {
 	int indice;
 	char nombre[TAM_MAX];
 	char barCode[TAM_BAR];
 	int stock;
 	float cUni;
 };
 typedef struct Producto_Type Producto;

/**
 * [leerProducto description]
 * @param arch [description]
 * @param reg  [description]
 */
void leerProducto(FILE * arch, Producto* reg);

/**
 * [grabaProducto description]
 * @param arch [description]
 * @param reg  [description]
 */
void grabaProducto(FILE* arch, Producto* reg);

/**
 * [creaProducto description]
 * @param  indice  [description]
 * @param  nombre  [description]
 * @param  barCode [description]
 * @param  stock   [description]
 * @param  cUni    [description]
 * @return         [description]
 */
Producto creaProducto(int indice, char nombre[], char barCode[], int stock, float cUni);

/**
 * [ingresaDatosxConsola description]
 * @param  indice [description]
 * @return        [description]
 */
Producto ingresaDatosxConsola(int indice);

/**
 * [DesplegarStock description]
 */
void DesplegarStock();

/**
 * [agregaProducto description]
 * @param indice [description]
 */
void agregaProducto(int indice);

/**
 * [buscaProductoIndex description]
 * @param index [description]
 */
void buscaProductoIndex(int index);

/**
 * [buscaProductoBarCode description]
 * @param  bar [description]
 * @return     [description]
 */
int buscaProductoBarCode(char bar[]);

/**
 * [buscaUltimo description]
 * @return [description]
 */
int buscaUltimo();

/**
 * [modificarRegistro description]
 */
void modificarRegistro();
 