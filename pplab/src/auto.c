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

void initAuto (eAuto tutu[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		tutu[i].isEmpty = 1;
	}
}

int noAuto (int ready)
{
	if(!(ready))
	{
		printf("Aun no se han ingresado autos.\n\n");
		return -1;
	}
	return 0;
}

int buscarLibreAuto(eAuto tutu[], int tam)
{
	for(int i = 0; i < tam; i++) {
		if(tutu[i].isEmpty == 1)
		{
			return i;
		}
	}

	printf("Lista completa");
	return -1;
}

int buscarAuto(int patente, eAuto tutu[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		if(tutu[i].patente == patente && tutu[i].isEmpty == 0)
		{
			return i;
			break;
		}
	}
	return -1;
}

int altaAuto(eAuto tutu[], int tam, eMarca marca[], int tamM, eColor color[], int tamC)
{
	eAuto auxAuto;
	int index = buscarLibreAuto(tutu, tam);

	if(index == -1)
	{
		return -1;
	}
	else
	{
		auxAuto.id = index;
		printf("Ingrese patente:\n");
		scanf("%d", &auxAuto.patente);
		listarMarca(marca, tamM);
		auxAuto.idMarca = inputInt("marca", 1000, 1004);
		listarColor(color, tamC);
		auxAuto.idColor = inputInt("color", 5000, 5004);
		auxAuto.modelo = inputInt("modelo", 1980, 2020);
		auxAuto.isEmpty = 0;

		tutu[index] = auxAuto;
	}
	return 0;
}

void bajaAuto(eAuto tutu[], int tam)
{
	int patente;
	int index;
	char seguir;

	system("cls");

	printf("Ingrese patente: ");
	scanf("%d", &patente);

	index = buscarAuto(patente, tutu, tam);
	if(index == -1)
	{
		printf("No existe esa patente.\n\n");
	}
	else
	{
		printf("Patente encontrada:\n");
		//mostrarEmpleado(auto[existe],sec, tamSec);

		printf("Esta seguro que desea eliminar al auto patente %d? S/N \n", patente);
		fflush(stdin);
		scanf("%c", &seguir);
		seguir = tolower(seguir);
		if(seguir == 's')
		{
			tutu[index].isEmpty = 1;
			printf("Auto eliminado.\n");
		}
		else
		{
			printf("No se realizaron cambios en el registro.\n");
		}
	}
}

void modificarAuto(eAuto tutu[], int tam, eColor color[], int tamC)
{
	int patente;
	int index;
	int opcion;

	system("cls");

	printf("Ingrese patente: ");
	scanf("%d", &patente);

	index = buscarAuto(patente, tutu, tam);
	if(index == -1)
	{
		printf("No existe esa patente.\n\n");
	}
	else
	{
		printf("Patente encontrada:\n");

		opcion = modifMenu();
		if(opcion == 1)
		{
			listarColor(color, tamC);
			printf("Ingrese nuevo color: \n");
			scanf("%d", &tutu[index].idColor);
		}
		else
		{
			printf("Ingrese nuevo modelo: \n");
			scanf("%d", &tutu[index].modelo);
		}
	}
}

void mostrarAuto(eAuto tutu, eColor color[], int tamC, eMarca marca[], int tamM)
{
	char desColor [20];
	char desMarca [20];
	cargarDescColor(desColor, tutu.idColor, color, tamC);
	cargarDescMarca(desMarca, tutu.idMarca, marca, tamM);
	printf(	"#======#======================#=================#=============#==========#\n"
			"|  ID  |        PATENTE       |      MARCA      |    COLOR    |  MODELO  |\n"
			"#======#======================#=================#=============#==========#\n");
	printf(	"| %04d          %d           %10s               %10s             %d\n", tutu.id, tutu.patente, desMarca, desColor, tutu.modelo);
	printf( "#======#======================#=================#=============#==========#\n");
}

void listarAutos(eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM)
{
	int ok = 0;
	for (int i = 0; i < tam; i++)
	{
		if(tutu[i].isEmpty == 0)
		{
			mostrarAuto(tutu[i], color, tamC, marca, tamM);
			ok = 1;
		}
	}
	if (ok == 0)
	{
		printf("No hay datos para mostrar");
	}
}
