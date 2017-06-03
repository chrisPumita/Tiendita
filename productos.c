#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "productos.h"
#define TAM_MAX 50
#define TAM_BAR 20
#define FILE_NAME "lista-de-precios.dat"
#define clear() printf("\033[H\033[J") 

void leerProducto(FILE * arch, Producto* reg)
{
	fread(reg,sizeof(Producto),1,arch);
}

void grabaProducto(FILE* arch, Producto* reg)
{
	fwrite(reg,sizeof(Producto),1,arch);
}

/**
 * [DesplegarStock Esta funcion lee archivos txt, se ha eliminado porque se ha creado funciones que leen archivos binarios]
 */
/*
void DesplegarStock()
{
	FILE* arch = fopen(FILE_NAME,"r+b");
	int ID;
	char barCode[TAM_BAR];
	char nombre[TAM_MAX];
	float cUni;
	int stock;

	fscanf(arch,"%d %s %s %f %d",&ID,barCode,nombre,&cUni,&stock);
	printf("ID  | CODIGO |  N O M B R E    |   $   |  Stock |\n");
	while(!(feof(arch)!= '\0'))
	{
		printf("%d\t",ID);
		printf("%s\t",barCode);
		printf("%s\t",nombre);
		printf("%.2f\t",cUni);
		printf("%d\t",stock);
		printf("\n");

		fscanf(arch,"%d %s %s %f %d",&ID,barCode,nombre,&cUni,&stock);
	}
	fclose(arch);
}
 */

Producto creaProducto(int indice, char nombre[], char barCode[], int stock, float cUni)
{
	Producto x;
	x.indice = indice;
	strcpy(x.nombre, nombre);
	strcpy(x.barCode, barCode);
	x.stock = stock;
	x.cUni=cUni;
	return x;
}

Producto ingresaDatosxConsola(int indice)
{
	char nombre[TAM_MAX];
	char barCode[TAM_BAR];
	int stock;
	float cUni;

	printf("Ingrese nombre del producto: ->");
	scanf("%s",&nombre);

	printf("Ingrese Código de Barra: ->");
	scanf("%s",&barCode);	

	printf("Ingrese Stock: ->");
	scanf("%d",&stock);	


	printf("Ingrese Costo Unitario: ->");
	scanf("%f",&cUni);

	Producto x;
	x.indice = indice+1;
	strcpy(x.nombre, nombre);
	strcpy(x.barCode, barCode);
	x.stock = stock;
	x.cUni=cUni;
	return x;
}

void DesplegarStock()
{
	FILE* arch;
	Producto a;

	//Abrimos el archivo para lectura
	arch = fopen(FILE_NAME, "r+b");

	//La primera leida la hacemos fuera del while
	
	printf("ID| CODIGO    |    NOMBRE    |   $   |  Stock |\n");
	leerProducto(arch,&a);
	while(!feof(arch))
	{
		printf("%d  ",a.indice);
		printf("%s\t",a.barCode);
		printf("%s\t\t",a.nombre);
		printf("%.2f\t",a.cUni);
		printf("%d",a.stock);
		printf("\n");
		//leemos el sig registro del archivo
//		fread(&a,sizeof(Producto),1,arch);
		leerProducto(arch,&a);
	}
	fclose(arch);
}

void agregaProducto(int indice)
{
	FILE* arch=fopen(FILE_NAME,"r+b");

	//Ingresa los datos por consola
	Producto reg = ingresaDatosxConsola(indice++);

	//Posicion del puntero al final del archivo .dat
	fseek(arch,0,SEEK_END);
	fwrite(&reg,sizeof(Producto),1,arch);
	fclose(arch);
	/*
	
	FILE* arch=fopen(FILE_NAME,"r+b");
	Producto a;
	
	//Creando producto nuevo en el archivo
	//ID, Nombre, CodeBar, Stock, Coste Unitario
	
	a=creaProducto(5,"GalletaDEMO2","6454326",50,7.50);
	a=creaProducto(6,"Pastel","65446",10,13.50);
	fwrite(&a,sizeof(Producto),1,arch);
	fclose(arch);
	 */
}
 
 void buscaProductoIndex(int index)
 {
	FILE* arch=fopen(FILE_NAME,"r+b");
	int n = index;

	//Posiciono el puntero del archivo
	fseek(arch,n*sizeof(Producto),SEEK_SET);

	//con el puntero posicionado, leo el registro
	Producto reg;
	fread(&reg,sizeof(Producto),1,arch);

	//muestro los datos de ese archivo
	printf("Detalles del producto:\n");
	printf("ID......: %d\n",reg.indice);
	printf("CODIGO..: %s\n",reg.barCode);
	printf("NOMBRE:.: %s\n",reg.nombre);
	printf("COSTO:..: $%.2f\n",reg.cUni);
	printf("STOCK:..: %d\n",reg.stock);
	printf("\n");
	fclose(arch);
 }

  int buscaProductoBarCode(char bar[])
 {
	FILE* arch=fopen(FILE_NAME,"r+b");
	Producto aux;
	int n;
	int index = 0;
	Bool found = FALSE;

	// ->>>> BUSCANDO DATO
	// fread(reg,sizeof(Producto),1,arch);
	while(fread(&aux, sizeof(aux),1,arch)!=0 && strcmp(aux.barCode,bar)!=0)
	{
		if (strcmp(aux.barCode,bar)!=0)
		{
			found = TRUE;
		}
		index++;
	}
	clear();
	fclose(arch);
	printf("%d\n",index);
    if (found != TRUE)
	{
		printf("No existe producto: %s\n",bar);
		return 0;
	}
    else
    {
        printf("Producto encontrado:\n");
//		index = aux.indice;
		return index;
 	}
	// ->> END
 }

 int buscaUltimo()
 {
 	FILE* arch;
	Producto a;
	int i;
	//Abrimos el archivo para lectura
	arch = fopen(FILE_NAME, "r+b");
	leerProducto(arch,&a);
	while(!feof(arch))
	{
		i = a.indice;
		//leemos el sig registro del archivo
		leerProducto(arch,&a);
	}
	fclose(arch);
	if (i<0)
	{
		i = 1;
	}
	i++;
	return i;
 }

 void modificarRegistro()
 {
//Funcion para modificar un elemento especifico
	FILE* arch=fopen(FILE_NAME,"r+b");
	int n;
	printf("Ingrese el ID a modificar: ->");
	fflush(stdout);
	scanf("%d",&n);
	n--;
	printf("Mostrando inforacion del ID: %d\n",n);
	buscaProductoIndex(n);
	//ingreso los nuevos datos por consola
	Producto reg = ingresaDatosxConsola(n);

	//Posicion del indentificaro de posicion
	fseek(arch,n*sizeof(Producto),SEEK_SET);

	//Grabo el registro reescribiendo
	fwrite(&reg,sizeof(Producto),1,arch);
	fclose(arch); 	
 }
 
#if 0
int main(int argc, char const *argv[])
{
	
	DesplegarStock();
	//Muestra todo el inventario
	


	//Se pide al usuario el ID que vaya a ver
	int ID;
	printf("Ingrese el ID para ver información: ->");
	scanf("%d",&ID);
	buscaProductoIndex(ID-1);

	

	DesplegarStock();

	return 0;
}
#endif