#include <stdio.h>
#include <string.h>
#include "productos.h"
#include "Bool.h"

	Producto crearProducto(int, char);
int main(int argc, char const *argv[])
{
	FILE* arch;
	Producto a;

	//Abrimos el archivo para lectura
	arch = fopen("lista-de-precios.dat", "r+b");

	//La primera leida la hacemos fuera del while
	//fread(&a,sizeof(Producto),1,arch);
	printf("ID  | CODIGO |  NOMBRE |   $   |  Stock |\n");
	while(!feof(arch))
	{
		printf("%d-\t%s-\t%s%.2f\t%d\n",a.indice,a.barCode,a.nombre,a.cUni,a.stock);
		//leemos el sig registro del archivo
		fread(&a,sizeof(Producto),1,arch);
	}

	fclose(arch);
	return 0;
}