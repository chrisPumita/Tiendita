#include <stdio.h>
#include <string.h>
#include "productos.h"
#include "Bool.h"
#define TAM_MAX 50
#define TAM_BAR 20

void leerProducto(FILE * arch, Producto* reg)
{
	fread(reg,sizeof(Producto),1,arch);
}

void grabaProdudcto(FILE* arch, Producto* reg)
{
	fwrite(reg,sizeof(Producto),1,arch);
}

/*

DesplegasStock()
{
}
 */


int main(int argc, char const *argv[])
{
	
	/*
	FILE* arch;
	Producto a;

	//Abrimos el archivo para lectura
	arch = fopen("lista-de-precios.dat", "r+b");

	//La primera leida la hacemos fuera del while
	printf("ID\t| CODIGO |  NOMBRE |   $   |  Stock |\n");
	leerProducto(arch,&a);
	while(!feof(arch))
	{
		printf("%d\t",a.indice);
		printf("%s\t",a.barCode);
		printf("%s\t",a.nombre);
		printf("%.2f\t",a.cUni);
		printf("%d\t",a.stock);
		printf("\n");
		//leemos el sig registro del archivo
//		fread(&a,sizeof(Producto),1,arch);
		leerProducto(arch,&a);
	}

	fclose(arch);
	 */

	FILE* arch = fopen("lista-de-precios.dat","r+");
	int ID;
	char barCode[TAM_BAR];
	char nombre[TAM_MAX];
	float cUni;
	int stock;

	fscanf(arch,"%d %s %s %f %d",&ID,barCode,nombre,&cUni,&stock);
	while(!feof(arch)!= '\0')
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

	return 0;
}