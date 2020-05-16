#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"


void listarMarca(eMarca mar[], int tam)
{
	system("cls");
	printf(" ID     MARCA\n");
	for (int i = 0; i < tam; i++)
		{
		 printf("%d   %10s\n", mar[i].id, mar[i].descripcion);
		}
}

int cargarDescMarca(char descripcion[], int id, eMarca marca[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		if(marca[i].id == id)
		{
			strcpy(descripcion, marca[i].descripcion);
			return 1;
		}
	}
	return 0;
}
