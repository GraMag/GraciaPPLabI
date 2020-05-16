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
#include "menu.h"
#include "validar.h"

#define TAMMC 5 // TAManio Marca Color
#define TAMS 4 // TAManio Servicio
#define TAMA 5 // TAManio Auto
#define TAMT 5 // TAM Trabajo

int main(void) {

	char continuar = 's';
	eMarca marca[TAMMC] = {{1000, "Renault"}, {1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};
	eColor color[TAMMC] = {{5000, "Negro"}, {5001, "Blanco"}, {5002, "Gris"}, {5003, "Rojo"}, {5004, "Azul"}};
	eServicio servicio[TAMS] = {{20000, "Lavado", 250}, {20001, "Pulido", 300}, {20002, "Encerado", 400}, {20003, "Completo", 600}};
	eAuto tutu[TAMA];
	eTrabajo trabajo[TAMT];
	int readyAuto = 0;

	setbuf(stdout, NULL);

	initAuto(tutu, TAMA);
	initTrabajo(trabajo, TAMT);
	printf("*** BIENVENIDO ***\n\n");

	do
		{
			system("cls");
			fflush(stdin);

			switch(menu())
			{
				case 'a':
					if (altaAuto(tutu, TAMA, marca, TAMMC, color, TAMMC) == 0)
					{
						readyAuto = 1;
					}
					break;
				case 'b':
					if (!(noAuto(readyAuto)))
					{
					modificarAuto(tutu, TAMA, color, TAMMC);
					}
					break;
				case 'c':
					if (!(noAuto(readyAuto)))
					{
					bajaAuto(tutu, TAMA);
					}
					break;
				case 'd':
					if (!(noAuto(readyAuto)))
					{
					listarAutos(tutu, TAMA, color, TAMMC, marca, TAMMC); //FALTA ORDENAMIENTO
					}
					break;
				case 'e':
					if (!(noAuto(readyAuto)))
					{
					listarMarca(marca, TAMMC);
					}
					break;
				case 'f':
					if (!(noAuto(readyAuto)))
					{
					listarColor(color, TAMMC);
					}
					break;
				case 'g':
					if (!(noAuto(readyAuto)))
					{
					listarServicio(servicio, TAMS);
					}
					break;
				case 'h':
					if (!(noAuto(readyAuto)))
					{
					altaTrabajo(trabajo, TAMT, servicio, TAMS);
					}
					break;
				case 'i':
					if (!(noAuto(readyAuto)))
					{
					listarTrabajos(trabajo,TAMS, servicio, TAMS);
					}
					break;
				default:
					printf("Opcion invalida\n");
					break;
			}

			system("pause");
			fflush(stdin);
		}while(continuar == 's');


	return EXIT_SUCCESS;
}
