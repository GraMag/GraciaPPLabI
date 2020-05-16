#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auto.h"
#include "color.h"
#include "fecha.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include "validar.h"


void initTrabajo (eTrabajo traba[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		traba[i].isEmpty = 1;
	}
}

int buscarLibreTraba(eTrabajo traba[], int tam)
{
	for(int i = 0; i < tam; i++) {
		if(traba[i].isEmpty == 1)
		{
			return i;
		}
	}

	printf("No hay lugares libres");
	return -1;
}

int altaTrabajo(eTrabajo traba[], int tam, eServicio serv[], int tamS)
{
	eTrabajo auxTrab;
	int index = buscarLibreTraba(traba, tam);

	if(index == -1)
	{
		return -1;
	}
	else
	{
		auxTrab.id = index;
		printf("Ingrese patente:\n");
		scanf("%d", &auxTrab.patente);
		listarServicio(serv, tamS);
		auxTrab.idServicio = inputInt("servicio", 20000, 20003);
		printf("Ingrese fecha: DD/MM/AAAA");
		scanf("%d/%d/%d", &auxTrab.fecha.dia, &auxTrab.fecha.mes, &auxTrab.fecha.anio);

		auxTrab.isEmpty = 0;

		traba[index] = auxTrab;
	}
	return 0;
}

void mostrarTrabajo(eTrabajo traba, eServicio serv[], int tamS)
{
	char desServicio [20];
	cargarDescServicio(desServicio, traba.idServicio, serv, tamS);


	printf(	"| %04d          %d           %10s               %0d/%0d/%d     \n", traba.id, traba.patente, desServicio, traba.fecha.dia, traba.fecha.mes, traba.fecha.anio);

}

void listarTrabajos(eTrabajo traba[], int tam,  eServicio serv[], int tamS)
{
	int ok = 0;
	printf(	"#======#======================#=================#=============#\n"
			"|  ID  |        PATENTE       |     SERVICIO    |    FECHA    |\n"
			"#======#======================#=================#=============#\n");
	for (int i = 0; i < tam; i++)
	{
		if(traba[i].isEmpty == 0)
		{
			mostrarTrabajo(traba[i], serv, tamS);
			ok = 1;
		}
	}
	printf( "#======#======================#=================#=============#\n");
	if (ok == 0)
	{
		printf("No hay datos para mostrar");
	}
}
