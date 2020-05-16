#include <stdio.h>
#include <stdlib.h>
#include "color.h"

void listarColor(eColor color[], int tam)
{
	system("cls");
	printf(" ID     Color\n");
	for (int i = 0; i < tam; i++)
	{
		printf("%d   %6s\n", color[i].id, color[i].nombreColor);
	}
}

int cargarDescColor(char descripcion[], int id, eColor color[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		if(color[i].id == id)
		{
			strcpy(descripcion, color[i].nombreColor);
			 return 1;
		}
	}

	return -1;
}
