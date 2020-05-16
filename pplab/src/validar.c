#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validar.h"

float inputFloat(char message[20], int min, int max)
{
	float num;

	printf("Ingrese %s: ", message);
	scanf("%f", &num);

	while (num < min || num > max)
	{
		printf("ERROR: %s fuera de rango. Ingrese %s nuevamente: \n", message, message);
		scanf("%f", &num);
	}
	return num;
}

int inputInt(char message[20], int min, int max)
{
	int num;

	printf("Ingrese %s: ", message);
	scanf("%d", &num);

	while (num < min || num > max)
	{
		printf("ERROR: %s fuera de rango. Ingrese %s nuevamente: ", message, message);
		scanf("%d", &num);
	}
	return num;
}
