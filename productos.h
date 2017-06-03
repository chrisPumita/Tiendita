#include <stdio.h>
#include <string.h>
#include "Bool.h"
#define TAM_MAX 50
#define TAM_BAR 20

/**
 * Esta estructura contiene la información de los productos
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
 * [Leen el producto de el archivo binario]
 * @param arch [Es el archivo binario]
 * @param reg  [Es la estructura tipo Producto]
 */
void leerProducto(FILE * arch, Producto* reg);

/**
 * [Ingresa el producto en el archivo binario]
 * @param arch [Es el archivo binario]
 * @param reg  [Es la estructura tipo Producto]
 */
void grabaProducto(FILE* arch, Producto* reg);

/**
 * [Crea la estructura Producto]
 * @param  indice   [Es el número del producto con respecto a los demás]
 * @param  nombre   [Nombre del producto]
 * @param  barra    [Es el número que se lee del código de barras]
 * @param  cantidad [Cantidad en inventario del producto]
 * @param  cUni     [Costo unitario del producto seleccionado]
 * @return          [Regresa una estructura tipo Producto]
 */
Producto creaProducto(int indice, char nombre[], char barCode[], int stock, float cUni);

/**
 * [Ingresa el producto en la consola]
 * @param  indice [description]
 * @return        [description]
 */
Producto ingresaDatosxConsola(int indice);

/**
 * [Muestra el inventario]
 */
void DesplegarStock();

/**
 * [Agrega un producto al inventario]
 * @param indice [Número del producto con respecto a los otros]
 */
void agregaProducto(int indice);

/**
 * [Muestra la información del producto]
 * @param index [Número del producto con respecto a los otros]
 */
void buscaProductoIndex(int index);

/**
 * [Busca un producto de acuerdo a su barcode]
 * @param  bar [Es el número del código de barra]
 * @return     [Regresa el index del producto]
 */
int buscaProductoBarCode(char bar[]);

/**
 * [Devuelve el último índice]
 * @return [Regresa el último índice]
 */
int buscaUltimo();

/**
 * [Modifica el producto seleccionado]
 */
void modificarRegistro();
 