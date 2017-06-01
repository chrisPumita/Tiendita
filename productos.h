 #define TAM_MAX 50
#define TAM_BAR 20
 struct Producto_Type
 {
 	int indice;
 	char nombre[TAM_MAX];
 	char BarCode[TAM_BAR];
 	int stock;
 	double cUni;
 };
 typedef struct Producto_Type Producto;

