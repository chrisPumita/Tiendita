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

#include <stdio.h>
#include <string.h>
#include "productos.h"
#include "Bool.h"
#define TAM_MAX 50
#define TAM_BAR 20

void leerProducto(FILE * arch, Producto* reg);

void grabaProdudcto(FILE* arch, Producto* reg);

void DesplegasStock();