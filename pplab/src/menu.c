#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

char menu()
{
	char opcion;
	printf("Seleccione una opcion: \n\n");
	printf( "A.- Alta auto\n"
			"B.- Modificar auto\n" // (Ingresar id, con submenu de color y modelo
			"C.- Baja auto\n" //  (id)
			"D.- Listar autos\n" //  (todas segun marca y patente)
			"E.- Listar marcas\n"
			"F.- Listar colores\n"
			"G.- Listar servicios\n"
			"H.- Alta trabajo\n" //  (elegir notebook, y servicio
			"I.- Listar trabajo\n\n");
	fflush(stdin);
	scanf(" %c", &opcion);
	opcion = tolower(opcion);
	return opcion;
}

int modifMenu()
{
	int num;
	printf("Que atributo desea modificar? \n"
				"1.- Color"
				"2.- Modelo");
	num = inputInt("atributo", 1, 2);
	return num;
}
