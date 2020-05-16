#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void listarServicio(eServicio serv[], int tam)
{
	system("cls");
	printf(" ID      SERVICIO   PRECIO\n");
	for (int i = 0; i < tam; i++)
	{
		printf("%d   %10s   $%.2f\n", serv[i].id, serv[i].descripcion, serv[i].precio);
	}
}


int cargarDescServicio(char descripcion[], int id, eServicio serv[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		if(serv[i].id == id)
		{
			strcpy(descripcion, serv[i].descripcion);
			 return 1;
		}
	}

	return -1;
}
