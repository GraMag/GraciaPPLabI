/*
 * servicio.h
 *
 *  Created on: 15 may. 2020
 *      Author: reyna
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
	int id;
	char descripcion[25];
	float precio;
}eServicio;

#endif /* SERVICIO_H_ */

void listarServicio(eServicio serv[], int tam);
int cargarDescServicio(char descripcion[], int id, eServicio serv[], int tam);
