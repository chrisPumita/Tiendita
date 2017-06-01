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
 	double cUni;
 };
 typedef struct Producto_Type Producto;


void leerProducto(FILE * arch, Producto* reg);

void grabaProducto(FILE* arch, Producto* reg);

void DesplegarStock();