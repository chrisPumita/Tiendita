#include <stdio.h>
#include <string.h>
#define TAM_MAX 50
#define TAM_BAR 20

 struct Producto_Type
 {
 	int indice;
 	char nombre[TAM_MAX];
 	char barCode[TAM_BAR];
 	int stock;
 	float cUni;
 };
 typedef struct Producto_Type Producto;


void leerProducto(FILE * arch, Producto* reg);

void grabaProducto(FILE* arch, Producto* reg);

Producto creaProducto(int indice, char nombre[], char barCode[], int stock, float cUni);

Producto ingresaDatosxConsola(int indice);

void DesplegarStock();

void agregaProducto(int indice);
 
void buscaProductoIndex(int index);

int buscaUltimo();

void modificarRegistro();
 